#pragma once

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSScript/MemoryPage.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class CodeTasklet;
		}


		class IProfilePolicy;
		class IStackCallbackFunctor;
		class StackFrame;
		struct IMemoryPagePolicy;


		class Stack : public BSIntrusiveRefCounted
		{
		public:
			enum class State : UInt32
			{
				kRunning = 0,
				kFinished = 1,
				kWaitingOnMemory = 2,
				kWaitingOnLatentFunction = 3,
				kWaitingOnOtherStackForCall = 4,
				kWaitingOnOtherStackForReturn = 5,
				kWaitingOnOtherStackForReturnNoPop = 6,
				kRetryReturnNoPop = 7,
				kRetryCall = 8
			};


			enum class FreezeState : UInt32
			{
				kUnfrozen = 0,
				kFreezing = 1,
				kFrozen = 2
			};


			enum class StackType : UInt32
			{
			};


			struct MemoryPageData
			{
			public:
				// members
				BSTAutoPointer<MemoryPage> page;					// 00
				UInt32					   availableMemoryInBytes;	// 08 - e.g. a function with 1 arg will have 3 unused args, so this will be 0x30, a function with 6 args will have 0 unused args, so this will be 0x0
				UInt32					   pad0C;					// 0C
			};
			STATIC_ASSERT(sizeof(MemoryPageData) == 0x10);


			~Stack();

			UInt32 GetChunkIdx(StackFrame* a_frame);


			// members
			UInt32								   pad04;		   // 04
			IMemoryPagePolicy*					   policy;		   // 08
			IProfilePolicy*						   profilePolicy;  // 10
			BSTSmallArray<MemoryPageData, 3>	   pages;		   // 18
			UInt32								   frames;		   // 58
			UInt32								   pad5C;		   // 5C
			StackFrame*							   top;			   // 60
			State								   state;		   // 68
			FreezeState							   freezeState;	   // 6C
			Variable							   returnValue;	   // 70
			VMStackID							   stackID;		   // 80
			StackType							   stackType;	   // 84
			BSTSmartPointer<Internal::CodeTasklet> owningTasklet;  // 88
			BSTSmartPointer<IStackCallbackFunctor> callback;	   // 90
			BSTSmartPointer<Stack>				   nextStack;	   // 98

		private:
			void Dtor();
		};
		STATIC_ASSERT(sizeof(Stack) == 0xA0);
	}
}
