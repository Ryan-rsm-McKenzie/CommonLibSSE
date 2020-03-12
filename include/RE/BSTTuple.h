#pragma once


namespace RE
{
	template <class T1, class T2>
	struct BSTTuple
	{
	public:
		using first_type = T1;
		using second_type = T2;


		BSTTuple() :
			first{},
			second{}
		{}


		BSTTuple(const BSTTuple&) = default;
		BSTTuple(BSTTuple&&) = default;


		BSTTuple(const T1& a_first, const T2& a_second) :
			first(a_first),
			second(a_second)
		{}


		template <class... Args1, class... Args2, std::size_t... I1, std::size_t... I2>
		BSTTuple(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs, std::index_sequence<I1...>, std::index_sequence<I2...>) :
			first(std::get<I1>(std::move(a_firstArgs))...),
			second(std::get<I2>(std::move(a_secondArgs))...)
		{}


		template <class... Args1, class... Args2>
		BSTTuple(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs) :
			BSTTuple(a_firstArgs, a_secondArgs, std::index_sequence_for<Args1...>(), std::index_sequence_for<Args2...>())
		{}


		BSTTuple& operator=(const BSTTuple& a_rhs)
		{
			first = a_rhs.first;
			second = a_rhs.second;
		}


		BSTTuple& operator=(BSTTuple&& a_rhs)
		{
			first = std::move(a_rhs.first);
			second = std::move(a_rhs.second);
		}


		T1 first;	// 00
		T2 second;	// ??
	};


	template <class T1, class T2>
	BSTTuple<std::decay_t<T1>, std::decay_t<T2>> make_pair(T1&& a_first, T2&& a_second)
	{
		return { std::forward<T1>(a_first), std::forward<T2>(a_second) };
	}
}
