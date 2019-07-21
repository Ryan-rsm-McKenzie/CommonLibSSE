#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	namespace BSScript
	{
		namespace
		{
			template <class T> struct _is_integer_type : std::is_integral<T> {};
			template <> struct _is_integer_type<bool> : std::false_type {};
		}
		template <class T> struct is_integer_type : _is_integer_type<T> {};

		template <class T> struct is_cref : std::conjunction<std::is_const<T>, std::is_reference<T>> {};
		template <class T> struct is_not_pointer : std::negation<std::is_pointer<T>> {};
		template <class T> struct is_not_reference : std::negation<std::is_reference<T>> {};

		template <class T> struct make_index_sequence_from_tuple : std::make_index_sequence<std::tuple_size<typename std::remove_reference_t<T>>::value> {};

		template <class T> struct remove_cvp { using type = typename std::remove_pointer_t<typename std::remove_cv_t<T>>; };
		template <class T> using remove_cvp_t = typename remove_cvp<T>::type;

		template <class T> struct remove_cvr { using type = typename std::remove_reference_t<typename std::remove_cv_t<T>>; };
		template <class T> using remove_cvr_t = typename remove_cvr<T>::type;

		template <class T> struct remove_cvpr { using type = typename std::remove_pointer_t<typename std::remove_reference_t<typename std::remove_cv_t<T>>>; };
		template <class T> using remove_cvpr_t = typename remove_cvpr<T>::type;

		template <class T, class U> struct is_same_no_cv : std::is_same<typename std::remove_cv_t<T>, typename std::remove_cv_t<U>> {};
		template <class T, class U> struct is_same_no_cvp : std::is_same<typename remove_cvp_t<T>, typename remove_cvp_t<U>> {};
		template <class T, class U> struct is_same_no_cvr : std::is_same<typename remove_cvr_t<T>, typename remove_cvr_t<U>> {};
		template <class T, class U> struct is_same_no_cvpr : std::is_same<typename remove_cvpr_t<T>, typename remove_cvpr_t<U>> {};

		template <class T, class U, class V = void> struct enable_if_is_same : std::enable_if<std::is_same<T, U>::value, V> {};
		template <class T, class U, class V = void> using enable_if_is_same_t = typename enable_if_is_same<T, U, V>::type;

		template <class T, class U, class V = void> struct enable_if_is_same_no_cv : std::enable_if<is_same_no_cv<T, U>::value, V> {};
		template <class T, class U, class V = void> using enable_if_is_same_no_cv_t = typename enable_if_is_same_no_cv<T, U, V>::type;

		template <class T, class U, class V = void> struct enable_if_is_same_no_cvp : std::enable_if<is_same_no_cvp<T, U>::value, V> {};
		template <class T, class U, class V = void> using enable_if_is_same_no_cvp_t = typename enable_if_is_same_no_cvp<T, U, V>::type;

		template <class T, class U, class V = void> struct enable_if_is_same_no_cvr : std::enable_if<is_same_no_cvr<T, U>::value, V> {};
		template <class T, class U, class V = void> using enable_if_is_same_no_cvr_t = typename enable_if_is_same_no_cvr<T, U, V>::type;

		template <class T, class U, class V = void> struct enable_if_is_same_no_cvpr : std::enable_if<is_same_no_cvpr<T, U>::value, V> {};
		template <class T, class U, class V = void> using enable_if_is_same_no_cvpr_t = typename enable_if_is_same_no_cvpr<T, U, V>::type;

		namespace
		{
			template <class T> struct _is_string : std::false_type {};
			template <> struct _is_string<BSFixedString> : std::true_type {};
		}
		template <class T> struct is_string : _is_string<typename std::remove_cv_t<T>> {};
		template <class T> struct is_string_no_cvr : is_string<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T> struct _is_string_compat : std::false_type {};
			template <> struct _is_string_compat<char*> : std::true_type {};
			template <> struct _is_string_compat<const char*> : std::true_type {};
			template <> struct _is_string_compat<BSFixedString> : std::true_type {};
		}
		template <class T> struct is_string_compat : _is_string_compat<typename remove_cvr_t<T>> {};


		template <class T> struct is_not_ptr_or_ref : std::conjunction<is_not_pointer<typename std::remove_reference_t<T>>, is_not_reference<typename std::remove_pointer_t<T>>> {};
		template<class T> struct is_cref_or_copy : std::disjunction<is_cref<T>, is_not_ptr_or_ref<T>> {};
		template <class T> struct is_string_cref_compat : std::conjunction<is_cref_or_copy<T>, is_string_no_cvr<T>> {};


		namespace
		{
			template <class T> struct _is_sint32 : std::false_type {};
			template <> struct _is_sint32<signed int> : std::true_type {};
			template <> struct _is_sint32<signed long> : std::true_type {};
		}
		template <class T> struct is_sint32 : _is_sint32<typename std::remove_cv_t<T>> {};
		template <class T> struct is_sint32_no_cvr : is_sint32<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T> struct _is_sint32_compat : std::conjunction<std::is_signed<T>, is_integer_type<T>> {};
		}
		template <class T> struct is_sint32_compat : _is_sint32_compat<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T> struct _is_uint32 : std::false_type {};
			template <> struct _is_uint32<unsigned int> : std::true_type {};
			template <> struct _is_uint32<unsigned long> : std::true_type {};
		}
		template <class T> struct is_uint32 : _is_uint32<typename std::remove_cv_t<T>> {};
		template <class T> struct is_uint32_no_cvr : is_uint32<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T> struct _is_uint32_compat : std::conjunction<std::is_unsigned<T>, is_integer_type<T>> {};
		}
		template <class T> struct is_uint32_compat : _is_uint32_compat<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T> struct _is_float : std::false_type {};
			template <> struct _is_float<float> : std::true_type {};
		}
		template <class T> struct is_float : _is_float<typename std::remove_cv_t<T>> {};
		template <class T> struct is_float_no_cvr : is_float<typename remove_cvr_t<T>> {};

		template <class T> struct is_float_compat : std::is_floating_point<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T> struct _is_bool : std::false_type {};
			template <> struct _is_bool<bool> : std::true_type {};
		}
		template <class T> struct is_bool : _is_bool<typename std::remove_cv_t<T>> {};
		template <class T> struct is_bool_no_cvr : is_bool<typename remove_cvr_t<T>> {};

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
		template <class T> struct is_builtin_type : _is_builtin_type<typename std::remove_cv_t<T>> {};
		template <class T> struct is_builtin_type_no_cvr : is_builtin_type<typename remove_cvr_t<T>> {};

		namespace
		{
			template <class T, class Enable = void> struct _is_builtin_compat : std::false_type {};
			template <> struct _is_builtin_compat<void> : std::true_type {};
			template <class T> struct _is_builtin_compat<T, std::enable_if_t<is_string_compat<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_compat<T, std::enable_if_t<is_sint32_compat<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_compat<T, std::enable_if_t<is_uint32_compat<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_compat<T, std::enable_if_t<is_float_compat<T>::value>> : std::true_type {};
			template <class T> struct _is_builtin_compat<T, std::enable_if_t<is_bool<T>::value>> : std::true_type {};
		}
		template <class T> struct is_builtin_compat : _is_builtin_compat<typename remove_cvr_t<T>> {};

		template <class T> struct is_form_type : std::is_base_of<TESForm, typename remove_cvpr_t<T>> {};
		template <class T> struct is_form_pointer : std::conjunction<is_form_type<T>, std::is_pointer<T>> {};
		template <class T> struct is_form_pointer_no_cvr : is_form_pointer<typename remove_cvr_t<T>> {};

		namespace
		{
			template <VMTypeID ID> struct vm_type_constant : std::integral_constant<VMTypeID, ID> {};

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
		template <class T> struct vm_type : _vm_type<typename remove_cvpr_t<T>> {};
	}
}
