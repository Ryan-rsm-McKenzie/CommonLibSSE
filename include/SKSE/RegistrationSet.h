#pragma once

#include <mutex>  // mutex, lock_guard
#include <set>  // set
#include <string>  // string

#include "SKSE/API.h"  // GetTaskInterface
#include "SKSE/Interfaces.h"  // SerializationInterface

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FunctionArguments.h"  // FunctionArguments
#include "RE/IObjectHandlePolicy.h"  // IObjectHandlePolicy
#include "RE/TESForm.h"  // TESForm
#include "RE/VirtualMachine.h"  // VirtualMachine


namespace SKSE
{
	namespace Impl
	{
		class RegistrationSetBase
		{
		public:
			RegistrationSetBase() = delete;
			RegistrationSetBase(const char* a_eventName);
			RegistrationSetBase(const RegistrationSetBase& a_rhs);
			RegistrationSetBase(RegistrationSetBase&& a_rhs);
			~RegistrationSetBase();

			RegistrationSetBase& operator=(const RegistrationSetBase& a_rhs);
			RegistrationSetBase& operator=(RegistrationSetBase&& a_rhs);

			bool Register(RE::TESForm* a_form);
			bool Unregister(RE::TESForm* a_form);
			void Clear();
			bool Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Locker = std::lock_guard<std::mutex>;


			std::set<RE::VMHandle>	_handles;
			std::string				_eventName;
			mutable std::mutex		_lock;
		};
	}


	template <class... Args>
	class RegistrationSet : public Impl::RegistrationSetBase
	{
	public:
		RegistrationSet() = delete;
		RegistrationSet(const char* a_eventName) : Impl::RegistrationSetBase(a_eventName) {}
		RegistrationSet(const RegistrationSet& a_rhs) : Impl::RegistrationSetBase(a_rhs) {}
		RegistrationSet(RegistrationSet&& a_rhs) : Impl::RegistrationSetBase(std::move(a_rhs)) {}
		~RegistrationSet() {}


		inline RegistrationSet& operator=(const RegistrationSet& a_rhs) { Impl::RegistrationSetBase::operator=(a_rhs); return *this; }
		inline RegistrationSet& operator=(RegistrationSet&& a_rhs) { Impl::RegistrationSetBase::operator=(std::move(a_rhs)); return *this; }


		void SendEvent(Args... a_args)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			RE::BSFixedString eventName(_eventName.c_str());
			for (auto& handle : _handles) {
				auto args = RE::MakeFunctionArguments(a_args);
				vm->QueueEvent(handle, eventName, args);
			}
		}


		void QueueEvent(Args... a_args)
		{
			AddTask([&]()
			{
				SendEvent(a_args);
			});
		}
	};


	template <>
	class RegistrationSet<> : public Impl::RegistrationSetBase
	{
	public:
		RegistrationSet() = delete;
		RegistrationSet(const char* a_eventName) : Impl::RegistrationSetBase(a_eventName) {}
		RegistrationSet(const RegistrationSet& a_rhs) : Impl::RegistrationSetBase(a_rhs) {}
		RegistrationSet(RegistrationSet&& a_rhs) : Impl::RegistrationSetBase(std::move(a_rhs)) {}
		~RegistrationSet() {}


		inline RegistrationSet& operator=(const RegistrationSet& a_rhs) { Impl::RegistrationSetBase::operator=(a_rhs); return *this; }
		inline RegistrationSet& operator=(RegistrationSet&& a_rhs) { Impl::RegistrationSetBase::operator=(std::move(a_rhs)); return *this; }


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
			task->AddTask([&]()
			{
				SendEvent();
			});
		}
	};
}
