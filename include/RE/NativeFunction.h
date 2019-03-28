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


		template <class Base, class R, class... Args>
		class NativeFunction : public NF_util::NativeFunctionBase
		{
		public:
			using function_type = R(Base, Args...);


			NativeFunction() = delete;
			NativeFunction(const NativeFunction&) = delete;
			NativeFunction(NativeFunction&&) = delete;


			NativeFunction(const char* a_fnName, const char* a_className, function_type* a_callback) :
				NativeFunctionBase(a_fnName, a_className, is_static_base<Base>::value, sizeof...(Args)),
				callback(a_callback)
			{
				SetTypes<Args...>(params.data);
				returnType = GetTypeID<R>();
			}


			virtual ~NativeFunction() = default;	// 00


			virtual bool HasCallback() const override	// 15
			{
				return callback != 0;
			}


			virtual bool Run(BSScriptVariable* a_baseValue, Internal::VirtualMachine* a_vm, UInt32 a_stackID, BSScriptVariable* a_resultValue, StackFrame* a_frame)	// 16
			{
				auto offset = a_frame->stack->GetOffset(a_frame);

				Base base{};
				if constexpr (std::negation<is_static_base<Base>>::value)
				{
					base = a_baseValue->Unpack<Base>();
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

				if constexpr (std::is_void<R>::value)
				{
					DoCallBack(callback, args, base);
					a_resultValue->SetNone();
				} else {
					R result = DoCallBack(callback, args, base);
					a_resultValue->Pack<R>(result);
				}
				return true;
			}


			// members
			function_type* callback;	// 50
		};
	}
}
