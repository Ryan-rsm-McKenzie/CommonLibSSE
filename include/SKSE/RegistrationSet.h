#pragma once

#include <mutex>  // recursive_mutex, lock_guard
#include <set>  // set
#include <string>  // string
#include <string_view>  // string_view
#include <tuple>  // tuple

#include "SKSE/API.h"  // GetTaskInterface
#include "SKSE/Interfaces.h"  // SerializationInterface
#include "SKSE/RegistrationTraits.h"

#include "RE/BSScript/Internal/VirtualMachine.h"  // BSScript::Internal::VirtualMachine
#include "RE/BSScript/FunctionArguments.h"  // BSScript::FunctionArguments
#include "RE/BSScript/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/BSScript/TypeTraits.h"  // BSScript::is_param_compat
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/TESForm.h"  // TESForm


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

			bool Register(RE::TESForm* a_form);
			bool Unregister(RE::TESForm* a_form);
			void Clear();
			bool Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;


			std::set<RE::VMHandle> _handles;
			std::string _eventName;
			mutable Lock _lock;
		};


		template <class Enable, class... Args> class RegistrationSet;


		template <class... Args>
		class RegistrationSet<typename std::enable_if_t<std::conjunction<RE::BSScript::is_param_compat<Args>...>::value>, Args...> :
			public RegistrationSetBase
		{
		private:
			using Base = RegistrationSetBase;

		public:
			RegistrationSet() = delete;
			RegistrationSet(const std::string_view& a_eventName) : Base(a_eventName) {}
			RegistrationSet(const RegistrationSet& a_rhs) : Base(a_rhs) {}
			RegistrationSet(RegistrationSet&& a_rhs) : Base(std::move(a_rhs)) {}
			~RegistrationSet() {}


			inline RegistrationSet& operator=(const RegistrationSet& a_rhs) { Base::operator=(a_rhs); return *this; }
			inline RegistrationSet& operator=(RegistrationSet&& a_rhs) { Base::operator=(std::move(a_rhs)); return *this; }


			void SendEvent(Args... a_args)
			{
				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				RE::BSFixedString eventName(_eventName.c_str());
				for (auto& handle : _handles) {
					auto args = RE::MakeFunctionArguments(a_args...);
					vm->QueueEvent(handle, eventName, args);
				}
			}


			void QueueEvent(Args... a_args)
			{
				auto args = PackArgs(a_args...);
				auto task = GetTaskInterface();
				task->AddTask([args, this]()
				{
					SendEvent_Tuple(std::move(args), make_index_sequence_from_tuple<decltype(args)>{});
				});
			}

		private:
			template <class Tuple, std::size_t... I>
			void SendEvent_Tuple(Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(std::move(UnpackArg(std::get<I>(std::forward<Tuple>(a_tuple))))...);
			}
		};


		template <>
		class RegistrationSet<void> : public RegistrationSetBase
		{
		private:
			using Base = RegistrationSetBase;

		public:
			RegistrationSet() = delete;
			RegistrationSet(const std::string_view& a_eventName) : Base(a_eventName) {}
			RegistrationSet(const RegistrationSet& a_rhs) : Base(a_rhs) {}
			RegistrationSet(RegistrationSet&& a_rhs) : Base(std::move(a_rhs)) {}
			~RegistrationSet() {}


			inline RegistrationSet& operator=(const RegistrationSet& a_rhs) { Base::operator=(a_rhs); return *this; }
			inline RegistrationSet& operator=(RegistrationSet&& a_rhs) { Base::operator=(std::move(a_rhs)); return *this; }


			void SendEvent()
			{
				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				RE::BSFixedString eventName(_eventName.c_str());
				for (auto& handle : _handles) {
					auto args = RE::MakeFunctionArguments();
					vm->QueueEvent(handle, eventName, args);
				}
			}


			void QueueEvent()
			{
				auto task = GetTaskInterface();
				task->AddTask([this]()
				{
					SendEvent();
				});
			}
		};
	}


	template <class... Args> using RegistrationSet = Impl::RegistrationSet<void, Args...>;
}
