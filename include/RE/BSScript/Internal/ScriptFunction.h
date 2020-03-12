#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSScript/ByteCode/PackedInstructionStream.h"
#include "RE/BSScript/IFunction.h"
#include "RE/BSScript/Internal/VDescTable.h"
#include "RE/BSScript/TypeInfo.h"


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


				virtual ~ScriptFunction();	// 00

				// override (IFunction)
				virtual const BSFixedString& GetName() const override;																									// 01 - { return functionName; }
				virtual const BSFixedString& GetObjectTypeName() const override;																						// 02 - { return scriptName; }
				virtual const BSFixedString& GetStateName() const override;																								// 03 - { return stateName; }
				virtual TypeInfo			 GetReturnType() const override;																							// 04 - { return returnType; }
				virtual UInt32				 GetParamCount() const override;																							// 05 - { return varInfo.numParams; }
				virtual void				 GetParam(UInt32 a_idx, BSFixedString& a_nameOut, TypeInfo& a_typeOut) const override;										// 06
				virtual UInt32				 GetStackFrameSize() const override;																						// 07 - { return (descTable.totalEntries - descTable.paramCount) + GetNumParams(); }
				virtual bool				 GetIsNative() const override;																								// 08 - { return false; }
				virtual bool				 GetIsStatic() const override;																								// 09 - { return isStatic; }
				virtual bool				 GetIsEmpty() const override;																								// 0A - { return instructions.numInstructionBits == 0; }
				virtual FunctionType		 GetFunctionType() const override;																							// 0B - { return functionType; }
				virtual UInt32				 GetUserFlags() const override;																								// 0C - { return userFlags; }
				virtual const BSFixedString& GetDocString() const override;																								// 0D - { return docString; }
				virtual void				 InsertLocals(StackFrame* a_frame) override;																				// 0E
				virtual CallResult			 Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) override;	// 0F
				virtual const BSFixedString& GetSourceFilename() const override;																						// 10 - { return sourceFileName; }
				virtual bool				 TranslateIPToLineNumber(UInt32 a_indexPtr, UInt32& a_lineNumberOut) const override;										// 11
				virtual bool				 GetVarNameForStackIndex(UInt32 a_idx, BSFixedString& a_nameOut) const override;											// 12
				virtual bool				 CanBeCalledFromTasklets() const override;																					// 13 - { return true; }
				virtual void				 SetCallableFromTasklets(bool a_callable) override;																			// 14 - { return; }


				// members
				BSFixedString					  name;				// 10
				BSFixedString					  objName;			// 18
				BSFixedString					  stateName;		// 20
				TypeInfo						  retType;			// 28
				VDescTable						  descTable;		// 30
				UInt32							  userFlags;		// 40
				UInt32							  pad44;			// 44
				ByteCode::PackedInstructionStream instructions;		// 48
				FunctionType16					  functionType;		// 58
				bool							  isStatic;			// 5A
				UInt8							  pad5B;			// 5B
				UInt32							  pad5C;			// 5C
				BSFixedString					  docString;		// 60
				BSFixedString					  sourceFileName;	// 68
				UInt32							  lineNumberCount;	// 70
				UInt32							  pad74;			// 74
				UInt16*							  lineNumbers;		// 78
			};
			STATIC_ASSERT(sizeof(ScriptFunction) == 0x80);
		}
	}
}
