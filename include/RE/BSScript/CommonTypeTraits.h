#pragma once

#include "RE/BSFixedString.h"
#include "RE/TESForm.h"


namespace RE
{
	namespace BSScript
	{
		namespace
		{
			template <class T>
			struct _is_integer_type :
				std::is_integral<T>
			{};

			template <>
			struct _is_integer_type<bool> :
				std::false_type
			{};
		}

		template <class T>
		struct is_integer_type :
			_is_integer_type<T>
		{};


		template <class T>
		struct is_cref :
			std::conjunction<std::is_const<T>, std::is_reference<T>>
		{};

		template <class T>
		struct is_not_pointer :
			std::negation<std::is_pointer<T>>
		{};

		template <class T>
		struct is_not_reference :
			std::negation<std::is_reference<T>>
		{};


		template <class T>
		struct make_index_sequence_from_tuple :
			std::make_index_sequence<std::tuple_size<std::remove_reference_t<T>>::value>
		{};


		template <class T>
		struct remove_cvp
		{
			using type = std::remove_pointer_t<std::remove_cv_t<T>>;
		};

		template <class T>
		using remove_cvp_t = typename remove_cvp<T>::type;


		template <class T>
		struct remove_cvr
		{
			using type = std::remove_reference_t<std::remove_cv_t<T>>;
		};

		template <class T>
		using remove_cvr_t = typename remove_cvr<T>::type;


		template <class T>
		struct remove_cvpr
		{
			using type = std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<T>>>;
		};

		template <class T>
		using remove_cvpr_t = typename remove_cvpr<T>::type;


		template <class T, class U>
		struct is_same_no_cv :
			std::is_same<std::remove_cv_t<T>, std::remove_cv_t<U>>
		{};

		template <class T, class U>
		struct is_same_no_cvp :
			std::is_same<remove_cvp_t<T>, remove_cvp_t<U>>
		{};

		template <class T, class U>
		struct is_same_no_cvr :
			std::is_same<remove_cvr_t<T>, remove_cvr_t<U>>
		{};

		template <class T, class U>
		struct is_same_no_cvpr :
			std::is_same<remove_cvpr_t<T>, remove_cvpr_t<U>>
		{};


		template <class T, class U, class V = void>
		struct enable_if_is_same :
			std::enable_if<std::is_same<T, U>::value, V>
		{};

		template <class T, class U, class V = void>
		using enable_if_is_same_t = typename enable_if_is_same<T, U, V>::type;


		template <class T, class U, class V = void>
		struct enable_if_is_same_no_cv :
			std::enable_if<is_same_no_cv<T, U>::value, V>
		{};

		template <class T, class U, class V = void>
		using enable_if_is_same_no_cv_t = typename enable_if_is_same_no_cv<T, U, V>::type;


		template <class T, class U, class V = void>
		struct enable_if_is_same_no_cvp :
			std::enable_if<is_same_no_cvp<T, U>::value, V>
		{};

		template <class T, class U, class V = void>
		using enable_if_is_same_no_cvp_t = typename enable_if_is_same_no_cvp<T, U, V>::type;


		template <class T, class U, class V = void>
		struct enable_if_is_same_no_cvr :
			std::enable_if<is_same_no_cvr<T, U>::value, V>
		{};

		template <class T, class U, class V = void>
		using enable_if_is_same_no_cvr_t = typename enable_if_is_same_no_cvr<T, U, V>::type;


		template <class T, class U, class V = void>
		struct enable_if_is_same_no_cvpr :
			std::enable_if<is_same_no_cvpr<T, U>::value, V>
		{};

		template <class T, class U, class V = void>
		using enable_if_is_same_no_cvpr_t = typename enable_if_is_same_no_cvpr<T, U, V>::type;


		namespace
		{
			template <class T>
			struct _is_string :
				std::false_type
			{};

			template <>
			struct _is_string<BSFixedString> :
				std::true_type
			{};
		}

		template <class T>
		struct is_string :
			_is_string<std::remove_cv_t<T>>
		{};

		template <class T>
		struct is_string_no_cvr :
			is_string<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_string_compat :
				std::false_type
			{};

			template <>
			struct _is_string_compat<char*> :
				std::true_type
			{};

			template <>
			struct _is_string_compat<const char*> :
				std::true_type
			{};

			template <>
			struct _is_string_compat<BSFixedString> :
				std::true_type
			{};
		}

