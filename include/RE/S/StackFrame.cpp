#include "RE/BSScript/StackFrame.h"

#include "RE/BSScript/Stack.h"


namespace RE
{
	namespace BSScript
	{
		std::uint32_t StackFrame::GetPageForFrame() const
		{
			return parent->GetPageForFrame(this);
		}


		Variable& StackFrame::GetStackFrameVariable(std::uint32_t a_index, std::uint32_t a_pageHint) const
		{
			return parent->GetStackFrameVariable(this, a_index, a_pageHint);
		}
	}
}
