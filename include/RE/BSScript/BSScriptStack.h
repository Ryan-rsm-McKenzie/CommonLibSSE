#pragma once

#include "RE/BSScript/BSScriptVariable.h"  // BSScriptVariable
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


		class StackFrame;
		struct IMemoryPagePolicy;


		class BSScriptStack : public BSIntrusiveRefCounted
		{
		public:
			UInt32				GetOffset(StackFrame* a_frame);
			BSScriptVariable*	Get(StackFrame* a_frame, UInt32 a_idx, UInt32 a_offset);


			// members
			UInt32					unk04;				// 04
			IMemoryPagePolicy*		memoryPagePolicy;	// 08
			UInt64					unk10;				// 10
			BSTSmallArray<void*, 3>	chunks;				// 18
			UInt64					unk40;				// 40
			UInt64					unk48;				// 48
			UInt64					unk50;				// 50
			UInt64					unk58;				// 58
			StackFrame*				current;			// 60
			UInt64					unk68;				// 68
			BSScriptVariable		resultValue;		// 70
			UInt32					stackID;			// 80
			UInt32					unk84;				// 84
			Internal::CodeTasklet*	codeTasklet;		// 88
			UInt64					unk90;				// 90
			UInt64					unk98;				// 98
		};
		STATIC_ASSERT(sizeof(BSScriptStack) == 0xA0);
	}
}
