#pragma once

#include <type_traits>

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSScriptArray.h"  // BSScriptArray
#include "RE/BSScriptObject.h"  // BSScriptObject
#include "RE/TESForm.h"  // TESForm
#include "RE/VMArray.h"  // VMArray


namespace RE
{
	namespace BSScript
	{
		struct StaticFunctionTag {};


		template <class T> struct make_index_sequence_from_tuple : std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<T>>> {};

		template <class T> struct remove_cvp { using type = typename std::remove_pointer_t<std::remove_cv_t<T>>; };
		template <class T> using remove_cvp_t = typename remove_cvp<T>::type;

		template <class T> struct remove_cvr { using type = typename std::remove_reference_t<std::remove_cv_t<T>>; };
		template <class T> using remove_cvr_t = typename remove_cvr<T>::type;

		template <class T> struct remove_cvpr { using type = typename std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<T>>>; };
		template <class T> using remove_cvpr_t = typename remove_cvpr<T>::type;

		namespace
		{
			template <class T> struct _is_script_array_pointer : std::false_type {};
			template <> struct _is_script_array_pointer<BSScriptArray*> : std::true_type {};
		}
		template <class T> struct is_script_array_pointer : _is_script_array_pointer<remove_cvr_t<T>>::type {};

		namespace
		{
			template <class T> struct _is_script_object_pointer : std::false_type {};
			template <> struct _is_script_object_pointer<BSScriptObject*> : std::true_type {};
		}
		template <class T> struct is_script_object_pointer : _is_script_object_pointer<remove_cvr_t<T>>::type {};

		namespace
		{
			template <class T> struct _is_string : std::false_type {};
			template <> struct _is_string<BSFixedString> : std::true_type {};
		}
		template <class T> struct is_string : _is_string<remove_cvr_t<T>>::type {};

		namespace
		{
			template <class T> struct _is_sint32 : std::false_type {};
			template <> struct _is_sint32<signed int> : std::true_type {};
			template <> struct _is_sint32<signed long> : std::true_type {};
		}
		template <class T> struct is_sint32 : _is_sint32<remove_cvr_t<T>>::type {};

		namespace
		{
			template <class T> struct _is_uint32 : std::false_type {};
			template <> struct _is_uint32<unsigned int> : std::true_type {};
			template <> struct _is_uint32<unsigned long> : std::true_type {};
		}
		template <class T> struct is_uint32 : _is_uint32<remove_cvr_t<T>>::type {};

		namespace
		{
			template <class T> struct _is_float : std::false_type {};
			template <> struct _is_float<float> : std::true_type {};
		}
		template <class T> struct is_float : _is_float<remove_cvr_t<T>>::type {};

		namespace
		{
			template <class T> struct _is_bool : std::false_type {};
			template <> struct _is_bool<bool> : std::true_type {};
		}
		template <class T> struct is_bool : _is_bool<remove_cvr_t<T>>::type {};

		template <class T, class U> struct is_same_no_cv : std::is_same<std::remove_cv_t<T>, std::remove_cv_t<U>> {};
		template <class T, class U> struct is_same_no_cvp : std::is_same<remove_cvp_t<T>, remove_cvp_t<U>> {};
		template <class T, class U> struct is_same_no_cvr : std::is_same<remove_cvr_t<T>, remove_cvr_t<U>> {};
		template <class T, class U> struct is_same_no_cvpr : std::is_same<remove_cvpr_t<T>, remove_cvpr_t<U>> {};

		template <class T, class U, class V = void> struct enable_if_is_same : std::enable_if<is_same_no_cv<T, U>::value, V> {};
		template <class T, class U, class V = void> using enable_if_is_same_t = typename enable_if_is_same<T, U, V>::type;

		namespace
		{
			template <class T, class Enable = void> struct _is_builtin_type : std::false_type {};
			template <> struct _is_builtin_type<void> : std::true_type {};
			template <class T> struct _is_builtin_type<T, std::enable_if_t<is_string<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_type<T, std::enable_if_t<is_sint32<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_type<T, std::enable_if_t<is_uint32<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_type<T, std::enable_if_t<is_float<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_type<T, std::enable_if_t<is_bool<T>::value>> : std::true_type {};
		}
		template <class T> struct is_builtin_type : _is_builtin_type<std::remove_cv_t<T>>::type {};

		template <VMTypeID ID> struct vm_type_constant : std::integral_constant<VMTypeID, ID> {};

		namespace
		{
			template <class T> struct _vm_type;
			template <> struct _vm_type<void> : vm_type_constant<VMTypeID::kNone> {};
			template <> struct _vm_type<BSFixedString> : vm_type_constant<VMTypeID::kString> {};
			template <> struct _vm_type<signed int> : vm_type_constant<VMTypeID::kInt> {};
			template <> struct _vm_type<signed long> : vm_type_constant<VMTypeID::kInt> {};
			template <> struct _vm_type<unsigned int> : vm_type_constant<VMTypeID::kInt> {};
			template <> struct _vm_type<unsigned long> : vm_type_constant<VMTypeID::kInt> {};
			template <> struct _vm_type<float> : vm_type_constant<VMTypeID::kFloat> {};
			template <> struct _vm_type<bool> : vm_type_constant<VMTypeID::kBool> {};
		}
		template <class T> struct vm_type : _vm_type<std::remove_cv_t<T>>::type {};

		template <class T> struct is_form_type : std::is_base_of<TESForm, remove_cvpr_t<T>> {};

		template <class T, class Enable = void> struct is_form_pointer : std::false_type {};
		template <class T> struct is_form_pointer<T, std::enable_if_t<is_form_type<T>::value>> : std::is_pointer<T> {};

		namespace
		{
			template <class T> struct _is_vm_array : std::false_type {};
			template <class T> struct _is_vm_array<VMArray<T>> : std::true_type {};
		}
		template <class T> struct is_vm_array : _is_vm_array<remove_cvpr_t<T>>::type {};

		namespace
		{
			template <class T> struct _remove_vm_array { using type = T; };
			template <class T> struct _remove_vm_array<VMArray<T>> { using type = T; };
		}
		template <class T> struct remove_vm_array : _remove_vm_array<remove_cvpr_t<T>> {};
		template <class T> using remove_vm_array_t = typename remove_vm_array<T>::type;

		template <class T> struct is_vm_form_array : std::conjunction<is_vm_array<T>, is_form_pointer<remove_vm_array_t<T>>> {};
		template <class T> struct is_vm_form_array_pointer : std::conjunction<is_vm_form_array<T>, std::is_pointer<T>> {};
		template <class T> struct is_vm_builtin_array : std::conjunction<is_vm_array<T>, is_builtin_type<remove_vm_array_t<T>>> {};
		template <class T> struct is_vm_builtin_array_pointer : std::conjunction<is_vm_builtin_array<T>, std::is_pointer<T>> {};

		template <class T, class Enable = void> struct is_static_base : std::false_type {};
		template <class T> struct is_static_base<T, std::enable_if_t<is_same_no_cvpr<T, StaticFunctionTag>::value>> : std::true_type {};

		template <class T, class Enable = void> struct is_static_base_pointer : std::false_type {};
		template <class T> struct is_static_base_pointer<T, std::enable_if_t<is_static_base<T>::value>> : std::is_pointer<T> {};
	}
}