		template <class T>
		struct is_string_compat :
			_is_string_compat<remove_cvr_t<T>>
		{};


		template <class T>
		struct is_not_ptr_or_ref :
			std::conjunction<is_not_pointer<std::remove_reference_t<T>>, is_not_reference<std::remove_pointer_t<T>>>
		{};

		template <class T>
		struct is_cref_or_copy :
			std::disjunction<is_cref<T>, is_not_ptr_or_ref<T>>
		{};

		template <class T>
		struct is_string_cref_compat :
			std::conjunction<is_cref_or_copy<T>, is_string_no_cvr<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_sint32 :
				std::false_type
			{};

			template <>
			struct _is_sint32<signed int> :
				std::true_type
			{};

			template <>
			struct _is_sint32<signed long> :
				std::true_type
			{};
		}

		template <class T>
		struct is_sint32 :
			_is_sint32<std::remove_cv_t<T>>
		{};

		template <class T>
		struct is_sint32_no_cvr :
			is_sint32<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_sint32_compat :
				std::conjunction<std::is_signed<T>, is_integer_type<T>>
			{};
		}

		template <class T>
		struct is_sint32_compat :
			_is_sint32_compat<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_uint32 :
				std::false_type
			{};

			template <>
			struct _is_uint32<unsigned int> :
				std::true_type
			{};

			template <>
			struct _is_uint32<unsigned long> :
				std::true_type
			{};
		}

		template <class T>
		struct is_uint32 :
			_is_uint32<std::remove_cv_t<T>>
		{};

		template <class T>
		struct is_uint32_no_cvr :
			is_uint32<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_uint32_compat :
				std::conjunction<std::is_unsigned<T>, is_integer_type<T>>
			{};
		}

		template <class T>
		struct is_uint32_compat :
			_is_uint32_compat<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_float :
				std::false_type
			{};

			template <>
			struct _is_float<float> :
				std::true_type
			{};
		}

		template <class T>
		struct is_float :
			_is_float<std::remove_cv_t<T>>
		{};

		template <class T>
		struct is_float_no_cvr :
			is_float<remove_cvr_t<T>>
		{};


		template <class T>
		struct is_float_compat :
			std::is_floating_point<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T>
			struct _is_bool :
				std::false_type
			{};

			template <>
			struct _is_bool<bool> :
				std::true_type
			{};
		}

		template <class T>
		struct is_bool :
			_is_bool<std::remove_cv_t<T>>
		{};

		template <class T>
		struct is_bool_no_cvr :
			is_bool<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T, class Enable = void>
			struct _is_builtin_type :
				std::false_type
			{};

			template <>
			struct _is_builtin_type<void> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_type<T, std::enable_if_t<is_string<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_type<T, std::enable_if_t<is_sint32<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_type<T, std::enable_if_t<is_uint32<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_type<T, std::enable_if_t<is_float<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_type<T, std::enable_if_t<is_bool<T>::value>> :
				std::true_type
			{};
		}

		template <class T>
		struct is_builtin_type :
			_is_builtin_type<std::remove_cv_t<T>>
		{};

		template <class T>
		struct is_builtin_type_no_cvr :
			is_builtin_type<remove_cvr_t<T>>
		{};


		namespace
		{
			template <class T, class Enable = void>
			struct _is_builtin_compat :
				std::false_type
			{};

			template <>
			struct _is_builtin_compat<void> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_compat<T, std::enable_if_t<is_string_compat<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_compat<T, std::enable_if_t<is_sint32_compat<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_compat<T, std::enable_if_t<is_uint32_compat<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_compat<T, std::enable_if_t<is_float_compat<T>::value>> :
				std::true_type
			{};

			template <class T>
			struct _is_builtin_compat<T, std::enable_if_t<is_bool<T>::value>> :
				std::true_type
			{};
		}

		template <class T>
		struct is_builtin_compat :
			_is_builtin_compat<remove_cvr_t<T>>
		{};


		template <class T>
		struct is_form_type :
			std::is_base_of<TESForm, remove_cvpr_t<T>>
		{};

		template <class T>
		struct is_form_pointer :
			std::conjunction<is_form_type<T>, std::is_pointer<T>>
		{};

		template <class T>
		struct is_form_pointer_no_cvr :
			is_form_pointer<remove_cvr_t<T>>
		{};
	}
}
