#include "RE/N/NativeFunctionBase.h"

namespace RE
{
	namespace BSScript
	{
		namespace NF_util
		{
			NativeFunctionBase::NativeFunctionBase(std::string_view a_fnName, std::string_view a_className, bool a_isStatic, std::uint16_t a_numParams) :
				_name(a_fnName),
				_objName(a_className),
				_descTable(a_numParams, 0),
				_isStatic(a_isStatic)
			{
				// native supports max 11
				std::string param("param");
				std::size_t num = 1;
				for (auto& elem : _descTable.entries) {
					elem.first = param + std::to_string(num++);
				}
			}

			const BSFixedString& NativeFunctionBase::GetName() const
			{
				return _name;
			}

			const BSFixedString& NativeFunctionBase::GetObjectTypeName() const
			{
				return _objName;
			}

			const BSFixedString& NativeFunctionBase::GetStateName() const
			{
				return _stateName;
			}

			TypeInfo NativeFunctionBase::GetReturnType() const
			{
				return _retType;
			}

			std::uint32_t NativeFunctionBase::GetParamCount() const
			{
				return _descTable.totalEntries;
			}

			void NativeFunctionBase::GetParam(std::uint32_t a_idx, BSFixedString& a_nameOut, TypeInfo& a_typeOut) const
			{
				if (a_idx < _descTable.paramCount) {
					auto& elem = _descTable.entries[a_idx];
					a_nameOut = elem.first;
					a_typeOut = elem.second;
				} else {
					a_nameOut = "";
					a_typeOut.SetType(TypeInfo::RawType::kNone);
				}
			}

			std::uint32_t NativeFunctionBase::GetStackFrameSize() const
			{
				return _descTable.totalEntries;
			}

			bool NativeFunctionBase::GetIsNative() const
			{
				return true;
			}

			bool NativeFunctionBase::GetIsStatic() const
			{
				return _isStatic;
			}

			bool NativeFunctionBase::GetIsEmpty() const
			{
				return false;
			}

			auto NativeFunctionBase::GetFunctionType() const
				-> FunctionType
			{
				return FunctionType::kNormal;
			}

			std::uint32_t NativeFunctionBase::GetUserFlags() const
			{
				return _userFlags;
			}

			const BSFixedString& NativeFunctionBase::GetDocString() const
			{
				return _docString;
			}

			void NativeFunctionBase::InsertLocals(StackFrame*)
			{
				return;
			}

			auto NativeFunctionBase::Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4)
				-> CallResult
			{
				using func_t = decltype(&NativeFunctionBase::Call);
				REL::Relocation<func_t> func{ Offset::BSScript::NF_util::NativeFunctionBase::Call };
				return func(this, a_stack, a_logger, a_vm, a_arg4);
			}

			const BSFixedString& NativeFunctionBase::GetSourceFilename() const
			{
				static BSFixedString native("<native>");
				return native;
			}

			bool NativeFunctionBase::TranslateIPToLineNumber(std::uint32_t, std::uint32_t& a_lineNumberOut) const
			{
				a_lineNumberOut = 0;
				return false;
			}

			bool NativeFunctionBase::GetVarNameForStackIndex(std::uint32_t a_idx, BSFixedString& a_nameOut) const
			{
				if (a_idx < _descTable.totalEntries) {
					a_nameOut = _descTable.entries[a_idx].first;
					return true;
				} else {
					a_nameOut = "";
					return false;
				}
			}

			bool NativeFunctionBase::CanBeCalledFromTasklets() const
			{
				return _isCallableFromTasklet;
			}

			void NativeFunctionBase::SetCallableFromTasklets(bool a_callable)
			{
				_isCallableFromTasklet = a_callable;
			}
		}
	}
}
