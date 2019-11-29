#include "RE/BSScript/NF_util/NativeFunctionBase.h"

#include <string>

#include "RE/BSScript/Type.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		namespace NF_util
		{
			NativeFunctionBase::NativeFunctionBase(const char* a_fnName, const char* a_className, bool a_isStatic, UInt32 a_numParams) :
				_fnName(a_fnName),
				_scriptName(a_className),
				_stateName(""),
				_returnType(VMTypeID::kNone),
				_vars(a_numParams, 0),
				_isStatic(a_isStatic),
				_unk41(false),
				_isLatent(false),
				_pad43(0),
				_unk44(0),
				_unk48("")
			{
				// native supports max 11
				std::string param("param");
				std::size_t num = 1;
				for (auto& elem : _vars.variables) {
					elem.name = param + std::to_string(num++);
				}
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
				return _vars.numVars;
			}


			Type& NativeFunctionBase::GetParam(UInt32 a_idx, BSFixedString& a_nameOut, Type& a_typeOut) const
			{
				if (a_idx < _vars.numParams) {
					auto& elem = _vars.variables[a_idx];
					a_nameOut = elem.name;
					a_typeOut = elem.type;
				} else {
					a_nameOut = "";
					a_typeOut = {};
				}
				return a_typeOut;
			}


			UInt32 NativeFunctionBase::GetNumVars() const
			{
				return _vars.numVars;
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
				REL::Offset<func_t*> func(Offset::BSScript::NF_util::NativeFunctionBase::Invoke);
				return func(this, a_stack, a_logger, a_vm, a_arg4);
			}


			const BSFixedString& NativeFunctionBase::GetSource() const
			{
				static BSFixedString native("<native>");
				return native;
			}


			bool NativeFunctionBase::GetLineNumber(UInt32 a_taskletExecutionOffset, UInt32& a_lineNumber)
			{
				a_lineNumber = 0;
				return false;
			}


			bool NativeFunctionBase::GetVarName(UInt32 a_idx, BSFixedString& a_out) const
			{
				if (a_idx < _vars.numVars) {
					a_out = _vars.variables[a_idx].name;
					return true;
				} else {
					a_out = "";
					return false;
				}
			}


			bool NativeFunctionBase::GetUnk41() const
			{
				return _unk41;
			}


			void NativeFunctionBase::SetUnk41(bool a_arg)
			{
				_unk41 = a_arg;
			}
		}
	}
}
