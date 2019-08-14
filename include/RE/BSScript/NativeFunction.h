#pragma once

#include <tuple>  // tuple
#include <type_traits>
#include <utility>

#include "RE/BSScript/Internal/VirtualMachine.h"  // BSScript::Internal::VirtualMachine
#include "RE/BSScript/NF_util/NativeFunctionBase.h"  // BSScript::NF_util::NativeFunctionBase
#include "RE/BSScript/PackUnpack.h"  // GetTypeID, PackValue, UnpackValue
#include "RE/BSScript/Stack.h"  // BSScript::Stack
#include "RE/BSScript/TypeTraits.h"  // BSScript::is_static_base
#include "RE/BSScript/Variable.h"  // BSScript::Variable
#include "RE/BSScript/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/BSScript/StackFrame.h"  // BSScript::StackFrame
#include "RE/BSScript/VMArray.h"  // BSScript::VMArray
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		namespace Impl
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


			NativeFunction() = delete;
			NativeFunction(const NativeFunction&) = delete;
			NativeFunction(NativeFunction&&) = delete;


			NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback) :
				NativeFunctionBase(a_fnName, a_className, is_static_base<base_type>::value, sizeof...(Args)),
				_callback(a_callback)
			{
				std::size_t i = 0;
				((_vars.variables[i++].type.SetTypeID(GetTypeID<Args>())), ...);
				_returnType = GetTypeID<result_type>();
			}


			virtual ~NativeFunction() = default;																												// 00


			virtual bool HasCallback() const override																											// 15
			{
				return _callback != 0;
			}


			virtual bool Run(Variable* a_baseValue, Internal::VirtualMachine* a_vm, UInt32 a_stackID, Variable* a_resultValue, StackFrame* a_frame) override	// 16
			{
				auto chunkIdx = a_frame->stack->GetChunkIdx(a_frame);

				base_type base{};
				if constexpr (std::negation<is_static_base<base_type>>::value) {
					base = a_baseValue->Unpack<base_type>();
					if (!base) {
						return false;
					}
				}

				UInt32 i = sizeof...(Args);
				auto args = Impl::MakeTuple<Args...>(a_frame, chunkIdx);
				if constexpr (std::is_void<result_type>::value) {
					if constexpr (IS_LONG) {
						Impl::CallBack(_callback, std::move(args), a_vm, a_stackID, std::move(base));
						a_resultValue->SetNone();
					} else {
						Impl::CallBack(_callback, std::move(args), std::move(base));
						a_resultValue->SetNone();
					}
				} else {
					if constexpr (IS_LONG) {
						auto result = Impl::CallBack(_callback, std::move(args), a_vm, a_stackID, std::move(base));
						a_resultValue->Pack<result_type>(result);
					} else {
						auto result = Impl::CallBack(_callback, std::move(args), std::move(base));
						a_resultValue->Pack<result_type>(result);
					}
				}

				return true;
			}

		protected:
			// members
			function_type* _callback;	// 50
		};
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


		NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback) :
			base(a_fnName, a_className, a_callback)
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


		NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback) :
			base(a_fnName, a_className, a_callback)
		{}
	};


	template <class F>
	NativeFunction<F>* MakeNativeFunction(const char* a_fnName, const char* a_className, F* a_callback)
	{
		return new NativeFunction<F>(a_fnName, a_className, a_callback);
	}


	namespace BSScript
	{
		namespace Internal
		{
			template <class F>
			void VirtualMachine::RegisterFunction(const char* a_fnName, const char* a_className, F* a_callback, FunctionFlag a_flags)
			{
				RegisterFunction(MakeNativeFunction(a_fnName, a_className, a_callback));
				if (a_flags != FunctionFlag::kNone) {
					Internal::VirtualMachine::GetSingleton()->SetFunctionFlags(a_className, a_fnName, a_flags);
				}
			}
		}
	}
}
