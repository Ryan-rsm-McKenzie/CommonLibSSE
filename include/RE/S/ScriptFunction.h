#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IFunction.h"
#include "RE/P/PackedInstructionStream.h"
#include "RE/T/TypeInfo.h"
#include "RE/V/VDescTable.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class ScriptFunction : public IFunction
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__Internal__ScriptFunction;

				~ScriptFunction() override;  // 00

				// override (IFunction)
				const BSFixedString& GetName() const override;                                                                                                  // 01 - { return functionName; }
				const BSFixedString& GetObjectTypeName() const override;                                                                                        // 02 - { return scriptName; }
				const BSFixedString& GetStateName() const override;                                                                                             // 03 - { return stateName; }
				TypeInfo             GetReturnType() const override;                                                                                            // 04 - { return returnType; }
				std::uint32_t        GetParamCount() const override;                                                                                            // 05 - { return varInfo.numParams; }
				void                 GetParam(std::uint32_t a_idx, BSFixedString& a_nameOut, TypeInfo& a_typeOut) const override;                               // 06
				std::uint32_t        GetStackFrameSize() const override;                                                                                        // 07 - { return (descTable.totalEntries - descTable.paramCount) + GetNumParams(); }
				bool                 GetIsNative() const override;                                                                                              // 08 - { return false; }
				bool                 GetIsStatic() const override;                                                                                              // 09 - { return isStatic; }
				bool                 GetIsEmpty() const override;                                                                                               // 0A - { return instructions.numInstructionBits == 0; }
				FunctionType         GetFunctionType() const override;                                                                                          // 0B - { return functionType; }
				std::uint32_t        GetUserFlags() const override;                                                                                             // 0C - { return userFlags; }
				const BSFixedString& GetDocString() const override;                                                                                             // 0D - { return docString; }
				void                 InsertLocals(StackFrame* a_frame) override;                                                                                // 0E
				CallResult           Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) override;  // 0F
				const BSFixedString& GetSourceFilename() const override;                                                                                        // 10 - { return sourceFileName; }
				bool                 TranslateIPToLineNumber(std::uint32_t a_indexPtr, std::uint32_t& a_lineNumberOut) const override;                          // 11
				bool                 GetVarNameForStackIndex(std::uint32_t a_idx, BSFixedString& a_nameOut) const override;                                     // 12
				bool                 CanBeCalledFromTasklets() const override;                                                                                  // 13 - { return true; }
				void                 SetCallableFromTasklets(bool a_callable) override;                                                                         // 14 - { return; }

				// members
				BSFixedString                                 name;             // 10
				BSFixedString                                 objName;          // 18
				BSFixedString                                 stateName;        // 20
				TypeInfo                                      retType;          // 28
				VDescTable                                    descTable;        // 30
				std::uint32_t                                 userFlags;        // 40
				std::uint32_t                                 pad44;            // 44
				ByteCode::PackedInstructionStream             instructions;     // 48
				stl::enumeration<FunctionType, std::uint16_t> functionType;     // 58
				bool                                          isStatic;         // 5A
				std::uint8_t                                  pad5B;            // 5B
				std::uint32_t                                 pad5C;            // 5C
				BSFixedString                                 docString;        // 60
				BSFixedString                                 sourceFileName;   // 68
				std::uint32_t                                 lineNumberCount;  // 70
				std::uint32_t                                 pad74;            // 74
				std::uint16_t*                                lineNumbers;      // 78
			};
			static_assert(sizeof(ScriptFunction) == 0x80);
		}
	}
}
