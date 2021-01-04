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
			bool Register(const RE::BGSBaseAlias* a_alias, RE::BSFixedString a_callback);
			bool Unregister(const RE::TESForm* a_form);
			bool Unregister(const RE::BGSBaseAlias* a_alias);
			void Clear();
			bool Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;
			using EventName = std::string;

			bool Register(const void* a_object, RE::BSFixedString a_callback, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, RE::VMTypeID a_typeID);

			std::map<RE::VMHandle, EventName> _regs;
			mutable Lock					  _lock;
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
		public:
			RegistrationMap() = default;
			RegistrationMap(const RegistrationMap&) = default;
			RegistrationMap(RegistrationMap&&) = default;

			~RegistrationMap() = default;

			RegistrationMap& operator=(const RegistrationMap& a_rhs) = default;
			RegistrationMap& operator=(RegistrationMap&& a_rhs) = default;

			inline void SendEvent(Args... a_args)
			{
				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				for (auto& reg : _regs) {
					auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
					vm->SendEvent(reg.first, reg.second.c_str(), args);
				}
			}

			inline void QueueEvent(Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto	   task = GetTaskInterface();
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
