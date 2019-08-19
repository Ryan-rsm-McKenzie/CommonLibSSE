#pragma once

#include "RE/BSScript/Variable.h"  // BSScript::Variable
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTArray.h"  // BSTSmallArray


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class CodeTasklet;
		}


		class IStackCallbackFunctor;
		class SimpleAllocMemoryPagePolicy;
		class StackFrame;


		class Stack : public BSIntrusiveRefCounted
		{
		public:
			// All stack frame pointers are offset by 4
			// The actual stack frame is kept here
			struct Chunk
			{
				StackFrame* GetStackFrame();


				UInt32	stackFrameSize;	// 00 - minimum size of 0x80, but can be larger
				char	buf[0x80];		// 04
			};
			STATIC_ASSERT(sizeof(Chunk) == 0x84);	// chunks can be larger


			struct Pair
			{
				Chunk*	chunk;			// 00
				UInt32	unusedArgSize;	// 08 - e.g. a function with 1 arg will have 3 unused args, so this will be 0x30, a function with 6 args will have 0 unused args, so this will be 0x0
				UInt32	pad0C;			// 0C
			};
			STATIC_ASSERT(sizeof(Pair) == 0x10);


			~Stack();

			UInt32		GetChunkIdx(StackFrame* a_frame);
			Variable*	Get(StackFrame* a_frame, UInt32 a_idx, UInt32 a_chunkIdx);


			// members
			UInt32									unk04;				// 04
			SimpleAllocMemoryPagePolicy*			memoryPagePolicy;	// 08
			void*									unk10;				// 10
			BSTSmallArray<Pair, 3>					chunks;				// 18
			UInt32									numChunks;			// 58
			UInt32									unk5C;				// 5C
			StackFrame*								current;			// 60
			UInt64									unk68;				// 68
			Variable								resultValue;		// 70
			UInt32									stackID;			// 80
			UInt32									unk84;				// 84
			BSTSmartPointer<Internal::CodeTasklet>	codeTasklet;		// 88
			BSTSmartPointer<IStackCallbackFunctor>	callbackFunctor;	// 90
			BSTSmartPointer<Stack>					unk98;				// 98

		private:
			void Dtor();
		};
		STATIC_ASSERT(sizeof(Stack) == 0xA0);
	}
}
