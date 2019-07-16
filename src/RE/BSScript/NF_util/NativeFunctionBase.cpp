#include "RE/BSScript/NF_util/NativeFunctionBase.h"

#include "skse64/PapyrusNativeFunctions.h"  // NativeFunctionBase, NativeFunction

#include "RE/BSScript/Type.h"  // BSScript::Type


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


			const BSFixedString& NativeFunctionBase::GetFunctionName() const
			{
				return _fnName;
			}


			const BSFixedString& NativeFunctionBase::GetScriptName() const
			{
				return _scriptName;
			}


			const BSFixedString& NativeFunctionBase::GetStateName() const
			{
				return _stateName;
			}


			Type& NativeFunctionBase::GetReturnType(Type& a_dst) const
			{
				a_dst.SetTypeID(_returnType);
				return a_dst;
			}


			UInt32 NativeFunctionBase::GetNumParams() const
			{
				return _params.numVars;
			}


			Type& NativeFunctionBase::GetParam(UInt32 a_idx, BSFixedString& a_nameOut, Type& a_typeOut) const
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::GetParam)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_GetParam, func_t*);
				return func(this, a_idx, a_nameOut, a_typeOut);
			}


			UInt32 NativeFunctionBase::GetNumVars() const
			{
				return _params.numVars;
			}


			bool NativeFunctionBase::IsNative() const
			{
				return true;
			}


			bool NativeFunctionBase::IsStatic() const
			{
				return _isStatic;
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
				return _unk44;
			}


			const BSFixedString& NativeFunctionBase::GetStr48() const
			{
				return _unk48;
			}


			void NativeFunctionBase::MoveVariablesToStack(StackFrame* a_stack)
			{
				return;
			}


			UInt32 NativeFunctionBase::Invoke(BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4)
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::Invoke)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_Invoke, func_t*);
				return func(this, a_stack, a_logger, a_vm, a_arg4);
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


			bool NativeFunctionBase::GetVarName(UInt32 a_idx, BSFixedString& a_out) const
			{
				using func_t = function_type_t<decltype(&NativeFunctionBase::GetVarName)>;
				func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NativeFunctionBase, Impl_Fn12, func_t*);
				return func(this, a_idx, a_out);
			}


			bool NativeFunctionBase::GetUnk41() const
			{
				return _unk41;
			}


			void NativeFunctionBase::SetUnk41(bool a_arg)
			{
				_unk41 = a_arg;
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
