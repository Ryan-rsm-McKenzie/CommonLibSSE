#pragma once

#include <tuple>  // tuple
#include <type_traits>
#include <utility>

#include "RE/BSScriptPackUnpack.h"  // GetTypeID, PackValue, UnpackValue
#include "RE/BSScriptStack.h"  // BSScriptStack
#include "RE/BSScriptTypeTraits.h"  // is_static_base
#include "RE/BSScriptVariable.h"  // BSScriptVariable
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/NativeFunctionBase.h"  // NativeFunctionBase
#include "RE/StackFrame.h"  // StackFrame
#include "RE/VirtualMachine.h"  // Internal::VirtualMachine
#include "RE/VMArray.h"  // VMArray


namespace RE
{
	namespace BSScript
	{
		namespace
		{
			template <class F, class Tuple, std::size_t... I, class... Args>
			inline constexpr decltype(auto) CallbackImpl(F&& a_func, Tuple&& a_tuple, std::index_sequence<I...>, Args&&... a_args)
			{
				return std::invoke(std::forward<F>(a_func), std::forward<Args>(a_args)..., std::get<I>(std::forward<Tuple>(a_tuple))...);
			}


			template <class F, class Tuple, class... Args>
			inline constexpr decltype(auto) CallBack(F&& a_func, Tuple&& a_tuple, Args&&... a_args)
			{
				return CallbackImpl(std::forward<F>(a_func), std::forward<Tuple>(a_tuple), make_index_sequence_from_tuple<Tuple>{}, std::forward<Args>(a_args)...);
			}


			template <class... Args, std::size_t... Is>
			std::tuple<Args...> MakeTupleImpl(StackFrame* a_frame, UInt32 a_offset, std::index_sequence<Is...>)
			{
				return std::forward_as_tuple(Args{ a_frame->Get(Is, a_offset)->Unpack<Args>() }...);
			}


			// tuple element construction order isn't guaranteed, so we need to wrap it
			template <class... Args>
			std::tuple<Args...> MakeTuple(StackFrame* a_frame, UInt32 a_offset)
			{
				return MakeTupleImpl<Args...>(a_frame, a_offset, std::make_index_sequence<sizeof...(Args)>{});
			}
		}


		template <bool IS_LONG, class F, class R, class Base, class... Args>
		class NativeFunction : public NF_util::NativeFunctionBase
		{
		public:
			using result_type = R;
			using base_type = Base;
			using function_type = F;
			using FunctionFlag = IVirtualMachine::FunctionFlag;


			NativeFunction() = delete;
			NativeFunction(const NativeFunction&) = delete;
			NativeFunction(NativeFunction&&) = delete;
			NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags);
			virtual ~NativeFunction() = default;																														// 00

			virtual bool HasCallback() const override;																													// 15
			virtual bool Run(BSScriptVariable* a_baseValue, Internal::VirtualMachine* a_vm, UInt32 a_stackID, BSScriptVariable* a_resultValue, StackFrame* a_frame);	// 16

		protected:
			// members
			function_type* _callback;	// 50

		private:
		};


#define TmpltParams_ IS_LONG, F, R, Base, Args...


		template <bool IS_LONG, class F, class R, class Base, class... Args>
		NativeFunction<TmpltParams_>::NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags) :
			NativeFunctionBase(a_fnName, a_className, is_static_base<base_type>::value, sizeof...(Args)),
			_callback(a_callback)
		{
			std::size_t i = 0;
			((_params.data[i++].type.SetTypeID(GetTypeID<Args>())), ...);
			_returnType = GetTypeID<result_type>();
			if (a_flags != FunctionFlag::kNone) {
				Internal::VirtualMachine::GetSingleton()->SetFunctionFlags(a_className, a_fnName, a_flags);
			}
		}


		template <bool IS_LONG, class F, class R, class Base, class... Args>
		bool NativeFunction<TmpltParams_>::HasCallback() const
		{
			return _callback != 0;
		}


		template <bool IS_LONG, class F, class R, class Base, class... Args>
		bool NativeFunction<TmpltParams_>::Run(BSScriptVariable* a_baseValue, Internal::VirtualMachine* a_vm, UInt32 a_stackID, BSScriptVariable* a_resultValue, StackFrame* a_frame)
		{
			auto offset = a_frame->stack->GetOffset(a_frame);

			base_type base{};
			if constexpr (std::negation<is_static_base<base_type>>::value)
			{
				base = a_baseValue->Unpack<base_type>();
				if (!base) {
					return false;
				}
			}

			UInt32 i = sizeof...(Args);
			std::tuple<Args...> args = MakeTuple<Args...>(a_frame, offset);
			if constexpr (std::is_void<result_type>::value)
			{
				if constexpr (IS_LONG)
				{
					CallBack(_callback, std::move(args), a_vm, a_stackID, std::move(base));
					a_resultValue->SetNone();
				} else {
					CallBack(_callback, std::move(args), std::move(base));
					a_resultValue->SetNone();
				}
			} else {
				if constexpr (IS_LONG)
				{
					auto result = CallBack(_callback, std::move(args), a_vm, a_stackID, std::move(base));
					a_resultValue->Pack<result_type>(result);
				} else {
					auto result = CallBack(_callback, std::move(args), std::move(base));
					a_resultValue->Pack<result_type>(result);
				}
			}
			return true;
		}


#undef TmpltParams_
	}


	template <class F, class Enable = void> class NativeFunction;


	template <class R, class Cls, class... Args>
	class NativeFunction<R(Cls, Args...), std::enable_if_t<BSScript::is_valid_short_sig<R, Cls, Args...>::value>> :
		public BSScript::NativeFunction<false, R(Cls, Args...), R, Cls, Args...>
	{
	private:
		using base = BSScript::NativeFunction<false, R(Cls, Args...), R, Cls, Args...>;

	public:
		using result_type = typename base::result_type;
		using base_type = typename base::base_type;
		using function_type = typename base::function_type;
		using FunctionFlag = BSScript::IVirtualMachine::FunctionFlag;


		NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags = FunctionFlag::kNone) :
			base(a_fnName, a_className, a_callback, a_flags)
		{}
	};


	template <class Int, class R, class Cls, class... Args>
	class NativeFunction<R(BSScript::Internal::VirtualMachine*, Int, Cls, Args...), std::enable_if_t<BSScript::is_valid_long_sig<Int, R, Cls, Args...>::value>> :
		public BSScript::NativeFunction<true, R(BSScript::Internal::VirtualMachine*, Int, Cls, Args...), R, Cls, Args...>
	{
	private:
		using base = BSScript::NativeFunction<true, R(BSScript::Internal::VirtualMachine*, Int, Cls, Args...), R, Cls, Args...>;

	public:
		using result_type = typename base::result_type;
		using base_type = typename base::base_type;
		using function_type = typename base::function_type;
		using FunctionFlag = BSScript::IVirtualMachine::FunctionFlag;


		NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags = FunctionFlag::kNone) :
			base(a_fnName, a_className, a_callback, a_flags)
		{}
	};
}
