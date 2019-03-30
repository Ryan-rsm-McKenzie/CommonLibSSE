#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class VirtualMachine;
		}


		class BSScriptStackPtr;
		class BSScriptType;
		class ErrorLogger;
		class VMState;


		class IFunction : public BSIntrusiveRefCounted
		{
		public:
			virtual ~IFunction();																															// 00

			// add
			virtual const BSFixedString&	GetFunctionName() const = 0;																					// 01
			virtual const BSFixedString&	GetScriptName() const = 0;																						// 02
			virtual const BSFixedString&	GetStateName() const = 0;																						// 03
			virtual void					GetReturnType(BSScriptType& a_dst) const = 0;																	// 04
			virtual UInt32					GetNumParams() const = 0;																						// 05
			virtual BSScriptType&			GetParam(UInt32 a_idx, BSFixedString& a_nameOut, BSScriptType& a_typeOut) const = 0;							// 06
			virtual UInt32					GetNumParams2() const = 0;																						// 07
			virtual bool					IsNative() const = 0;																							// 08
			virtual bool					IsStatic() const = 0;																							// 09
			virtual bool					IsEvent() const = 0;																							// 0A
			virtual UInt32					Unk_0B() = 0;																									// 0B
			virtual UInt32					GetUnk44() const = 0;																							// 0C
			virtual const BSFixedString&	GetStr48() const = 0;																							// 0D
			virtual void					Unk_0E(UInt32 a_arg1) = 0;																						// 0E
			virtual UInt32					Invoke(BSScriptStackPtr& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, UInt32 a_arg4) = 0;	// 0F
			virtual const BSFixedString&	GetSource() const = 0;																							// 10
			virtual bool					Unk_11(UInt32 a_arg1, UInt32* a_arg2) = 0;																		// 11
			virtual bool					GetParamName(UInt32 a_idx, BSFixedString& a_out) const = 0;														// 12
			virtual bool					GetUnk41() const = 0;																							// 13
			virtual void					SetUnk41(bool a_arg) = 0;																						// 14
		};
		STATIC_ASSERT(sizeof(IFunction) == 0x10);
	}
}
