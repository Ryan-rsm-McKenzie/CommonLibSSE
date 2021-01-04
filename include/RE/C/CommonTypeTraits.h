#pragma once

#include "RE/A/ActiveEffect.h"
#include "RE/B/BGSBaseAlias.h"
#include "RE/B/BSFixedString.h"
#include "RE/T/TESForm.h"

namespace RE
{
	namespace BSScript
	{
		template <class T>
		struct is_not_const :
			std::negation<
				std::is_const<T>>
		{};

		template <class T>
		inline constexpr bool is_not_const_v = is_not_const<T>::value;

		template <class T>
		struct is_not_volatile :
			std::negation<
				std::is_volatile<T>>
		{};

		template <class T>
		inline constexpr bool is_not_volatile_v = is_not_volatile<T>::value;

		template <class T>
		struct is_not_reference :
			std::negation<
				std::is_reference<T>>
		{};

		template <class T>
		inline constexpr bool is_not_reference_v = is_not_reference<T>::value;

		template <class T>
		struct is_not_pointer :
			std::negation<
				std::is_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_not_pointer_v = is_not_pointer<T>::value;

		template <class, class = void>
		struct defines_value_type :
			std::false_type
		{};

		template <class T>
		struct defines_value_type<
			T,
			std::void_t<
				typename T::value_type>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool defines_value_type_v = defines_value_type<T>::value;

		template <class, class = void>
		struct defines_size_type :
			std::false_type
		{};

		template <class T>
		struct defines_size_type<
			T,
			std::void_t<
				typename T::size_type>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool defines_size_type_v = defines_size_type<T>::value;

		template <class, class = void>
		struct defines_iterator :
			std::false_type
		{};

		template <class T>
		struct defines_iterator<
			T,
			std::void_t<
				typename T::iterator>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool defines_iterator_v = defines_iterator<T>::value;

		template <class, class = void>
		struct implements_begin :
			std::false_type
		{};

		template <class T>
		struct implements_begin<
			T,
			std::enable_if_t<
				std::is_same_v<
					typename T::iterator,
					decltype(std::declval<T>().begin())>>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool implements_begin_v = implements_begin<T>::value;

		template <class, class = void>
		struct implements_end :
			std::false_type
		{};

		template <class T>
		struct implements_end<
			T,
			std::enable_if_t<
				std::is_same_v<
					typename T::iterator,
					decltype(std::declval<T>().end())>>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool implements_end_v = implements_end<T>::value;

		template <class, class = void>
		struct implements_size :
			std::false_type
		{};

		template <class T>
		struct implements_size<
			T,
			std::enable_if_t<
				std::is_invocable_r_v<
					typename T::size_type,
					decltype(&T::size),
					T>>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool implements_size_v = implements_size<T>::value;

		template <class, class = void>
		struct implements_push_back :
			std::false_type
		{};

		template <class T>
		struct implements_push_back<
			T,
			std::void_t<
				decltype(std::declval<T>().push_back(std::declval<typename T::value_type>()))>> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool implements_push_back_v = implements_push_back<T>::value;

		template <class T>
		struct _is_integer :
			std::is_integral<T>
		{};

		template <>
		struct _is_integer<bool> :
			std::false_type
		{};

		template <class T>
		struct is_integer :
			_is_integer<
				std::remove_cv_t<T>>
		{};

		template <class T>
		inline constexpr bool is_integer_v = is_integer<T>::value;

		template <class T>
		struct index_sequence_for_tuple :
			std::make_index_sequence<
				std::tuple_size_v<
					std::decay_t<T>>>
		{};

		template <class T>
		struct decay_pointer :
			std::decay_t<
				std::remove_pointer<T>>
		{};

		template <class T>
		using decay_pointer_t = typename decay_pointer<T>::type;

		template <class T>
		struct is_string :
			std::is_same<
				std::remove_cv_t<T>,
				BSFixedString>
		{};

		template <class T>
		inline constexpr bool is_string_v = is_string<T>::value;

		template <class T>
		struct is_signed_integral :
			std::conjunction<
				is_integer<T>,
				std::is_signed<T>,
				std::bool_constant<sizeof(T) == 4>>
		{};

		template <class T>
		inline constexpr bool is_signed_integral_v = is_signed_integral<T>::value;

		template <class T>
		struct is_unsigned_integral :
			std::conjunction<
				is_integer<T>,
				std::is_unsigned<T>,
				std::bool_constant<sizeof(T) == 4>>
		{};

		template <class T>
		inline constexpr bool is_unsigned_integral_v = is_unsigned_integral<T>::value;

		template <class T>
		struct is_integral :
			std::disjunction<
				is_signed_integral<T>,
				is_unsigned_integral<T>>
		{};

		template <class T>
		inline constexpr bool is_integral_v = is_integral<T>::value;

