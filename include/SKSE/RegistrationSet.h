#pragma once

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
		class RegistrationSetBase
		{
		public:
			RegistrationSetBase() = delete;
			RegistrationSetBase(const std::string_view& a_eventName);
			RegistrationSetBase(const RegistrationSetBase& a_rhs);
			RegistrationSetBase(RegistrationSetBase&& a_rhs);
			~RegistrationSetBase();

			RegistrationSetBase& operator=(const RegistrationSetBase& a_rhs);
			RegistrationSetBase& operator=(RegistrationSetBase&& a_rhs);

			bool Register(const RE::TESForm* a_form);
			bool Register(const RE::BGSBaseAlias* a_alias);
			bool Register(const RE::ActiveEffect* a_effect);
			bool Unregister(const RE::TESForm* a_form);
			bool Unregister(const RE::BGSBaseAlias* a_alias);
			bool Unregister(const RE::ActiveEffect* a_effect);
			bool Unregister(RE::VMHandle a_handle);
			void Clear();
			bool Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);
			void Revert(SerializationInterface*);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			bool Register(const void* a_object, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, RE::VMTypeID a_typeID);

			std::set<RE::VMHandle> _handles;
			std::string            _eventName;
			mutable Lock           _lock;
		};

		template <class Enable, class... Args>
		class RegistrationSet;

		template <class... Args>
		class RegistrationSet<
			std::enable_if_t<
				std::conjunction_v<
					RE::BSScript::is_return_convertible<Args>...>>,
			Args...> :
			public RegistrationSetBase
		{
		private:
			using super = RegistrationSetBase;

		public:
			RegistrationSet() = delete;
			RegistrationSet(const RegistrationSet&) = default;
			RegistrationSet(RegistrationSet&&) = default;

			inline RegistrationSet(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationSet() = default;

			RegistrationSet& operator=(const RegistrationSet&) = default;
			RegistrationSet& operator=(RegistrationSet&&) = default;

			inline void SendEvent(Args... a_args)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				for (auto& handle : _handles) {
					auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
					vm->SendEvent(handle, eventName, args);
				}
			}

			inline void QueueEvent(Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto       task = GetTaskInterface();
				assert(task);
				if (task) {
					task->AddTask([args, this]() mutable {
						SendEvent_Tuple(std::move(args), index_sequence_for_tuple<decltype(args)>{});
					});
				}
			}

		private:
			template <class Tuple, std::size_t... I>
			inline void SendEvent_Tuple(Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(std::get<I>(std::forward<Tuple>(a_tuple)).Unpack()...);
			}
		};

		template <>
		class RegistrationSet<void> : public RegistrationSetBase
		{
		private:
			using super = RegistrationSetBase;

		public:
			RegistrationSet() = delete;
			RegistrationSet(const RegistrationSet&) = default;
			RegistrationSet(RegistrationSet&&) = default;

			inline RegistrationSet(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationSet() = default;

			RegistrationSet& operator=(const RegistrationSet&) = default;
			RegistrationSet& operator=(RegistrationSet&&) = default;

			inline void SendEvent()
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				if (vm) {
					for (auto& handle : _handles) {
						auto args = RE::MakeFunctionArguments();
						vm->SendEvent(handle, eventName, args);
					}
				}
			}

			inline void QueueEvent()
			{
				auto task = GetTaskInterface();
				assert(task);
				task->AddTask([this]() {
					SendEvent();
				});
			}
		};
	}

	template <class... Args>
	using RegistrationSet = Impl::RegistrationSet<void, Args...>;
}
