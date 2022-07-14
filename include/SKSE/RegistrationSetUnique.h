#pragma once

#include "RE/A/ActiveEffect.h"
#include "RE/B/BGSRefAlias.h"
#include "RE/B/BSFixedString.h"
#include "RE/F/FunctionArguments.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/T/TESForm.h"
#include "RE/T/TypeTraits.h"
#include "RE/V/VirtualMachine.h"

#include "SKSE/API.h"
#include "SKSE/Impl/RegistrationTraits.h"
#include "SKSE/Interfaces.h"

namespace SKSE
{
	namespace Impl
	{
		class RegistrationSetUniqueBase
		{
		public:
			using Handles = std::pair<RE::FormID, RE::VMHandle>;

			RegistrationSetUniqueBase() = delete;
			RegistrationSetUniqueBase(const std::string_view& a_eventName);
			RegistrationSetUniqueBase(const RegistrationSetUniqueBase& a_rhs);
			RegistrationSetUniqueBase(RegistrationSetUniqueBase&& a_rhs);
			~RegistrationSetUniqueBase();

			RegistrationSetUniqueBase& operator=(const RegistrationSetUniqueBase& a_rhs);
			RegistrationSetUniqueBase& operator=(RegistrationSetUniqueBase&& a_rhs);

			bool Register(RE::BGSRefAlias* a_alias);
			bool Register(RE::ActiveEffect* a_activeEffect);
			bool Unregister(RE::BGSRefAlias* a_alias);
			bool Unregister(RE::ActiveEffect* a_activeEffect);
			bool Unregister(RE::VMHandle a_handle);
			void Clear();
			bool Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);
			void Revert(SerializationInterface*);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			bool Register(const void* a_object, RE::FormID a_formID, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, RE::FormID a_formID, RE::VMTypeID a_typeID);

			std::set<Handles> _handles;
			std::string       _eventName;
			mutable Lock      _lock;
		};

		template <class Enable, class... Args>
		class RegistrationSetUnique;

		template <class... Args>
		class RegistrationSetUnique<
			std::enable_if_t<
				std::conjunction_v<
					RE::BSScript::is_return_convertible<Args>...>>,
			Args...> :
			public RegistrationSetUniqueBase
		{
		private:
			using super = RegistrationSetUniqueBase;

		public:
			RegistrationSetUnique() = delete;
			RegistrationSetUnique(const RegistrationSetUnique&) = default;
			RegistrationSetUnique(RegistrationSetUnique&&) = default;

			inline RegistrationSetUnique(const std::string_view& a_eventName) :
				super(a_eventName)
			{
			}

			~RegistrationSetUnique() = default;

			RegistrationSetUnique& operator=(const RegistrationSetUnique&) = default;
			RegistrationSetUnique& operator=(RegistrationSetUnique&&) = default;

			inline void SendEvent(RE::TESObjectREFR* a_target, Args... a_args)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();

				const auto targetFormID = a_target->GetFormID();
				for (auto& [formID, vmHandle] : _handles) {
					if (formID == targetFormID) {
						auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
						vm->SendEvent(vmHandle, eventName, args);
					}
				}
			}

			inline void QueueEvent(RE::TESObjectREFR* a_target, Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto       task = GetTaskInterface();
				assert(task);
				if (task) {
					task->AddTask([a_target, args, this]() mutable {
						SendEvent_Tuple(a_target, std::move(args), index_sequence_for_tuple<decltype(args)>{});
					});
				}
			}

		private:
			template <class Tuple, std::size_t... I>
			inline void SendEvent_Tuple(RE::TESObjectREFR* a_target, Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(a_target, std::get<I>(std::forward<Tuple>(a_tuple)).Unpack()...);
			}
		};

		template <>
		class RegistrationSetUnique<void> : public RegistrationSetUniqueBase
		{
		private:
			using super = RegistrationSetUniqueBase;

		public:
			RegistrationSetUnique() = delete;
			RegistrationSetUnique(const RegistrationSetUnique&) = default;
			RegistrationSetUnique(RegistrationSetUnique&&) = default;

			inline RegistrationSetUnique(const std::string_view& a_eventName) :
				super(a_eventName)
			{
			}

			~RegistrationSetUnique() = default;

			RegistrationSetUnique& operator=(const RegistrationSetUnique&) = default;
			RegistrationSetUnique& operator=(RegistrationSetUnique&&) = default;

			inline void SendEvent(RE::TESObjectREFR* a_target)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				if (vm) {
					const auto targetFormID = a_target->GetFormID();
					for (auto& [formID, vmHandle] : _handles) {
						if (formID == targetFormID) {
							auto args = RE::MakeFunctionArguments();
							vm->SendEvent(vmHandle, eventName, args);
						}
					}
				}
			}

			inline void QueueEvent(RE::TESObjectREFR* a_target)
			{
				auto task = GetTaskInterface();
				assert(task);
				task->AddTask([a_target, this]() {
					SendEvent(a_target);
				});
			}
		};
	}

	template <class... Args>
	using RegistrationSetUnique = Impl::RegistrationSetUnique<void, Args...>;
}
