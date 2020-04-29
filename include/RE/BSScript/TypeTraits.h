#pragma once

#include <type_traits>

#include "RE/BSScript/CommonTypeTraits.h"
#include "RE/BSScript/TypeInfo.h"


namespace RE
{
	struct StaticFunctionTag
	{};


	namespace BSScript
	{
		template <class T, class = void>
		struct _unwrapped_type
		{
			using type = decay_pointer_t<T>;
		};

		template <class T>
		struct _unwrapped_type<T, std::enable_if_t<is_array_v<T>>>
		{
			using type = decay_pointer_t<typename T::value_type>;
		};

		template <class T>
		struct unwrapped_type :
			_unwrapped_type<
				std::remove_cv_t<T>>
		{};

		template <class T>
		using unwrapped_type_t = typename unwrapped_type<T>::type;


		template <TypeInfo::RawType V>
		struct vm_type_constant :
			std::integral_constant<TypeInfo::RawType, V>
		{};


		template <class, class = void>
		struct _vm_type;

		template <>
		struct _vm_type<void> :
			vm_type_constant<TypeInfo::RawType::kNone>
		{};

		template <class T>
		struct _vm_type<T, std::enable_if_t<is_string_convertible_v<T>>> :
			vm_type_constant<TypeInfo::RawType::kString>
		{};

		template <class T>
		struct _vm_type<T, std::enable_if_t<is_integral_convertible_v<T>>> :
			vm_type_constant<TypeInfo::RawType::kInt>
		{};

		template <class T>
		struct _vm_type<T, std::enable_if_t<is_floating_point_convertible_v<T>>> :
			vm_type_constant<TypeInfo::RawType::kFloat>
		{};

		template <class T>
		struct _vm_type<T, std::enable_if_t<is_boolean_v<T>>> :
			vm_type_constant<TypeInfo::RawType::kBool>
		{};

		template <class T>
		struct vm_type :
			_vm_type<
				unwrapped_type_t<T>>
		{};

		template <class T>
		inline constexpr TypeInfo::RawType vm_type_v = vm_type<T>::value;


		template <class T>
		struct is_static_base :
			std::is_same<
				decay_pointer_t<T>,
				StaticFunctionTag>
		{};

		template <class T>
		inline constexpr bool is_static_base_v = is_static_base<T>::value;


		template <class T>
		struct is_static_base_pointer :
			std::conjunction<
				is_static_base<T>,
				std::is_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_static_base_pointer_v = is_static_base_pointer<T>::value;


		template <class T>
		struct is_valid_base :
			std::disjunction<
				is_static_base_pointer<T>,
				is_form_pointer<T>>
		{};

		template <class T>
		inline constexpr bool is_valid_base_v = is_valid_base<T>::value;


		template <class T>
		struct is_valid_parameter :
			std::conjunction<
				is_not_reference<T>,
				is_not_volatile<T>,
				std::disjunction<
					is_builtin<T>,
					is_form_pointer<T>,
					is_array<T>>>
		{};

		template <class T>
		inline constexpr bool is_valid_parameter_v = is_valid_parameter<T>::value;


		template <class T>
		struct is_parameter_convertible :
			std::conjunction<
				is_not_reference<T>,
				is_not_volatile<T>,
				std::disjunction<
					is_builtin_convertible<T>,
					is_form_pointer<T>,
					is_array<T>>>
		{};

		template <class T>
		inline constexpr bool is_parameter_convertible_v = is_parameter_convertible<T>::value;


		template <class T>
		struct is_valid_return :
			std::conjunction<
				is_not_const<T>,
				is_valid_parameter<T>>
		{};

		template <class T>
		inline constexpr bool is_valid_return_v = is_valid_return<T>::value;


		template <class T>
		struct is_return_convertible :
			std::conjunction<
				is_not_const<T>,
				is_parameter_convertible<T>>
		{};

		template <class T>
		inline constexpr bool is_return_convertible_v = is_return_convertible<T>::value;


		template <class R, class Cls, class... Args>
		struct is_valid_short_sig :
			std::conjunction<
				is_return_convertible<R>,
				is_valid_base<Cls>,
				is_parameter_convertible<Args>...>
		{};

		template <class R, class Cls, class... Args>
		inline constexpr bool is_valid_short_sig_v = is_valid_short_sig<R, Cls, Args...>::value;


		template <class Int, class R, class Cls, class... Args>
		struct is_valid_long_sig :
			std::conjunction<
				is_integral<Int>,
				is_valid_short_sig<R, Cls, Args...>>
		{};

		template <class Int, class R, class Cls, class... Args>
		inline constexpr bool is_valid_long_sig_v = is_valid_long_sig<Int, R, Cls, Args...>::value;
	}
}
