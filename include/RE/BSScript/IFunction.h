#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IFunction

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class VirtualMachine;
		}


		class ErrorLogger;
		class Stack;
		class StackFrame;
		class Type;
		class VMState;


		class IFunction : public BSIntrusiveRefCounted
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IFunction;


			IFunction();
			virtual ~IFunction() = default;																														// 00

			// add
			virtual const BSFixedString&	GetFunctionName() const = 0;																						// 01
			virtual const BSFixedString&	GetScriptName() const = 0;																							// 02
			virtual const BSFixedString&	GetStateName() const = 0;																							// 03
			virtual Type&					GetReturnType(Type& a_dst) const = 0;																				// 04
			virtual UInt32					GetNumParams() const = 0;																							// 05
			virtual Type&					GetParam(UInt32 a_idx, BSFixedString& a_nameOut, Type& a_typeOut) const = 0;										// 06
			virtual UInt32					GetNumVars() const = 0;																								// 07
			virtual bool					IsNative() const = 0;																								// 08
			virtual bool					IsStatic() const = 0;																								// 09
			virtual bool					IsEvent() const = 0;																								// 0A
			virtual UInt32					Unk_0B() = 0;																										// 0B
			virtual UInt32					GetUnk44() const = 0;																								// 0C
			virtual const BSFixedString&	GetStr48() const = 0;																								// 0D
			virtual void					MoveVariablesToStack(StackFrame* a_frame) = 0;																		// 0E
			virtual UInt32					Invoke(BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) = 0;	// 0F
			virtual const BSFixedString&	GetSource() const = 0;																								// 10
			virtual bool					GetLineNumber(UInt32 a_taskletExecutionOffset, UInt32& a_lineNumber) = 0;											// 11
			virtual bool					GetVarName(UInt32 a_idx, BSFixedString& a_out) const = 0;															// 12
			virtual bool					GetUnk41() const = 0;																								// 13
			virtual void					SetUnk41(bool a_arg) = 0;																							// 14


			// members
			UInt32 unk0C;	// 0C
		};
		STATIC_ASSERT(sizeof(IFunction) == 0x10);
	}
}
