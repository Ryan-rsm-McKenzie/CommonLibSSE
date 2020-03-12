#pragma once

#include "RE/BSScript/Internal/IFuncCallQuery.h"


namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class Stack;
		class StackFrame;


		namespace Internal
		{
			class VirtualMachine;


			class CodeTasklet : public IFuncCallQuery
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__Internal__CodeTasklet;


				enum class ResumeReason : UInt32
				{
					kNotResuming = 0,
					kNotResumingNoIncrement = 1,
					kInitialStart = 2,
					kFunctionReturn = 3,
					kRetryInstruction = 4,
					kFunctionCall = 5
				};


				enum class OpCode : UInt32
				{
					kNOP,
					kIADD,
					kFADD,
					kISUB,
					kFSUB,
					kIMUL,
					kFMUL,
					kIDIV,
					kFDIV,
					kIMOD,
					kNOT,
					kINEG,
					kFNEG,
					kASSIGN,
					kCAST,
					kCMP_EQ,
					kCMP_LT,
					kCMP_LTE,
					kCMP_GT,
					kCMP_GTE,
					kJMP,
					kJMPT,
					kJMPF,
					kCALLMETHOD,
					kCALLPARENT,
					kCALLSTATIC,
					kRETURN,
					kSTRCAT,
					kPROPGET,
					kPROPSET,
					kARRAY_CREATE,
					kARRAY_LENGTH,
					kARRAY_GETELEMENT,
					kARRAY_SETELEMENT,
					kARRAY_FINDELEMENT,
					kARRAY_RFINDELEMENT
				};


				virtual ~CodeTasklet();	 // 00

				// override (IFuncCallQuery)
				virtual bool GetFunctionCallInfo(CallType& a_callType, BSTSmartPointer<ObjectTypeInfo>& a_arg2, BSFixedString& a_arg3, Variable& a_arg4, BSScrapArray<Variable>& a_arg5) override;	// 01


				// members
				Stack*			stack;					  // 10
				VirtualMachine* vm;						  // 18
				ErrorLogger*	errorLogger;			  // 20
				ResumeReason	resumeReason;			  // 28
				UInt32			pad2C;					  // 2C
				StackFrame*		topFrame;				  // 30
				UInt32			frameMemoryPage;		  // 38
				SInt8			jumpBitCount;			  // 3C
				SInt8			localVarBitCount;		  // 3D
				SInt8			memberVarBitCount;		  // 3E
				UInt8			pad3F;					  // 3F
				UInt32			instructionDataBitCount;  // 40
				UInt32			pad44;					  // 44
				const void*		instructionDataStart;	  // 48
			};
			STATIC_ASSERT(sizeof(CodeTasklet) == 0x50);
		}
	}
}
