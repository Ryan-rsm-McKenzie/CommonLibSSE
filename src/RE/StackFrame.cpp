#include "RE/StackFrame.h"

#include "RE/BSScriptStack.h"  // BSScriptStack


namespace RE
{
	namespace BSScript
	{
		BSScriptVariable* StackFrame::Get(UInt32 a_idx, UInt32 a_offset)
		{
			return stack->Get(this, a_idx, a_offset);
		}
	}
}
