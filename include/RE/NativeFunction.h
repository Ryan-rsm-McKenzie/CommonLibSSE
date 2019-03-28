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
			template <class Last>
			inline void SetTypesImpl(NF_util::NativeFunctionBase::ParameterInfo::Entry* a_data, std::size_t a_idx)
			{
				a_data[a_idx].type.SetTypeID(GetTypeID<Last>());
			}


			template <class First, class Second, class... Rest>
			inline void SetTypesImpl(NF_util::NativeFunctionBase::ParameterInfo::Entry* a_data, std::size_t a_idx)
			{
				a_data[a_idx++].type.SetTypeID(GetTypeID<First>());
				SetTypesImpl<Second, Rest...>(a_data, a_idx);
			}


			template <class F, class Tuple, std::size_t... I, class... Args>
			inline constexpr decltype(auto) DoCallbackImpl(F&& a_func, Tuple&& a_tuple, std::index_sequence<I...>, Args&&... a_args)
			{
				return std::invoke(std::forward<F>(a_func), std::forward<Args>(a_args)..., std::get<I>(std::forward<Tuple>(a_tuple))...);
			}


			template <class... Args>
			inline void SetTypes(NF_util::NativeFunctionBase::ParameterInfo::Entry* a_data)
			{
				std::size_t i = 0;
				SetTypesImpl<Args...>(a_data, i);
			}


			template <class F, class Tuple, class... Args>
			inline constexpr decltype(auto) DoCallBack(F&& a_func, Tuple&& a_tuple, Args&&... a_args)
			{
				return DoCallbackImpl(std::forward<F>(a_func), std::forward<Tuple>(a_tuple), make_index_sequence_from_tuple<Tuple>{}, std::forward<Args>(a_args)...);
			}


			template <std::size_t I = 0, class Tuple, std::size_t SIZE = std::tuple_size_v<std::remove_reference_t<Tuple>>, class F, class... Args>
			inline void ForEachTupleElem(Tuple&& a_tuple, F&& a_func, Args&&... a_args)
			{
				if constexpr (I < SIZE)
				{
					std::invoke(a_func, a_args..., std::get<I>(a_tuple));

					if constexpr (I + 1 < SIZE)
					{
						ForEachTupleElem<I + 1>(std::forward<Tuple>(a_tuple), std::forward<F>(a_func), std::forward<Args>(a_args)...);
					}
				}
			}


			namespace Impl
			{
				template <bool IS_LONG, class F, class R, class Base, class... Args>
				class NativeFunction : public NF_util::NativeFunctionBase
				{
				public:
					using return_type = R;
					using base_type = Base;
					using function_type = F;
					using FunctionFlag = IVirtualMachine::FunctionFlag;


					NativeFunction() = delete;
					NativeFunction(const NativeFunction&) = delete;
					NativeFunction(NativeFunction&&) = delete;


					NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags) :
						NativeFunctionBase(a_fnName, a_className, is_static_base<base_type>::value, sizeof...(Args)),
						callback(a_callback)
					{
						SetTypes<Args...>(params.data);
						returnType = GetTypeID<return_type>();
						if (a_flags != FunctionFlag::kNone) {
							Internal::VirtualMachine::GetSingleton()->SetFunctionFlags(a_className, a_fnName, a_flags);
						}
					}


					virtual ~NativeFunction() = default;	// 00


					virtual bool HasCallback() const override	// 15
					{
						return callback != 0;
					}


					virtual bool Run(BSScriptVariable* a_baseValue, Internal::VirtualMachine* a_vm, UInt32 a_stackID, BSScriptVariable* a_resultValue, StackFrame* a_frame)	// 16
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

						std::tuple<Args...> args;
						std::size_t i = 0;
						ForEachTupleElem(args, [&](auto& a_elem)
						{
							using elem_type = remove_cvr_t<decltype(a_elem)>;
							a_elem = a_frame->Get(i++, offset)->Unpack<elem_type>();
						});

						if constexpr (std::is_void<return_type>::value)
						{
							if constexpr (IS_LONG)
							{
								DoCallBack(callback, args, a_vm, a_stackID, base);
								a_resultValue->SetNone();
							} else {
								DoCallBack(callback, args, base);
								a_resultValue->SetNone();
							}
						} else {
							if constexpr (IS_LONG)
							{
								auto result = DoCallBack(callback, args, a_vm, a_stackID, base);
								a_resultValue->Pack<return_type>(result);
							} else {
								auto result = DoCallBack(callback, args, base);
								a_resultValue->Pack<return_type>(result);
							}
						}
						return true;
					}


					// members
					function_type* callback;	// 50
				};
			}
		}


		template <class F, class Enable = void> class NativeFunction;


		template <class R, class Cls, class... Args>
		class NativeFunction<R(Cls, Args...), std::enable_if_t<is_valid_short_sig<R, Cls, Args...>::value>> :
			public Impl::NativeFunction<false, R(Cls, Args...), R, Cls, Args...>
		{
		private:
			using base = Impl::NativeFunction<false, R(Cls, Args...), R, Cls, Args...>;

		public:
			using return_type = typename base::return_type;
			using base_type = typename base::base_type;
			using function_type = typename base::function_type;
			using FunctionFlag = IVirtualMachine::FunctionFlag;


			NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags = FunctionFlag::kNone) :
				base(a_fnName, a_className, a_callback, a_flags)
			{}
		};


		template <class Int, class R, class Cls, class... Args>
		class NativeFunction<R(Internal::VirtualMachine*, Int, Cls, Args...), std::enable_if_t<is_valid_long_sig<Int, R, Cls, Args...>::value>> :
			public Impl::NativeFunction<true, R(Internal::VirtualMachine*, Int, Cls, Args...), R, Cls, Args...>
		{
		private:
			using base = Impl::NativeFunction<true, R(Internal::VirtualMachine*, Int, Cls, Args...), R, Cls, Args...>;

		public:
			using return_type = typename base::return_type;
			using base_type = typename base::base_type;
			using function_type = typename base::function_type;
			using FunctionFlag = IVirtualMachine::FunctionFlag;


			NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback, FunctionFlag a_flags = FunctionFlag::kNone) :
				base(a_fnName, a_className, a_callback, a_flags)
			{}
		};
	}
}
