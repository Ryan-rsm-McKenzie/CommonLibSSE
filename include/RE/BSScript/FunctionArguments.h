#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

#include "RE/BSScript/TypeTraits.h"
#include "RE/BSScript/IFunctionArguments.h"  // BSScript::IFunctionArguments
#include "RE/BSScript/ZeroFunctionArguments.h"  // BSScript::ZeroFunctionArguments


namespace RE
{
	namespace BSScript
	{
		template <class... Args, std::size_t... I>
		void CopyArgsImpl(std::tuple<Args...>& a_tuple, BSScrapArray<Variable>& a_dst, std::index_sequence<I...>)
		{
			((a_dst[I].Pack<Args>(std::get<I>(a_tuple))), ...);
		}


		template <class... Args>
		void CopyArgs(std::tuple<Args...>& a_tuple, BSScrapArray<Variable>& a_dst)
		{
			CopyArgsImpl(a_tuple, a_dst, std::index_sequence_for<Args...>{});
		}


		template <class Enable, class... Args> class FunctionArguments;


		template <class... Args>
		class FunctionArguments<std::enable_if_t<std::conjunction<is_param_compat<Args>...>::value>, Args...> :
			public IFunctionArguments
		{
		public:
			FunctionArguments(Args&&... a_args) :
				_args(std::forward<Args>(a_args)...)
			{}


			FunctionArguments()
			{}


			FunctionArguments(const FunctionArguments& a_rhs) :
				_args(a_rhs._args)
			{}


			FunctionArguments(FunctionArguments&& a_rhs) :
				_args(std::move(a_rhs._args))
			{}


			virtual ~FunctionArguments() = default;						// 00


			virtual bool Copy(BSScrapArray<Variable>& a_dst) override	// 01
			{
				ResizeArguments(a_dst, sizeof...(Args));
				CopyArgs(_args, a_dst);
				return true;
			}

		protected:
			std::tuple<Args...> _args;
		};
	}


	template <class... Args>
	using FunctionArguments = BSScript::FunctionArguments<void, Args...>;


	template <class... Args>
	inline BSScript::IFunctionArguments* MakeFunctionArguments(Args&&... a_args)
	{
		return new FunctionArguments<Args...>(std::forward<Args>(a_args)...);
	}


	template <>
	inline BSScript::IFunctionArguments* MakeFunctionArguments()
	{
		return new BSScript::ZeroFunctionArguments();
	}
}
