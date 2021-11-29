#pragma once

#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESObjectREFR.h"

namespace SKSE
{
	namespace Impl
	{
		template <class T>
		using is_object_pointer = std::is_convertible<std::decay_t<T>, RE::TESObjectREFR*>;

		template <class T>
		inline constexpr bool is_object_pointer_v = is_object_pointer<T>::value;

		template <class T>
		using is_not_object_pointer = std::negation<is_object_pointer<T>>;

		template <class T>
		inline constexpr bool is_not_object_pointer_v = is_not_object_pointer<T>::value;

		template <class T>
		using is_form_pointer = std::is_convertible<std::decay_t<T>, RE::TESForm*>;

		template <class T>
		inline constexpr bool is_form_pointer_v = is_form_pointer<T>::value;

		template <class T>
		using is_not_form_pointer = std::negation<is_form_pointer<T>>;

		template <class T>
		inline constexpr bool is_not_form_pointer_v = is_not_form_pointer<T>::value;

		template <class T>
		struct index_sequence_for_tuple :
			std::make_index_sequence<
				std::tuple_size_v<
					std::decay_t<T>>>
		{};

		// default
		template <class T, class = void>
		class VMArg
		{
		public:
			using value_type = std::decay_t<T>;

			VMArg() :
				_arg{}
			{}

			template <class U, std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, int> = 0>
			VMArg(U&& a_arg) :
				_arg{ std::forward<U>(a_arg) }
			{}

			~VMArg() = default;

			template <class U, std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, int> = 0>
			void Pack(U&& a_arg)
			{
				_arg = std::forward<U>(a_arg);
			}

			value_type Unpack()
			{
				return value_type{ std::move(_arg) };
			}

		private:
			T _arg;
		};

		// forms
		template <class T>
		class VMArg<
			T,
			std::enable_if_t<
				std::conjunction_v<
					is_form_pointer<T>,
					is_not_object_pointer<T>>>>
		{
		public:
			using value_type = std::decay_t<T>;

			VMArg() :
				_formID(static_cast<RE::FormID>(0))
			{}

			template <class U, std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, int> = 0>
			VMArg(U&& a_arg) :
				VMArg()
			{
				Pack(std::forward<U>(a_arg));
			}

			~VMArg() = default;

			template <class U, std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, int> = 0>
			void Pack(U&& a_arg)
			{
				if (a_arg) {
					_formID = a_arg->GetFormID();
				}
			}

			value_type Unpack()
			{
				return static_cast<value_type>(RE::TESForm::LookupByID(_formID));
			}

		private:
			RE::FormID _formID;
		};

		// objects
		template <class T>
		class VMArg<
			T,
			std::enable_if_t<
				is_object_pointer_v<T>>>
		{
		public:
			using value_type = std::decay_t<T>;

			VMArg() :
				_object(nullptr)
			{}

			template <class U, std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, int> = 0>
			VMArg(U&& a_arg) :
				VMArg()
			{
				Pack(std::forward<U>(a_arg));
			}

			~VMArg() = default;

			template <class U, std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, int> = 0>
			void Pack(U&& a_arg)
			{
				_object.reset(a_arg);
			}

			value_type Unpack()
			{
				return _object.get();
			}

		private:
			RE::NiPointer<std::remove_pointer_t<value_type>> _object;
		};

		template <class T>
		VMArg(T&&) -> VMArg<T>;
	}
}
