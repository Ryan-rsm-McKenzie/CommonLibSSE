#pragma once

#include "RE/BSScript/Variable.h"  // BSScript::Variable


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class ScriptFunction;
		}


		class Stack;


		class StackFrame
		{
		public:
			Variable* Get(UInt32 a_idx, UInt32 a_chunkIdx);


			Stack*						stack;					// 00
			StackFrame*					parent;					// 08
			Internal::ScriptFunction*	func;					// 10
			Class*						scriptClass;			// 18
			UInt32						taskletExecutionOffset;	// 20
			UInt32						unk24;					// 24
			Variable					baseValue;				// 28
			UInt32						numArgs;				// 38
			bool						unk3C;					// 3C
			UInt8						pad3D;					// 3D
			UInt16						pad3E;					// 3E
			Variable					args[4];				// 40 - minimum space for 4 args is allocated
		};
		STATIC_ASSERT(sizeof(StackFrame) == 0x80);	// frames can be larger
	}
}
