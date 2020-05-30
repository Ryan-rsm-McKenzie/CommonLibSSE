#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTSmartPointer.h"


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
		class TypeInfo;
		class VMState;


		class IFunction : public BSIntrusiveRefCounted
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IFunction;


			enum class FunctionType : UInt32
			{
				kNormal = 0,
				kGetter = 1,
				kSetter = 2
			};


			enum class FunctionType16 : UInt16
			{
				kNormal = 0,
				kGetter = 1,
				kSetter = 2
			};


			enum class CallResult : UInt32
			{
				kCompleted = 0,
				kSetupForVM = 1,
				kInProgress = 2,
				kFailedRetry = 3,
				kFailedAbort = 4
			};


			IFunction();
			virtual ~IFunction() = default;	 // 00

			// add
			virtual const BSFixedString& GetName() const = 0;																								   // 01
			virtual const BSFixedString& GetObjectTypeName() const = 0;																						   // 02
			virtual const BSFixedString& GetStateName() const = 0;																							   // 03
			virtual TypeInfo			 GetReturnType() const = 0;																							   // 04
			virtual UInt32				 GetParamCount() const = 0;																							   // 05
			virtual void				 GetParam(UInt32 a_idx, BSFixedString& a_nameOut, TypeInfo& a_typeOut) const = 0;									   // 06
			virtual UInt32				 GetStackFrameSize() const = 0;																						   // 07
			virtual bool				 GetIsNative() const = 0;																							   // 08
			virtual bool				 GetIsStatic() const = 0;																							   // 09
			virtual bool				 GetIsEmpty() const = 0;																							   // 0A
			virtual FunctionType		 GetFunctionType() const = 0;																						   // 0B
			virtual UInt32				 GetUserFlags() const = 0;																							   // 0C
			virtual const BSFixedString& GetDocString() const = 0;																							   // 0D
			virtual void				 InsertLocals(StackFrame* a_frame) = 0;																				   // 0E
			virtual CallResult			 Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger* a_logger, Internal::VirtualMachine* a_vm, bool a_arg4) = 0;  // 0F
			virtual const BSFixedString& GetSourceFilename() const = 0;																						   // 10
			virtual bool				 TranslateIPToLineNumber(UInt32 a_indexPtr, UInt32& a_lineNumberOut) const = 0;										   // 11
			virtual bool				 GetVarNameForStackIndex(UInt32 a_idx, BSFixedString& a_nameOut) const = 0;											   // 12
			virtual bool				 CanBeCalledFromTasklets() const = 0;																				   // 13
			virtual void				 SetCallableFromTasklets(bool a_callable) = 0;																		   // 14


			// members
			UInt32 pad0C;  // 0C
		};
		STATIC_ASSERT(sizeof(IFunction) == 0x10);
	}
}
