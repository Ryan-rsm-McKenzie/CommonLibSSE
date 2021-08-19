#pragma once

#include "RE/A/ActiveEffect.h"
#include "RE/B/BGSRefAlias.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/EffectSetting.h"
#include "RE/F/FunctionArguments.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TypeTraits.h"
#include "RE/V/VirtualMachine.h"

#include "SKSE/API.h"
#include "SKSE/Impl/RegistrationTraits.h"
#include "SKSE/Interfaces.h"
#include "SKSE/Logger.h"

namespace SKSE
{
	namespace Impl
	{
		class RegistrationMapUniqueBase
		{
		public:
			using Key = std::pair<RE::FormID, bool>;
			using Handles = std::pair<RE::FormID, RE::VMHandle>;

			RegistrationMapUniqueBase() = delete;
			RegistrationMapUniqueBase(const std::string_view& a_eventName);
			RegistrationMapUniqueBase(const RegistrationMapUniqueBase& a_rhs);
			RegistrationMapUniqueBase(RegistrationMapUniqueBase&& a_rhs);
			~RegistrationMapUniqueBase();

			RegistrationMapUniqueBase& operator=(const RegistrationMapUniqueBase& a_rhs);
			RegistrationMapUniqueBase& operator=(RegistrationMapUniqueBase&& a_rhs);

			bool Register(RE::ActiveEffect* a_activeEffect, Key a_key);
			bool Register(RE::BGSRefAlias* a_alias, Key a_key);
			bool Unregister(RE::ActiveEffect* a_activeEffect, Key a_key);
			bool Unregister(RE::BGSRefAlias* a_alias, Key a_key);
			void UnregisterAll(RE::ActiveEffect* a_activeEffect);
			void UnregisterAll(RE::BGSRefAlias* a_alias);
			void UnregisterAll(RE::VMHandle a_handle);
			void Clear();
			bool Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);
			void Revert(SerializationInterface*);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			bool Register(const void* a_object, RE::FormID a_formID, Key a_key, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, RE::FormID a_formID, Key a_key, RE::VMTypeID a_typeID);
			void UnregisterAll(const void* a_object, RE::FormID a_formID, RE::VMTypeID a_typeID);

			template <class T>
			bool GetMatch(T* a_filter, RE::TESForm* a_form, bool a_match)
			{
				bool result = false;

				if (a_form) {
					switch (a_form->GetFormType()) {
					case T::FORMTYPE:
						{
							result = a_match ?
                                         a_filter == a_form :
                                         a_filter != a_form;
						}
						break;
					case RE::FormType::Keyword:
						{
							if (auto keyword = a_form->As<RE::BGSKeyword>(); keyword) {
								result = a_match ?
                                             a_filter->HasKeyword(keyword) :
                                             !a_filter->HasKeyword(keyword);
							}
						}
						break;
					case RE::FormType::FormList:
						{
							if (auto list = a_form->As<RE::BGSListForm>(); list) {
								result = a_match ?
                                             a_filter->HasKeywords(list, false) :
                                             !a_filter->HasKeywords(list, false);
							}
						}
						break;
					default:
						break;
					}
				}

				return result;
			}

			std::map<Key, std::set<Handles>> _regs;
			std::string                      _eventName;
			mutable Lock                     _lock;
		};

		template <class Enable, class... Args>
		class RegistrationMapUnique;

		template <class... Args>
		class RegistrationMapUnique<
			std::enable_if_t<
				std::conjunction_v<
					RE::BSScript::is_return_convertible<Args>...>>,
			Args...> :
			public RegistrationMapUniqueBase
		{
		private:
			using super = RegistrationMapUniqueBase;

		public:
			RegistrationMapUnique() = delete;
			RegistrationMapUnique(const RegistrationMapUnique&) = default;
			RegistrationMapUnique(RegistrationMapUnique&&) = default;

			inline RegistrationMapUnique(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationMapUnique() = default;

			RegistrationMapUnique& operator=(const RegistrationMapUnique&) = default;
			RegistrationMapUnique& operator=(RegistrationMapUnique&&) = default;

			template <class T>
			inline void SendEvent(RE::TESObjectREFR* a_target, T* a_filter, Args... a_args)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				for (auto& [key, handles] : _regs) {
					auto& [filterID, match] = key;
					auto form = RE::TESForm::LookupByID(filterID);
					if (GetMatch(a_filter, form, match)) {
						const auto targetFormID = a_target->GetFormID();
						for (auto& [formID, vmHandle] : handles) {
							if (formID == targetFormID) {
								auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
								vm->SendEvent(vmHandle, eventName, args);
							}
						}
					}
				}
			}

			template <class T>
			inline void QueueEvent(RE::TESObjectREFR* a_target, T* a_filter, Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto       task = GetTaskInterface();
				assert(task);
				if (task) {
					task->AddTask([a_target, a_filter, args, this]() mutable {
						SendEvent_Tuple(a_target, a_filter, std::move(args), index_sequence_for_tuple<decltype(args)>{});
					});
				}
			}

		private:
			template <class Tuple, class T, std::size_t... I>
			inline void SendEvent_Tuple(RE::TESObjectREFR* a_target, T* a_filter, Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(a_target, a_filter, std::get<I>(std::forward<Tuple>(a_tuple)).Unpack()...);
			}
		};

		template <>
		class RegistrationMapUnique<void> : public RegistrationMapUniqueBase
		{
		private:
			using super = RegistrationMapUniqueBase;

		public:
			RegistrationMapUnique() = delete;
			RegistrationMapUnique(const RegistrationMapUnique&) = default;
			RegistrationMapUnique(RegistrationMapUnique&&) = default;

			inline RegistrationMapUnique(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationMapUnique() = default;

			RegistrationMapUnique& operator=(const RegistrationMapUnique&) = default;
			RegistrationMapUnique& operator=(RegistrationMapUnique&&) = default;

			template <class T>
			inline void SendEvent(RE::TESObjectREFR* a_target, T* a_filter)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				if (vm) {
					for (auto& [key, handles] : _regs) {
						auto& [filterID, match] = key;
						auto form = RE::TESForm::LookupByID(filterID);
						if (GetMatch(a_filter, form, match)) {
							const auto targetFormID = a_target->GetFormID();
							for (auto& [formID, vmHandle] : handles) {
								if (formID == targetFormID) {
									auto args = RE::MakeFunctionArguments();
									vm->SendEvent(vmHandle, eventName, args);
								}
							}
						}
					}
				}
			}

			template <class T>
			inline void QueueEvent(RE::TESObjectREFR* a_target, T* a_filter)
			{
				auto task = GetTaskInterface();
				assert(task);
				task->AddTask([a_target, a_filter, this]() {
					SendEventWithKey(a_target, a_filter);
				});
			}
		};
	}

	template <class... Args>
	using RegistrationMapUnique = Impl::RegistrationMapUnique<void, Args...>;
}
