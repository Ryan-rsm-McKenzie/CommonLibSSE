#include "RE/BSScript/StackFrame.h"

#include "RE/BSScript/Stack.h"  // BSScript::Stack


namespace RE
{
	namespace BSScript
	{
		Variable* StackFrame::Get(UInt32 a_idx, UInt32 a_chunkIdx)
		{
			return stack->Get(this, a_idx, a_chunkIdx);
		}
	}
}
