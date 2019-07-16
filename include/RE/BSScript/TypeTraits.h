#pragma once

#include <type_traits>

#include "RE/BSScript/ArrayTypeTraits.h"
#include "RE/BSScript/ObjectTypeTraits.h"
#include "RE/BSScript/CommonTypeTraits.h"
#include "RE/BSScript/VMArray.h"  // BSScript::VMArray


namespace RE
{
	struct StaticFunctionTag {};


	namespace BSScript
	{
		namespace
		{
			template <class T> struct _is_vm_array : std::false_type {};
			template <class T> struct _is_vm_array<VMArray<T>> : std::true_type {};
		}
		template <class T> struct is_vm_array : _is_vm_array<typename std::remove_cv_t<T>>::type {};

		namespace
		{
			template <class T> struct _remove_vm_array { using type = T; };
			template <class T> struct _remove_vm_array<VMArray<T>> { using type = T; };
		}
		template <class T> struct remove_vm_array : _remove_vm_array<typename remove_cvpr_t<T>> {};
		template <class T> using remove_vm_array_t = typename remove_vm_array<T>::type;

		template <class T> struct is_vm_form_array : std::conjunction<is_vm_array<T>, is_form_pointer<typename remove_vm_array_t<T>>> {};
		template <class T> struct is_vm_form_array_no_cvr : is_vm_form_array<typename remove_cvr_t<T>> {};

		template <class T> struct is_vm_builtin_array : std::conjunction<is_vm_array<T>, is_builtin_type<typename remove_vm_array_t<T>>> {};
		template <class T> struct is_vm_builtin_array_no_cvr : is_vm_builtin_array<typename remove_cvr_t<T>> {};

		template <class T> struct is_static_base : is_same_no_cvp<T, StaticFunctionTag> {};
		template <class T> struct is_static_base_pointer : std::conjunction<is_static_base<T>, std::is_pointer<T>> {};

		template <class T> struct is_valid_base : std::disjunction<is_static_base_pointer<T>, is_form_pointer<T>> {};
		template <class T> struct is_valid_param : std::disjunction<is_builtin_type<T>, is_vm_builtin_array<T>, is_form_pointer<T>, is_vm_form_array<T>> {};
		template <class T> struct is_valid_return : std::disjunction<std::is_void<T>, is_valid_param<T>> {};
		template <class R, class Cls, class... Args> struct is_valid_short_sig : std::conjunction<is_valid_return<R>, is_valid_base<Cls>, is_valid_param<Args>...> {};
		template <class Int, class R, class Cls, class... Args> struct is_valid_long_sig : std::conjunction<is_uint32<typename std::make_unsigned_t<Int>>, is_valid_short_sig<R, Cls, Args...>> {};

		template <class T> struct is_param_compat : std::disjunction<is_builtin_compat<T>, is_vm_builtin_array<T>, is_form_pointer<T>, is_vm_form_array<T>> {};
	}
}
