#include "RE/BSScript/MemoryPage.h"


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
			auto head = reinterpret_cast<std::uintptr_t>(GetHead());
			return reinterpret_cast<void*>(head + pageSize);
		}


		bool MemoryPage::IsInRange(void* a_ptr)
		{
			return a_ptr <= GetHead() && a_ptr < GetTail();
		}
	}
}
