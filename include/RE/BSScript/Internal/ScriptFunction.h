#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__Internal__ScriptFunction

#include "RE/BSScript/IFunction.h"  // BSScript::IFunction
#include "RE/BSScript/Type.h"  // BSScript::Type
#include "RE/BSScript/VariableInfo.h"  // BSScript::VariableInfo
#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class ScriptFunction : public IFunction
			{
			public:
				inline static const void* RTTI = RTTI_BSScript__Internal__ScriptFunction;


				virtual ~ScriptFunction();																																// 00

				// override (IFunction)
				virtual const BSFixedString&	GetFunctionName() const override;																						// 01 - { return functionName; }
				virtual const BSFixedString&	GetScriptName() const override;																							// 02 - { return scriptName; }
				virtual const BSFixedString&	GetStateName() const override;																							// 03 - { return stateName; }
				virtual Type&					GetReturnType(Type& a_dst) const override;																				// 04 - { a_dst = returnType; return a_dst; }
				virtual UInt32					GetNumParams() const override;																							// 05 - { return varInfo.numParams; }
				virtual Type&					GetParam(UInt32 a_idx, BSFixedString& a_nameOut, Type& a_typeOut) const override;										// 06
				virtual UInt32					GetNumVars() const override;																							// 07 - { return (varInfo.numVars - varInfo.numParams) + GetNumParams(); }
				virtual bool					IsNative() const override;																								// 08 - { return false; }
				virtual bool					IsStatic() const override;																								// 09 - { return isStatic; }
				virtual bool					IsEvent() const override;																								// 0A - { return unk48 == 0; }
				virtual UInt32					Unk_0B() override;																										// 0B - { return unk58; }
				virtual UInt32					GetUnk44() const override;																								// 0C - { return unk40; }
				virtual const BSFixedString&	GetStr48() const override;																								// 0D - { return unk60; }
				virtual void					MoveVariablesToStack(StackFrame* a_frame) override;																		// 0E
				virtual UInt32					Invoke(BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) override;	// 0F
				virtual const BSFixedString&	GetSource() const override;																								// 10 - { return sourceFileName; }
				virtual bool					GetLineNumber(UInt32 a_taskletExecutionOffset, UInt32& a_lineNumber) override;											// 11
				virtual bool					GetVarName(UInt32 a_idx, BSFixedString& a_out) const override;															// 12
				virtual bool					GetUnk41() const override;																								// 13 - { return true; }
				virtual void					SetUnk41(bool a_arg) override;																							// 14 - { return; }


				// members
				BSFixedString	functionName;		// 10
				BSFixedString	scriptName;			// 18
				BSFixedString	stateName;			// 20
				Type			returnType;			// 28
				VariableInfo	varInfo;			// 30
				UInt32			unk40;				// 40
				UInt32			unk44;				// 44
				UInt32			unk48;				// 48
				UInt8			unk4C;				// 4C
				UInt8			unk4D;				// 4D
				UInt8			unk4E;				// 4E
				UInt8			unk4F;				// 4F
				UInt64*			unk50;				// 50
				UInt16			unk58;				// 58
				bool			isStatic;			// 5A
				UInt8			unk5B;				// 5B
				UInt32			unk5C;				// 5C
				BSFixedString	unk60;				// 60
				BSFixedString	sourceFileName;		// 68
				UInt32			numLineMappings;	// 70
				UInt32			unk74;				// 74
				UInt16*			lineMappings;		// 78
			};
			STATIC_ASSERT(sizeof(ScriptFunction) == 0x80);
		}
	}
}
