#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MemoryPage.h"
#include "RE/V/Variable.h"

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
		class Variable;
		struct IMemoryPagePolicy;

		class Stack : public BSIntrusiveRefCounted
		{
		public:
			enum class State
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

			enum class FreezeState
			{
				kUnfrozen = 0,
				kFreezing = 1,
				kFrozen = 2
			};

			enum class StackType
			{
			};

			struct MemoryPageData
			{
			public:
				// members
				BSTAutoPointer<MemoryPage> page;					// 00
				std::uint32_t			   availableMemoryInBytes;	// 08 - e.g. a function with 1 arg will have 3 unused args, so this will be 0x30, a function with 6 args will have 0 unused args, so this will be 0x0
				std::uint32_t			   pad0C;					// 0C
			};
			static_assert(sizeof(MemoryPageData) == 0x10);

			~Stack();

			std::uint32_t GetPageForFrame(const StackFrame* a_frame) const;
			Variable&	  GetStackFrameVariable(const StackFrame* a_frame, std::uint32_t a_index, std::uint32_t a_pageHint);

			// members
			std::uint32_t								 pad04;			 // 04
			IMemoryPagePolicy*							 policy;		 // 08
			IProfilePolicy*								 profilePolicy;	 // 10
			BSTSmallArray<MemoryPageData, 3>			 pages;			 // 18
			std::uint32_t								 frames;		 // 58
			std::uint32_t								 pad5C;			 // 5C
			StackFrame*									 top;			 // 60
			stl::enumeration<State, std::uint32_t>		 state;			 // 68
			stl::enumeration<FreezeState, std::uint32_t> freezeState;	 // 6C
			Variable									 returnValue;	 // 70
			VMStackID									 stackID;		 // 80
			stl::enumeration<StackType, std::uint32_t>	 stackType;		 // 84
			BSTSmartPointer<Internal::CodeTasklet>		 owningTasklet;	 // 88
			BSTSmartPointer<IStackCallbackFunctor>		 callback;		 // 90
			BSTSmartPointer<Stack>						 nextStack;		 // 98

		private:
			void Dtor();
		};
		static_assert(sizeof(Stack) == 0xA0);
	}
}
