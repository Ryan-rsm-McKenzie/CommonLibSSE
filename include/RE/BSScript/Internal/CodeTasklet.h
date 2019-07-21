#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__Internal__CodeTasklet

#include "RE/BSScript/Internal/IFuncCallQuery.h"  // BSScript::Internal::IFuncCallQuery


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
				inline static const void* RTTI = RTTI_BSScript__Internal__CodeTasklet;


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


				virtual ~CodeTasklet();				// 00

				// override (IFuncCallQuery)
				virtual void Unk_01(void) override;	// 01


				// members
				Stack*			stack;			// 10
				VirtualMachine*	virtualMachine;	// 18
				ErrorLogger*	errorLogger;	// 20
				UInt32			unk28;			// 28
				UInt32			pad2C;			// 2C
				StackFrame*		stackFrame;		// 30
				UInt32			chunkIdx;		// 38
				UInt16			unk3C;			// 3C
				UInt16			unk3E;			// 3E
				UInt32			unk40;			// 40
				UInt32			unk44;			// 44
				UInt64			unk48;			// 48
			};
			STATIC_ASSERT(sizeof(CodeTasklet) == 0x50);
		}
	}
}
