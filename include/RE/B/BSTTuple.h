#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class T1, class T2>
	struct BSTTuple
	{
	public:
		using first_type = T1;
		using second_type = T2;

		// 1)
		BSTTuple()  //
			noexcept(std::is_nothrow_default_constructible_v<first_type>&&
					std::is_nothrow_default_constructible_v<second_type>)  //
			requires(std::is_default_constructible_v<first_type>&&
					std::is_default_constructible_v<second_type>) :
			first(),
			second()
		{}

		// 2)
		explicit(!std::is_convertible_v<const first_type&, first_type> ||
				 !std::is_convertible_v<const second_type&, second_type>)     //
			BSTTuple(const first_type& a_first, const second_type& a_second)  //
			noexcept(std::is_nothrow_copy_constructible_v<first_type>&&
					std::is_nothrow_copy_constructible_v<second_type>)  //
			requires(std::is_copy_constructible_v<first_type>&&
					std::is_copy_constructible_v<second_type>) :
			first(a_first),
			second(a_second)
		{}

		// 3)
		template <class U1, class U2>
		explicit(!std::is_convertible_v<U1&&, first_type> ||
				 !std::is_convertible_v<U2&&, second_type>)  //
			BSTTuple(U1&& a_first, U2&& a_second)            //
			noexcept(std::is_nothrow_constructible_v<first_type, U1&&>&&
					std::is_nothrow_constructible_v<second_type, U2&&>)  //
			requires(std::is_constructible_v<first_type, U1&&>&&
					std::is_constructible_v<second_type, U2&&>) :
			first(std::forward<U1>(a_first)),
			second(std::forward<U2>(a_second))
		{}

		// 4)
		template <class U1, class U2>
		explicit(!std::is_convertible_v<const U1&, first_type> ||
				 !std::is_convertible_v<const U2&, second_type>)  //
			BSTTuple(const BSTTuple<U1, U2>& a_rhs)               //
			noexcept(std::is_nothrow_constructible_v<first_type, const U1&>&&
					std::is_nothrow_constructible_v<second_type, const U2&>)  //
			requires(std::is_constructible_v<first_type, const U1&>&&
					std::is_constructible_v<second_type, const U2&>) :
			first(a_rhs.first),
			second(a_rhs.second)
		{}

		// 5)
		template <class U1, class U2>
		explicit(!std::is_convertible_v<U1&&, first_type> ||
				 !std::is_convertible_v<U2&&, second_type>)  //
			BSTTuple(BSTTuple<U1, U2>&& a_rhs)               //
			noexcept(std::is_nothrow_constructible_v<first_type, U1&&>&&
					std::is_nothrow_constructible_v<second_type, U2&&>)  //
			requires(std::is_constructible_v<first_type, U1&&>&&
					std::is_constructible_v<second_type, U2&&>) :
			first(std::forward<U1>(a_rhs.first)),
			second(std::forward<U2>(a_rhs.second))
		{}

		// 6)
		template <
			class... Args1,
			class... Args2>
		BSTTuple(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs) :
			BSTTuple(a_firstArgs, a_secondArgs, std::index_sequence_for<Args1...>(), std::index_sequence_for<Args2...>())
		{}

	private:
		// 6) impl
		template <
			class Tuple1,
			class Tuple2,
			std::size_t... I1,
			std::size_t... I2>
		BSTTuple(Tuple1& a_firstArgs, Tuple2& a_secondArgs, std::index_sequence<I1...>, std::index_sequence<I2...>) :
			first(std::get<I1>(std::move(a_firstArgs))...),
			second(std::get<I2>(std::move(a_secondArgs))...)
		{}

	public:
		// 7)
		BSTTuple(const BSTTuple&) = default;

		// 8)
		BSTTuple(BSTTuple&&) = default;

		~BSTTuple() = default;

		// 1)
		BSTTuple& operator=(const BSTTuple& a_rhs)  //
			noexcept(std::is_nothrow_copy_assignable_v<first_type>&&
					std::is_nothrow_copy_assignable_v<second_type>)  //
			requires(std::is_copy_assignable_v<first_type>&&
					std::is_copy_assignable_v<second_type>)
		{
			if (this != std::addressof(a_rhs)) {
				first = a_rhs.first;
				second = a_rhs.second;
			}
			return *this;
		}

		// 2)
		template <class U1, class U2>
		BSTTuple& operator=(const BSTTuple<U1, U2>& a_rhs)  //
			noexcept(std::is_nothrow_assignable_v<first_type&, const U1&>&&
					std::is_nothrow_assignable_v<second_type&, const U2&>)  //
			requires(std::is_assignable_v<first_type&, const U1&>&&
					std::is_assignable_v<second_type&, const U2&>)
		{
			first = a_rhs.first;
			second = a_rhs.second;
			return *this;
		}

		// 3)
		BSTTuple& operator=(BSTTuple&& a_rhs)  //
			noexcept(std::is_nothrow_move_assignable_v<first_type>&&
					std::is_nothrow_move_assignable_v<second_type>)  //
			requires(std::is_move_assignable_v<first_type>&&
					std::is_move_assignable_v<second_type>)
		{
			if (this != std::addressof(a_rhs)) {
				first = std::move(a_rhs.first);
				second = std::move(a_rhs.second);
			}
			return *this;
		}

		// 4)
		template <class U1, class U2>
		BSTTuple& operator=(BSTTuple<U1, U2>&& a_rhs)  //
			noexcept(std::is_nothrow_assignable_v<first_type&, U1>&&
					std::is_nothrow_assignable_v<second_type&, U2>)  //
			requires(std::is_assignable_v<first_type&, U1>&&
					std::is_assignable_v<second_type&, U2>)
		{
			first = std::move(a_rhs.first);
			second = std::move(a_rhs.second);
			return *this;
		}

		TES_HEAP_REDEFINE_NEW();

		void swap(BSTTuple& a_rhs)  //
			noexcept(std::is_nothrow_swappable_v<first_type>&&
					std::is_nothrow_swappable_v<second_type>)
		{
			using std::swap;
			if (this != std::addressof(a_rhs)) {
				swap(first, a_rhs.first);
				swap(second, a_rhs.second);
			}
		}

		// members
		first_type  first;   // 00
		second_type second;  // ??
	};

	template <class T1, class T2>
	[[nodiscard]] auto make_pair(T1&& a_first, T2&& a_second)
	{
		using result_t =
			BSTTuple<
				std::decay_t<T1>,
				std::decay_t<T2>>;
		return result_t(std::forward<T1>(a_first), std::forward<T2>(a_second));
	}

	template <class T1, class T2>
	[[nodiscard]] auto make_tuple(T1&& a_first, T2&& a_second)
	{
		using result_t =
			BSTTuple<
				std::decay_t<T1>,
				std::decay_t<T2>>;
		return result_t(std::forward<T1>(a_first), std::forward<T2>(a_second));
	}

	template <class T1, class T2>
	[[nodiscard]] bool operator==(const BSTTuple<T1, T2>& a_lhs, const BSTTuple<T1, T2>& a_rhs)
	{
		return a_lhs.first == a_rhs.first && a_lhs.second == a_rhs.second;
	}

	template <class T1, class T2>
	[[nodiscard]] bool operator<(const BSTTuple<T1, T2>& a_lhs, const BSTTuple<T1, T2>& a_rhs)
	{
		return a_lhs.first < a_rhs.first   ? true :
		       a_rhs.first < a_lhs.first   ? false :
		       a_lhs.second < a_rhs.second ? true :
                                             false;
	}

	template <class T1, class T2>
	void swap(BSTTuple<T1, T2>& a_lhs, BSTTuple<T1, T2>& a_rhs)  //
		noexcept(noexcept(a_lhs.swap(a_rhs)))                    //
		requires(std::is_swappable_v<T1>&&
				std::is_swappable_v<T2>)
	{
		a_lhs.swap(a_rhs);
	}

	template <class T1, class T2>
	BSTTuple(T1, T2) -> BSTTuple<T1, T2>;
}
