#include "RE/BSScript/Stack.h"

#include "RE/BSScript/IStackCallbackFunctor.h"
#include "RE/BSScript/Internal/CodeTasklet.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		Stack::~Stack()
		{
			Dtor();
			memzero(this);
		}


		UInt32 Stack::GetChunkIdx(StackFrame* a_frame)
		{
			for (UInt32 i = 0; i < pages.size(); ++i) {
				auto& pair = pages[i];
				if (pair.page->IsInRange(a_frame)) {
					return i;
				}
			}
			assert(false);
			return static_cast<UInt32>(-1);
		}


		void Stack::Dtor()
		{
			using func_t = decltype(&Stack::Dtor);
			REL::Offset<func_t> func(Offset::BSScript::Stack::Dtor);
			return func(this);
		}
	}
}
