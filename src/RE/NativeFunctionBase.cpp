#include "RE/NativeFunctionBase.h"

#include "skse64/PapyrusNativeFunctions.h"  // NativeFunctionBase, NativeFunction

#include "RE/BSScriptType.h"  // BSScriptType


namespace RE
{
	namespace BSScript
	{
		namespace NF_util
		{
			NativeFunctionBase::NativeFunctionBase(const char* a_fnName, const char* a_className, bool a_isStatic, UInt32 a_numParams)
			{
				Ctor(a_fnName, a_className, a_isStatic, a_numParams);
			}


			NativeFunctionBase::~NativeFunctionBase()
			{
				Dtor();
			}


			const BSFixedString& NativeFunctionBase::GetName() const
			{
				return fnName;
			}


			const BSFixedString& NativeFunctionBase::GetScriptName() const
			{
				return scriptName;
			}


			const BSFixedString& NativeFunctionBase::GetStateName() const
			{
				return stateName;
			}


			void NativeFunctionBase::GetReturnType(BSScriptType& a_dst) const
			{
				a_dst.SetTypeID(returnType);
			}


			UInt32 NativeFunctionBase::GetNumParams() const
			{
				return params.unk0A;
			}


			BSScriptType& NativeFunctionBase::GetParam(UInt32 a_idx, BSFixedString& a_nameOut, BSScriptType& a_typeOut) const
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::GetParam)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_GetParam, func_t*);
				return func(this, a_idx, a_nameOut, a_typeOut);
			}


			UInt32 NativeFunctionBase::GetNumParams2() const
			{
				return params.unk0A;
			}


			bool NativeFunctionBase::IsNative() const
			{
				return true;
			}


			bool NativeFunctionBase::IsStatic() const
			{
				return isStatic;
			}


			bool NativeFunctionBase::IsEvent() const
			{
				return false;
			}


			UInt32 NativeFunctionBase::Unk_0B(void)
			{
				return 0;
			}


			UInt32 NativeFunctionBase::GetUnk44() const
			{
				return unk44;
			}


			const BSFixedString& NativeFunctionBase::GetStr48() const
			{
				return unk48;
			}


			void NativeFunctionBase::Unk_0E(UInt32 a_arg1)
			{
				return;
			}


			UInt32 NativeFunctionBase::Invoke(BSScriptStackPtr& a_stack, void* a_arg2, Internal::VirtualMachine* a_vm, UInt32 a_arg4)
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::Invoke)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_Invoke, func_t*);
				return func(this, a_stack, a_arg2, a_vm, a_arg4);
			}


			const BSFixedString& NativeFunctionBase::GetSource() const
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::GetSource)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_Fn10, func_t*);
				return func(this);
			}


			bool NativeFunctionBase::Unk_11(UInt32 a_arg1, UInt32* a_arg2)
			{
				*a_arg2 = 0;
				return false;
			}


			bool NativeFunctionBase::GetParamName(UInt32 a_idx, BSFixedString& a_out) const
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::GetParamName)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_Fn12, func_t*);
				return func(this, a_idx, a_out);
			}


			bool NativeFunctionBase::GetUnk41() const
			{
				return unk41;
			}


			void NativeFunctionBase::SetUnk41(bool a_arg)
			{
				unk41 = a_arg;
			}


			NativeFunctionBase* NativeFunctionBase::Ctor(const char* a_fnName, const char* a_className, bool a_isStatic, UInt32 a_numParams)
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::Ctor)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunction, Impl_ctor, func_t*);
				return func(this, a_fnName, a_className, a_isStatic, a_numParams);
			}


			void NativeFunctionBase::Dtor()
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::Dtor)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_dtor, func_t*);
				return func(this);
			}
		}
	}
}
