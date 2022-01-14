#pragma once

#include "RE/A/ActiveEffect.h"
#include "RE/B/BGSBaseAlias.h"
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
		class RegistrationMapBase
		{
		public:
			using Key = std::variant<std::string, RE::FormID, RE::FormType>;

			RegistrationMapBase() = delete;
			RegistrationMapBase(const std::string_view& a_eventName);
			RegistrationMapBase(const RegistrationMapBase& a_rhs);
			RegistrationMapBase(RegistrationMapBase&& a_rhs);
			~RegistrationMapBase();

			RegistrationMapBase& operator=(const RegistrationMapBase& a_rhs);
			RegistrationMapBase& operator=(RegistrationMapBase&& a_rhs);

			bool Register(const RE::TESForm* a_form, Key a_key);
			bool Register(const RE::BGSBaseAlias* a_alias, Key a_key);
			bool Register(const RE::ActiveEffect* a_activeEffect, Key a_key);
			bool Unregister(const RE::TESForm* a_form, Key a_key);
			bool Unregister(const RE::BGSBaseAlias* a_alias, Key a_key);
			bool Unregister(const RE::ActiveEffect* a_activeEffect, Key a_key);
			void UnregisterAll(const RE::TESForm* a_form);
			void UnregisterAll(const RE::BGSBaseAlias* a_alias);
			void UnregisterAll(const RE::ActiveEffect* a_activeEffect);
			void UnregisterAll(RE::VMHandle a_handle);
			void Clear();
			bool Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);
			void Revert(SerializationInterface*);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			bool Register(const void* a_object, Key a_key, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, Key a_key, RE::VMTypeID a_typeID);
			void UnregisterAll(const void* a_object, RE::VMTypeID a_typeID);

			std::map<Key, std::set<RE::VMHandle>> _regs;
			std::string                           _eventName;
			mutable Lock                          _lock;
		};

		template <class Enable, class... Args>
		class RegistrationMap;

		template <class... Args>
		class RegistrationMap<
			std::enable_if_t<
				std::conjunction_v<
					RE::BSScript::is_return_convertible<Args>...>>,
			Args...> :
			public RegistrationMapBase
		{
		private:
			using super = RegistrationMapBase;

		public:
			RegistrationMap() = delete;
			RegistrationMap(const RegistrationMap&) = default;
			RegistrationMap(RegistrationMap&&) = default;

			inline RegistrationMap(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationMap() = default;

			RegistrationMap& operator=(const RegistrationMap&) = default;
			RegistrationMap& operator=(RegistrationMap&&) = default;

			inline void SendEvent(Key a_key, Args... a_args)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				for (auto& [key, handles] : _regs) {
					if (key == a_key) {
						for (auto& handle : handles) {
							auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
							vm->SendEvent(handle, eventName, args);
						}
					}
				}
			}

			inline void QueueEvent(Key a_key, Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto       task = GetTaskInterface();
				assert(task);
				if (task) {
					task->AddTask([a_key, args, this]() mutable {
						SendEvent_Tuple(a_key, std::move(args), index_sequence_for_tuple<decltype(args)>{});
					});
				}
			}

		private:
			template <class Tuple, std::size_t... I>
			inline void SendEvent_Tuple(Key a_key, Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(a_key, std::get<I>(std::forward<Tuple>(a_tuple)).Unpack()...);
			}
		};

		template <>
		class RegistrationMap<void> : public RegistrationMapBase
		{
		private:
			using super = RegistrationMapBase;

		public:
			RegistrationMap() = delete;
			RegistrationMap(const RegistrationMap&) = default;
			RegistrationMap(RegistrationMap&&) = default;

			inline RegistrationMap(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationMap() = default;

			RegistrationMap& operator=(const RegistrationMap&) = default;
			RegistrationMap& operator=(RegistrationMap&&) = default;

			inline void SendEvent(Key a_key)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				if (vm) {
					for (auto& [key, handles] : _regs) {
						if (key == a_key) {
							for (auto& handle : handles) {
								auto args = RE::MakeFunctionArguments();
								vm->SendEvent(handle, eventName, args);
							}
						}
					}
				}
			}

			inline void QueueEvent(Key a_key)
			{
				auto task = GetTaskInterface();
				assert(task);
				task->AddTask([a_key, this]() {
					SendEvent(a_key);
				});
			}
		};
	}

	template <class... Args>
	using RegistrationMap = Impl::RegistrationMap<void, Args...>;
}
