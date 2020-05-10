#pragma once

#include <cassert>
#include <map>
#include <mutex>
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
		class RegistrationMapBase
		{
		public:
			RegistrationMapBase();
			RegistrationMapBase(const RegistrationMapBase& a_rhs);
			RegistrationMapBase(RegistrationMapBase&& a_rhs);
			~RegistrationMapBase();

			RegistrationMapBase& operator=(const RegistrationMapBase& a_rhs);
			RegistrationMapBase& operator=(RegistrationMapBase&& a_rhs);

			bool Register(const RE::TESForm* a_form, RE::BSFixedString a_callback);
			bool Unregister(const RE::TESForm* a_form);
			void Clear();
			bool Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;
			using EventName = std::string;

			std::map<RE::VMHandle, EventName> _regs;
			mutable Lock					  _lock;
		};


		template <class Enable, class... Args>
		class RegistrationMap;


		template <class... Args>
		class RegistrationMap<typename std::enable_if_t<std::conjunction<RE::BSScript::is_param_compat<Args>...>::value>, Args...> :
			public RegistrationMapBase
		{
		public:
			RegistrationMap() = default;
			RegistrationMap(const RegistrationMap&) = default;
			RegistrationMap(RegistrationMap&&) = default;

			~RegistrationMap() = default;

			RegistrationMap& operator=(const RegistrationMap& a_rhs) = default;
			RegistrationMap& operator=(RegistrationMap&& a_rhs) = default;

			inline void SendEvent(Args&&... a_args)
			{
				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				for (auto& reg : _regs) {
					auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
					vm->SendEvent(reg.first, reg.second.c_str(), args);
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
		class RegistrationMap<void> : public RegistrationMapBase
		{
		public:
			RegistrationMap() = default;
			RegistrationMap(const RegistrationMap&) = default;
			RegistrationMap(RegistrationMap&&) = default;

			~RegistrationMap() = default;

			RegistrationMap& operator=(const RegistrationMap&) = default;
			RegistrationMap& operator=(RegistrationMap&&) = default;

			inline void SendEvent()
			{
				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				if (vm) {
					for (auto& reg : _regs) {
						auto args = RE::MakeFunctionArguments();
						vm->SendEvent(reg.first, reg.second.c_str(), args);
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
	using RegistrationMap = Impl::RegistrationMap<void, Args...>;
}
