#pragma once

namespace RE
{
	template <class T1, class T2>
	struct BSTTuple
	{
	public:
		using first_type = T1;
		using second_type = T2;

		// 1
		template <
			class U1 = first_type,
			class U2 = second_type,
			std::enable_if_t<
				std::conjunction_v<
					std::is_default_constructible<U1>,
					std::is_default_constructible<U2>>,
				int> = 0>
		inline BSTTuple() :
			first{},
			second{}
		{}

		// 2
		template <
			class U1 = first_type,
			class U2 = second_type,
			std::enable_if_t<
				std::conjunction_v<
					std::is_copy_constructible<U1>,
					std::is_copy_constructible<U2>>,
				int> = 0>
		inline explicit(
			std::disjunction_v<
				std::negation<
					std::is_convertible<const first_type&, first_type>>,
				std::negation<
					std::is_convertible<const second_type&, second_type>>>)
			BSTTuple(const first_type& a_first, const second_type& a_second) :
			first{ a_first },
			second{ a_second }
		{}

		// 3
		template <
			class U1,
			class U2,
			std::enable_if_t<
				std::conjunction_v<
					std::is_constructible<first_type, U1&&>,
					std::is_constructible<second_type, U2&&>>,
				int> = 0>
		inline explicit(
			std::disjunction_v<
				std::negation<
					std::is_convertible<U1&&, first_type>>,
				std::negation<
					std::is_convertible<U2&&, second_type>>>)
			BSTTuple(U1&& a_first, U2&& a_second) :
			first{ std::forward<U1>(a_first) },
			second{ std::forward<U2>(a_second) }
		{}

		// 4
		template <
			class U1,
			class U2,
			std::enable_if_t<
				std::conjunction_v<
					std::is_constructible<first_type, const U1&>,
					std::is_constructible<second_type, const U2&>>,
				int> = 0>
		inline explicit(
			std::disjunction_v<
				std::negation<
					std::is_convertible<const U1&, first_type>>,
				std::negation<
					std::is_convertible<const U2&, second_type>>>)
			BSTTuple(const BSTTuple<U1, U2>& a_rhs) :
			first{ a_rhs.first },
			second{ a_rhs.second }
		{}

		// 5
		template <
			class U1,
			class U2,
			std::enable_if_t<
				std::conjunction_v<
					std::is_constructible<first_type, U1&&>,
					std::is_constructible<second_type, U2&&>>,
				int> = 0>
		inline explicit(
			std::disjunction_v<
				std::negation<
					std::is_convertible<U1&&, first_type>>,
				std::negation<
					std::is_convertible<U2&&, second_type>>>)
			BSTTuple(BSTTuple<U1, U2>&& a_rhs) :
			first{ std::forward<U1>(a_rhs.first) },
			second{ std::forward<U2>(a_rhs.second) }
		{}

		// 6
		template <
			class... Args1,
			class... Args2>
		inline BSTTuple(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs) :
			BSTTuple(a_firstArgs, a_secondArgs, std::index_sequence_for<Args1...>(), std::index_sequence_for<Args2...>())
		{}

		// 6-impl
		template <
			class... Args1,
			class... Args2,
			std::size_t... I1,
			std::size_t... I2>
		inline BSTTuple(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs, std::index_sequence<I1...>, std::index_sequence<I2...>) :
			first{ std::get<I1>(std::move(a_firstArgs))... },
			second{ std::get<I2>(std::move(a_secondArgs))... }
		{}

		// 7
		BSTTuple(const BSTTuple&) = default;

		// 8
		BSTTuple(BSTTuple&&) = default;

		// 1
		template <
			class U1 = first_type,
			class U2 = second_type,
			std::enable_if_t<
				std::conjunction_v<
					std::is_copy_assignable<U1>,
					std::is_copy_assignable<U2>>,
				int> = 0>
		inline BSTTuple& operator=(const BSTTuple& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				first = a_rhs.first;
				second = a_rhs.second;
			}
			return *this;
		}

		// 2
		template <
			class U1,
			class U2,
			std::enable_if_t<
				std::conjunction_v<
					std::is_assignable<first_type&, const U1&>,
					std::is_assignable<second_type&, const U2&>>,
				int> = 0>
		inline BSTTuple& operator=(const BSTTuple<U1, U2>& a_rhs)
		{
			first = a_rhs.first;
			second = a_rhs.second;
			return *this;
		}

		// 3
		template <
			class U1 = first_type,
			class U2 = second_type,
			std::enable_if_t<
				std::conjunction_v<
					std::is_move_assignable<U1>,
					std::is_move_assignable<U2>>,
				int> = 0>
		inline BSTTuple& operator=(BSTTuple&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				first = std::move(a_rhs.first);
				second = std::move(a_rhs.second);
			}
			return *this;
		}

		// 4
		template <
			class U1,
			class U2,
			std::enable_if_t<
				std::conjunction_v<
					std::is_assignable<first_type&, U1&&>,
					std::is_assignable<second_type&, U2&&>>,
				int> = 0>
		inline BSTTuple& operator=(BSTTuple<U1, U2>&& a_rhs)
		{
			first = std::move(a_rhs.first);
			second = std::move(a_rhs.second);
			return *this;
		}

		inline void swap(BSTTuple& a_rhs)
		{
			using std::swap;
			swap(first, a_rhs.first);
			swap(second, a_rhs.second);
		}

		// members
		T1 first;	// 00
		T2 second;	// ??
	};

	template <
		class T1,
		class T2>
	[[nodiscard]] inline BSTTuple<
		std::decay_t<T1>,
		std::decay_t<T2>>
		make_pair(T1&& a_first, T2&& a_second)
	{
		using result_t =
			BSTTuple<
				std::decay_t<T1>,
				std::decay_t<T2>>;
		return result_t{ std::forward<T1>(a_first), std::forward<T2>(a_second) };
	}

	template <
		class T1,
		class T2>
	[[nodiscard]] inline BSTTuple<
		std::decay_t<T1>,
		std::decay_t<T2>>
		make_tuple(T1&& a_first, T2&& a_second)
	{
		using result_t =
			BSTTuple<
				std::decay_t<T1>,
				std::decay_t<T2>>;
		return result_t{ std::forward<T1>(a_first), std::forward<T2>(a_second) };
	}

	template <class T1, class T2>
	inline void swap(BSTTuple<T1, T2>& a_lhs, BSTTuple<T1, T2>& a_rhs)
	{
		a_lhs.swap(a_rhs);
	}

	template <class T1, class T2>
	BSTTuple(T1, T2) -> BSTTuple<T1, T2>;
}
