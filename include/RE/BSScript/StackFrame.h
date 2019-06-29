#pragma once

#include "RE/BSScript/BSScriptVariable.h"  // BSScript::BSScriptVariable


namespace RE
{
	namespace BSScript
	{
		class BSScriptStack;
		class IFunction;


		class StackFrame
		{
		public:
			BSScriptVariable* Get(UInt32 a_idx, UInt32 a_offset);


			BSScriptStack*		stack;		// 00
			StackFrame*			parent;		// 08
			IFunction*			func;		// 10
			void*				unk0C;		// 18
			UInt64				unk10;		// 20
			BSScriptVariable	baseValue;	// 28
			UInt32				numArgs;	// 38
			UInt32				pad3C;		// 3C
			//BSScriptVariable	args[0];	// 40
		};
		STATIC_ASSERT(sizeof(StackFrame) == 0x40);
	}
}
