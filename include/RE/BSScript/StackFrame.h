#pragma once

#include "RE/BSScript/Variable.h"  // BSScript::Variable


namespace RE
{
	namespace BSScript
	{
		class IFunction;
		class Stack;


		class StackFrame
		{
		public:
			Variable* Get(UInt32 a_idx, UInt32 a_chunkIdx);


			Stack*		stack;			// 00
			StackFrame*	parent;			// 08
			IFunction*	func;			// 10
			Class*		scriptClass;	// 18
			UInt64		unk20;			// 20
			Variable	baseValue;		// 28
			UInt32		numArgs;		// 38
			UInt32		unk3C;			// 3C
			Variable	args[4];		// 40 - minimum space for 4 args is allocated
		};
		STATIC_ASSERT(sizeof(StackFrame) == 0x80);	// frames can be larger
	}
}
