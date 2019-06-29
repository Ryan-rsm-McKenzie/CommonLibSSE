#include "RE/BSScript/StackFrame.h"

#include "RE/BSScript/BSScriptStack.h"  // BSScript::BSScriptStack


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
