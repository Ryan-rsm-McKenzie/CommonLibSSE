#include "RE/S/Stack.h"

#include "RE/C/CodeTasklet.h"
#include "RE/I/IStackCallbackFunctor.h"

namespace RE
{
	namespace BSScript
	{
		Stack::~Stack()
		{
			Dtor();
			memzero(this);
		}

		std::uint32_t Stack::GetPageForFrame(const StackFrame* a_frame) const
		{
			for (std::uint32_t i = 0; i < pages.size(); ++i) {
				auto& pair = pages[i];
				if (pair.page->IsInRange(a_frame)) {
					return i;
				}
			}
			assert(false);
			return static_cast<std::uint32_t>(-1);
		}

		Variable& Stack::GetStackFrameVariable(const StackFrame* a_frame, std::uint32_t a_index, std::uint32_t a_pageHint)
		{
			using func_t = decltype(&Stack::GetStackFrameVariable);
			REL::Relocation<func_t> func{ REL::ID(97746) };
			return func(this, a_frame, a_index, a_pageHint);
		}

		void Stack::Dtor()
		{
			using func_t = decltype(&Stack::Dtor);
			REL::Relocation<func_t> func{ REL::ID(97742) };
			return func(this);
		}
	}
}