		template <class T>
		struct is_floating_point :
			std::is_same<
				std::remove_cv_t<T>,
				float>
		{};

		template <class T>
		inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

		template <class T>
		struct is_boolean :
			std::is_same<
				std::remove_cv_t<T>,
				bool>
		{};

		template <class T>
		inline constexpr bool is_boolean_v = is_boolean<T>::value;

		template <class T>
		struct is_builtin :
			std::disjunction<
				std::is_void<T>,
				is_string<T>,
				is_signed_integral<T>,
				is_unsigned_integral<T>,
				is_floating_point<T>,
				is_boolean<T>>
		{};

		template <class T>
		inline constexpr bool is_builtin_v = is_builtin<T>::value;

		template <class T>
		struct is_string_convertible :
			std::is_convertible<T, std::string_view>
		{};

		template <class T>
		inline constexpr bool is_string_convertible_v = is_string_convertible<T>::value;

		template <class T, class = void>
		struct is_signed_integral_convertible :
			std::conjunction<
				is_integer<T>,
				std::is_signed<T>>
		{};

		template <class T>
		struct is_signed_integral_convertible<
			T,
			std::enable_if_t<
				std::is_enum_v<T>>> :
			std::is_signed<
				std::underlying_type_t<T>>
		{};

		template <class T>
		inline constexpr bool is_signed_integral_convertible_v = is_signed_integral_convertible<T>::value;

		template <class T, class = void>
		struct is_unsigned_integral_convertible :
			std::conjunction<
				is_integer<T>,
				std::is_unsigned<T>>
		{};

		template <class T>
		struct is_unsigned_integral_convertible<
			T,
			std::enable_if_t<
				std::is_enum_v<T>>> :
			std::is_unsigned<
				std::underlying_type_t<T>>
		{};

		template <class T>
		inline constexpr bool is_unsigned_integral_convertible_v = is_unsigned_integral_convertible<T>::value;

		template <class T>
		struct is_integral_convertible :
			std::disjunction<
				is_signed_integral_convertible<T>,
				is_unsigned_integral_convertible<T>>
		{};

		template <class T>
		inline constexpr bool is_integral_convertible_v = is_integral_convertible<T>::value;

		template <class T>
		struct is_floating_point_convertible :
			std::is_floating_point<T>
		{};

		template <class T>
		inline constexpr bool is_floating_point_convertible_v = is_floating_point_convertible<T>::value;

		template <class T>
		struct is_builtin_convertible :
			std::disjunction<
				std::is_void<T>,
				is_string_convertible<T>,
				is_signed_integral_convertible<T>,
				is_unsigned_integral_convertible<T>,
				is_floating_point_convertible<T>,
				is_boolean<T>>
		{};

		template <class T>
		inline constexpr bool is_builtin_convertible_v = is_builtin_convertible<T>::value;

		template <class T>
		struct is_form :
			std::is_base_of<
				RE::TESForm,
				std::remove_cv_t<T>>
		{};

		template <class T>
		inline constexpr bool is_form_v = is_form<T>::value;

		template <class T>
		struct is_form_pointer :
			std::conjunction<
				is_form<
					std::remove_pointer_t<T>>,
				std::is_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_form_pointer_v = is_form_pointer<T>::value;

		template <class T>
		struct is_alias :
			std::is_base_of<
				RE::BGSBaseAlias,
				std::remove_cv_t<T>>
		{};

		template <class T>
		inline constexpr bool is_alias_v = is_alias<T>::value;

		template <class T>
		struct is_alias_pointer :
			std::conjunction<
				is_alias<
					std::remove_pointer_t<T>>,
				std::is_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_alias_pointer_v = is_alias_pointer<T>::value;

		template <class T>
		struct is_active_effect :
			std::is_base_of<
				RE::ActiveEffect,
				std::remove_cv_t<T>>
		{};

		template <class T>
		inline constexpr bool is_active_effect_v = is_active_effect<T>::value;

		template <class T>
		struct is_active_effect_pointer :
			std::conjunction<
				is_active_effect<
					std::remove_pointer_t<T>>,
				std::is_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_active_effect_pointer_v = is_active_effect_pointer<T>::value;

		template <class T>
		struct _is_array :
			std::conjunction<
				std::negation<
					is_string_convertible<T>>,
				std::is_default_constructible<T>,
				std::is_destructible<T>,
				is_not_reference<T>,
				is_not_pointer<T>,
				defines_value_type<T>,
				defines_size_type<T>,
				defines_iterator<T>,
				implements_begin<T>,
				implements_end<T>,
				implements_size<T>,
				implements_push_back<T>>
		{};

		template <>
		struct _is_array<
			std::vector<bool>> :
			std::true_type
		{};

		template <class T>
		struct is_array :
			_is_array<
				std::remove_cv_t<T>>
		{};

		template <class T>
		inline constexpr bool is_array_v = is_array<T>::value;
	}
}
