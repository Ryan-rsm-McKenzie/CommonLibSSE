#pragma once

#include <mutex>  // recursive_mutex, lock_guard
#include <set>  // set
#include <string>  // string
#include <string_view>  // string_view
#include <tuple>  // tuple

#include "SKSE/API.h"  // GetTaskInterface
#include "SKSE/Interfaces.h"  // SerializationInterface

#include "RE/BSScript/Internal/VirtualMachine.h"  // BSScript::Internal::VirtualMachine
#include "RE/BSScript/FunctionArguments.h"  // BSScript::FunctionArguments
#include "RE/BSScript/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/BSScript/TypeTraits.h"  // BSScript::is_param_compat
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiSmartPointer.h"  // NiPointer
#include "RE/TESForm.h"  // TESForm
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace SKSE
{
	namespace Impl
	{
		namespace
		{
			template <class T> using is_object_pointer = std::is_convertible<T, RE::TESObjectREFR*>;
			template <class T> using is_not_object_pointer = std::negation<is_object_pointer<T>>;
			template <class T> using is_form_pointer = std::is_convertible<T, RE::TESForm*>;
			template <class T> using is_not_form_pointer = std::negation<is_form_pointer<T>>;

			template <class T> struct make_index_sequence_from_tuple : std::make_index_sequence<std::tuple_size<typename std::remove_reference_t<T>>::value> {};


			// use a template wrapper so we can preserve type info
			template <class T>
			struct FormWrapper
			{
				RE::FormID formID;
			};
		}


		// default
		template <class T, typename std::enable_if_t<std::conjunction<is_not_form_pointer<T>, is_not_object_pointer<T>>::value, int> = 0>
		inline T PackArg(T a_val)
		{
			return a_val;
		}


		// forms
		template <class T, typename std::enable_if_t<std::conjunction<is_form_pointer<T>, is_not_object_pointer<T>>::value, int> = 0>
		inline FormWrapper<T> PackArg(T a_form)
		{
			auto form = static_cast<RE::TESForm*>(a_form);
			auto formID = form ? form->formID : static_cast<RE::FormID>(-1);
			return { formID };
		}


		// obj references
		template <class T, typename std::enable_if_t<is_object_pointer<T>::value, int> = 0>
		inline RE::NiPointer<typename std::remove_pointer_t<T>> PackArg(T a_objRef)
		{
			return { a_objRef };
		}


		template <class... Args>
		inline decltype(auto) PackArgs(Args... a_args)
		{
			return std::make_tuple(PackArg(a_args)...);
		}


		// default
		template <class T>
		inline T& UnpackArg(T& a_val)
		{
			return a_val;
		}


		// forms
		template <class T>
		inline T UnpackArg(FormWrapper<T> a_wrapper)
		{
			return static_cast<T>(RE::TESForm::LookupByID(a_wrapper.formID));
		}


		// obj references
		template <class T>
		inline T* UnpackArg(RE::NiPointer<T> a_objRef)
		{
			return a_objRef.get();
		}


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
