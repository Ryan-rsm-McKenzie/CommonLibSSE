#pragma once

#include "RE/I/IFuncCallQuery.h"

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

				enum class ResumeReason
				{
					kNotResuming = 0,
					kNotResumingNoIncrement = 1,
					kInitialStart = 2,
					kFunctionReturn = 3,
					kRetryInstruction = 4,
					kFunctionCall = 5
				};

				enum class OpCode
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

				~CodeTasklet() override;  // 00

				// override (IFuncCallQuery)
				bool GetFunctionCallInfo(CallType& a_callType, BSTSmartPointer<ObjectTypeInfo>& a_arg2, BSFixedString& a_arg3, Variable& a_arg4, BSScrapArray<Variable>& a_arg5) override;  // 01

				// members
				Stack*                                        stack;                    // 10
				VirtualMachine*                               vm;                       // 18
				ErrorLogger*                                  errorLogger;              // 20
				stl::enumeration<ResumeReason, std::uint32_t> resumeReason;             // 28
				std::uint32_t                                 pad2C;                    // 2C
				StackFrame*                                   topFrame;                 // 30
				std::uint32_t                                 frameMemoryPage;          // 38
				std::int8_t                                   jumpBitCount;             // 3C
				std::int8_t                                   localVarBitCount;         // 3D
				std::int8_t                                   memberVarBitCount;        // 3E
				std::uint8_t                                  pad3F;                    // 3F
				std::uint32_t                                 instructionDataBitCount;  // 40
				std::uint32_t                                 pad44;                    // 44
				const void*                                   instructionDataStart;     // 48
			};
			static_assert(sizeof(CodeTasklet) == 0x50);
		}
	}
}
