#pragma once

#include <tuple>
#include <type_traits>

#include "RE/NiSmartPointer.h"
#include "RE/TESForm.h"
#include "RE/TESObjectREFR.h"


namespace SKSE
{
	namespace Impl
	{
		namespace
		{
			template <class T>
			using is_object_pointer = std::is_convertible<T, RE::TESObjectREFR*>;
			template <class T>
			using is_not_object_pointer = std::negation<is_object_pointer<T>>;
			template <class T>
			using is_form_pointer = std::is_convertible<T, RE::TESForm*>;
			template <class T>
			using is_not_form_pointer = std::negation<is_form_pointer<T>>;

			template <class T>
			struct make_index_sequence_from_tuple : std::make_index_sequence<std::tuple_size<typename std::remove_reference_t<T>>::value>
			{};


			// use a template wrapper so we can preserve type info
			template <class T>
			struct FormWrapper
			{
				RE::FormID formID;
			};
		}


		// default
		template <class T, class U = std::decay_t<T>, typename std::enable_if_t<std::conjunction<is_not_form_pointer<U>, is_not_object_pointer<U>>::value, int> = 0>
		inline T PackArg(T&& a_val)
		{
			return a_val;
		}


		// forms
		template <class T, class U = std::decay_t<T>, typename std::enable_if_t<std::conjunction<is_form_pointer<U>, is_not_object_pointer<U>>::value, int> = 0>
		inline FormWrapper<U> PackArg(T&& a_form)
		{
			auto formID = a_form ? a_form->formID : static_cast<RE::FormID>(-1);
			return { formID };
		}


		// obj references
		template <class T, class U = std::decay_t<T>, typename std::enable_if_t<is_object_pointer<U>::value, int> = 0>
		inline RE::NiPointer<std::remove_pointer_t<U>> PackArg(T&& a_objRef)
		{
			return { a_objRef };
		}


		template <class... Args>
		inline decltype(auto) PackArgs(Args&&... a_args)
		{
			return std::make_tuple(PackArg(std::forward<Args>(a_args))...);
		}


		// default
		template <class T>
		inline T UnpackArg(T&& a_val)
		{
			return a_val;
		}


		// forms
		template <class T>
		inline T UnpackArg(const FormWrapper<T>& a_wrapper)
		{
			return static_cast<T>(RE::TESForm::LookupByID(a_wrapper.formID));
		}


		template <class T>
		inline T UnpackArg(FormWrapper<T>&& a_wrapper)
		{
			return static_cast<T>(RE::TESForm::LookupByID(a_wrapper.formID));
		}


		// obj references
		template <class T>
		inline T* UnpackArg(const RE::NiPointer<T>& a_objRef)
		{
			return a_objRef.get();
		}


		template <class T>
		inline T* UnpackArg(RE::NiPointer<T>&& a_objRef)
		{
			return a_objRef.get();
		}
	}
}
