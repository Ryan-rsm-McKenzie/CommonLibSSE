#pragma once

#include <cassert>
#include <mutex>
#include <set>
#include <string>
#include <string_view>
#include <tuple>

#include "RE/BSFixedString.h"
#include "RE/BSScript/FunctionArguments.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/TypeTraits.h"
#include "RE/TESForm.h"

#include "SKSE/API.h"
#include "SKSE/Interfaces.h"
#include "SKSE/RegistrationTraits.h"


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
			bool Unregister(const RE::TESForm* a_form);
			void Clear();
			bool Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			std::set<RE::VMHandle> _handles;
			std::string			   _eventName;
			mutable Lock		   _lock;
		};


		template <class Enable, class... Args>
		class RegistrationSet;


		template <class... Args>
		class RegistrationSet<typename std::enable_if_t<std::conjunction<RE::BSScript::is_param_compat<Args>...>::value>, Args...> :
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

			inline void SendEvent(Args&&... a_args)
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
				auto args = PackArgs(std::move(a_args)...);
				auto task = GetTaskInterface();
				task->AddTask([args, this]() {
					SendEvent_Tuple(std::move(args), make_index_sequence_from_tuple<decltype(args)>{});
				});
			}

		private:
			template <class Tuple, std::size_t... I>
			inline void SendEvent_Tuple(Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(std::move(UnpackArg(std::get<I>(std::forward<Tuple>(a_tuple))))...);
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
