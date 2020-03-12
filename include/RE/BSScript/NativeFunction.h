#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/NF_util/NativeFunctionBase.h"
#include "RE/BSScript/PackUnpack.h"
#include "RE/BSScript/Stack.h"
#include "RE/BSScript/StackFrame.h"
#include "RE/BSScript/TypeTraits.h"
#include "RE/BSScript/VMArray.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSTSmartPointer.h"


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


			template <class... Args, std::size_t... I>
			std::tuple<Args...> MakeTupleImpl(const StackFrame& a_frame, std::index_sequence<I...>)
			{
				return std::forward_as_tuple(Args{ a_frame.args[I].Unpack<Args>() }...);
			}


			// tuple element construction order isn't guaranteed, so we need to wrap it
			template <class... Args>
			std::tuple<Args...> MakeTuple(const StackFrame& a_frame)
			{
				return MakeTupleImpl<Args...>(a_frame, std::make_index_sequence<sizeof...(Args)>{});
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
				_stub(a_callback)
			{
				std::size_t i = 0;
				((_descTable.entries[i++].second.SetType(GetRawType<Args>())), ...);
				_retType = GetRawType<result_type>();
			}


			virtual ~NativeFunction() = default;  // 00


			virtual bool HasStub() const override  // 15
			{
				return _stub != 0;
			}


			virtual bool MarshallAndDispatch(Variable& a_baseValue, [[maybe_unused]] Internal::VirtualMachine& a_vm, [[maybe_unused]] VMStackID a_stackID, Variable& a_resultValue, const StackFrame& a_frame) const override  // 16
			{
				base_type base{};
				if constexpr (std::negation<is_static_base<base_type>>::value) {
					base = a_baseValue.Unpack<base_type>();
					if (!base) {
						return false;
					}
				}

				auto args = Impl::MakeTuple<Args...>(a_frame);
				if constexpr (std::is_void<result_type>::value) {
					if constexpr (IS_LONG) {
						Impl::CallBack(_stub, std::move(args), std::addressof(a_vm), a_stackID, std::move(base));
						a_resultValue.SetNone();
					} else {
						Impl::CallBack(_stub, std::move(args), std::move(base));
						a_resultValue.SetNone();
					}
				} else {
					if constexpr (IS_LONG) {
						auto result = std::move(Impl::CallBack(_stub, std::move(args), std::addressof(a_vm), a_stackID, std::move(base)));
						a_resultValue.Pack<result_type>(std::move(result));
					} else {
						auto result = std::move(Impl::CallBack(_stub, std::move(args), std::move(base)));
						a_resultValue.Pack<result_type>(std::move(result));
					}
				}

				return true;
			}

		protected:
			// members
			function_type* _stub;  // 50
		};
	}


	template <class F, class Enable = void>
	class NativeFunction;


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


	template <class Int, class R, class Cls, class... Args>
	class NativeFunction<R(BSScript::IVirtualMachine*, Int, Cls, Args...), std::enable_if_t<BSScript::is_valid_long_sig<Int, R, Cls, Args...>::value>> :
		public BSScript::NativeFunction<true, R(BSScript::IVirtualMachine*, Int, Cls, Args...), R, Cls, Args...>
	{
	private:
		using base = BSScript::NativeFunction<true, R(BSScript::IVirtualMachine*, Int, Cls, Args...), R, Cls, Args...>;

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
		template <class F>
		void IVirtualMachine::RegisterFunction(const char* a_fnName, const char* a_className, F* a_callback, bool a_callableFromTasklets)
		{
			BindNativeMethod(MakeNativeFunction(a_fnName, a_className, a_callback));
			if (a_callableFromTasklets) {
				SetCallableFromTasklets(a_className, a_fnName, a_callableFromTasklets);
			}
		}
	}
}
