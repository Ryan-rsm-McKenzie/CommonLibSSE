#include "RE/BSScript/StackFrame.h"

#include "RE/BSScript/Stack.h"


namespace RE
{
	namespace BSScript
	{
		UInt32 StackFrame::GetPageForFrame() const
		{
			return parent->GetPageForFrame(this);
		}


		Variable& StackFrame::GetStackFrameVariable(UInt32 a_index, UInt32 a_pageHint) const
		{
			return parent->GetStackFrameVariable(this, a_index, a_pageHint);
		}
	}
}
