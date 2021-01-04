#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/N/NativeFunctionBase.h"
#include "RE/P/PackUnpack.h"
#include "RE/S/Stack.h"
#include "RE/S/StackFrame.h"
#include "RE/T/TypeTraits.h"
#include "RE/V/Variable.h"
#include "RE/V/VirtualMachine.h"

namespace RE
{
	namespace BSScript
	{
		namespace Impl
		{
			template <class F, class Tuple, std::size_t... I, class... Args>
			inline constexpr decltype(auto) CallbackImpl(F&& a_func, Tuple&& a_tuple, std::index_sequence<I...>, Args&&... a_args)
			{
				return std::invoke(
					std::forward<F>(a_func),
					std::forward<Args>(a_args)...,
					std::get<I>(std::forward<Tuple>(a_tuple))...);
			}

			template <class F, class Tuple, class... Args>
			inline constexpr decltype(auto) CallBack(F&& a_func, Tuple&& a_tuple, Args&&... a_args)
			{
				return CallbackImpl(
					std::forward<F>(a_func),
					std::forward<Tuple>(a_tuple),
					index_sequence_for_tuple<Tuple>{},
					std::forward<Args>(a_args)...);
			}

			template <class... Args, std::size_t... I>
			std::tuple<Args...> MakeTupleImpl(const StackFrame& a_frame, std::uint32_t a_page, std::index_sequence<I...>)
			{
				return std::forward_as_tuple(
					a_frame.GetStackFrameVariable(I, a_page).Unpack<Args>()...);
			}

			// tuple element construction order isn't guaranteed, so we need to wrap it
			template <class... Args>
			std::tuple<Args...> MakeTuple(const StackFrame& a_frame, std::uint32_t a_page)
			{
				return MakeTupleImpl<Args...>(a_frame, a_page, std::index_sequence_for<Args...>{});
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

			NativeFunction(std::string_view a_fnName, std::string_view a_className, function_type a_callback) :
				NF_util::NativeFunctionBase(a_fnName, a_className, is_static_base_v<base_type>, sizeof...(Args)),
				_stub(a_callback)
			{
				std::size_t i = 0;
				((_descTable.entries[i++].second.SetType(GetRawType<Args>())), ...);
				_retType = GetRawType<result_type>();
			}

			virtual ~NativeFunction() = default;  // 00

			virtual bool HasStub() const override  // 15
			{
				return static_cast<bool>(_stub);
			}

			virtual bool MarshallAndDispatch(Variable& a_baseValue, [[maybe_unused]] Internal::VirtualMachine& a_vm, [[maybe_unused]] VMStackID a_stackID, Variable& a_resultValue, const StackFrame& a_frame) const override  // 16
			{
				base_type base{};
				if constexpr (std::negation_v<is_static_base<base_type>>) {
					base = a_baseValue.Unpack<base_type>();
					if (!base) {
						return false;
					}
				}

				auto page = a_frame.GetPageForFrame();
				auto args = Impl::MakeTuple<Args...>(a_frame, page);
				if constexpr (std::is_void_v<result_type>) {
					if constexpr (IS_LONG) {
						Impl::CallBack(_stub, std::move(args), std::addressof(a_vm), a_stackID, std::move(base));
						a_resultValue.SetNone();
					} else {
						Impl::CallBack(_stub, std::move(args), std::move(base));
						a_resultValue.SetNone();
					}
				} else {
					if constexpr (IS_LONG) {
						auto result = Impl::CallBack(_stub, std::move(args), std::addressof(a_vm), a_stackID, std::move(base));
						a_resultValue.Pack<result_type>(std::move(result));
					} else {
						auto result = Impl::CallBack(_stub, std::move(args), std::move(base));
						a_resultValue.Pack<result_type>(std::move(result));
					}
				}

				return true;
			}

		protected:
			// members
			std::function<function_type> _stub;	 // 50
		};
	}

	template <class F, class = void>
	class NativeFunction;

	template <class R, class Cls, class... Args>
	class NativeFunction<R(Cls, Args...), std::enable_if_t<BSScript::is_valid_short_sig_v<R, Cls, Args...>>> :
		public BSScript::NativeFunction<false, R(Cls, Args...), R, Cls, Args...>
	{
	private:
		using super = BSScript::NativeFunction<false, R(Cls, Args...), R, Cls, Args...>;

	public:
		using result_type = typename super::result_type;
		using base_type = typename super::base_type;
		using function_type = typename super::function_type;

		using super::super;
	};

	template <class Int, class R, class Cls, class... Args>
	class NativeFunction<R(BSScript::Internal::VirtualMachine*, Int, Cls, Args...), std::enable_if_t<BSScript::is_valid_long_sig_v<Int, R, Cls, Args...>>> :
		public BSScript::NativeFunction<true, R(BSScript::Internal::VirtualMachine*, Int, Cls, Args...), R, Cls, Args...>
	{
	private:
		using super = BSScript::NativeFunction<true, R(BSScript::Internal::VirtualMachine*, Int, Cls, Args...), R, Cls, Args...>;

	public:
		using result_type = typename super::result_type;
		using base_type = typename super::base_type;
		using function_type = typename super::function_type;

		using super::super;
	};

	template <class Int, class R, class Cls, class... Args>
	class NativeFunction<R(BSScript::IVirtualMachine*, Int, Cls, Args...), std::enable_if_t<BSScript::is_valid_long_sig_v<Int, R, Cls, Args...>>> :
		public BSScript::NativeFunction<true, R(BSScript::IVirtualMachine*, Int, Cls, Args...), R, Cls, Args...>
	{
	private:
		using super = BSScript::NativeFunction<true, R(BSScript::IVirtualMachine*, Int, Cls, Args...), R, Cls, Args...>;

	public:
		using result_type = typename super::result_type;
		using base_type = typename super::base_type;
		using function_type = typename super::function_type;

		using super::super;
	};

	template <class F>
	NativeFunction(std::string_view, std::string_view, F) -> NativeFunction<std::remove_pointer_t<F>>;

	namespace BSScript
	{
		template <class F>
		void IVirtualMachine::RegisterFunction(std::string_view a_fnName, std::string_view a_className, F a_callback, bool a_callableFromTasklets)
		{
			BindNativeMethod(new RE::NativeFunction(a_fnName, a_className, a_callback));
			if (a_callableFromTasklets) {
				SetCallableFromTasklets(a_className.data(), a_fnName.data(), a_callableFromTasklets);
			}
		}
	}
}
