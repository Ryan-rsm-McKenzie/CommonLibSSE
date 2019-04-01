#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

#include "RE/BSScriptTypeTraits.h"
#include "RE/IFunctionArguments.h"  // IFunctionArguments


namespace RE
{
	namespace BSScript
	{
		template <class... Args, std::size_t... Is>
		void CopyArgsImpl(std::tuple<Args...>& a_tuple, BSScrapArray<BSScriptVariable>& a_dst, std::index_sequence<Is...>)
		{
			((a_dst[Is].SetData<Args>(std::get<Is>(a_tuple))), ...);
		}


		template <class... Args>
		void CopyArgs(std::tuple<Args...>& a_tuple, BSScrapArray<BSScriptVariable>& a_dst)
		{
			CopyArgsImpl(a_tuple, a_dst, std::index_sequence_for<Args...>{});
		}


		template <class Enable, class... Args> class FunctionArguments;


#define TmpltParams_ std::enable_if_t<std::conjunction<is_param_compat<Args>...>::value>, Args...


		template <class... Args>
		class FunctionArguments<TmpltParams_>
			: public IFunctionArguments
		{
		public:
			FunctionArguments(Args... a_args);
			FunctionArguments();
			FunctionArguments(const FunctionArguments& a_rhs);
			FunctionArguments(FunctionArguments&& a_rhs);
			virtual ~FunctionArguments();										// 00

			virtual bool Copy(BSScrapArray<BSScriptVariable>& a_dst) override;	// 01

		protected:
			std::tuple<Args...> _args;
		};


		template <class... Args>
		FunctionArguments<TmpltParams_>::FunctionArguments(Args... a_args) :
			_args(a_args...)
		{}


		template <class... Args>
		FunctionArguments<TmpltParams_>::FunctionArguments()
		{}


		template <class... Args>
		FunctionArguments<TmpltParams_>::FunctionArguments(const FunctionArguments& a_rhs) :
			_args(a_rhs._args)
		{}


		template <class... Args>
		FunctionArguments<TmpltParams_>::FunctionArguments(FunctionArguments&& a_rhs) :
			_args(std::move(a_rhs._args))
		{}


		template <class... Args>
		FunctionArguments<TmpltParams_>::~FunctionArguments()
		{}


		template <class... Args>
		bool FunctionArguments<TmpltParams_>::Copy(BSScrapArray<BSScriptVariable>& a_dst)
		{
			ResizeArguments(a_dst, sizeof...(Args));
			CopyArgs(_args, a_dst);
			return true;
		}


#undef TmpltParams_
	}


	template <class... Args>
	using FunctionArguments = BSScript::FunctionArguments<void, Args...>;


	template <class... Args>
	FunctionArguments<Args...>* MakeFunctionArguments(Args... a_args)
	{
		return new FunctionArguments<Args...>{ a_args... };
	}
}
