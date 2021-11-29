#include "RE/M/MemoryPage.h"

namespace RE
{
	namespace BSScript
	{
		void* MemoryPage::GetHead()
		{
			return buf;
		}

		void* MemoryPage::GetTail()
		{
			return stl::adjust_pointer<void>(GetHead(), pageSize);
		}

		bool MemoryPage::IsInRange(const void* a_ptr)
		{
			return GetHead() <= a_ptr && a_ptr < GetTail();
		}
	}
}
