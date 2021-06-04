#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		// All stack frame pointers are offset by 4
		// The actual stack frame is kept here
		struct MemoryPage
		{
			TES_HEAP_REDEFINE_NEW();

			template <class T>
			T* GetData()
			{
				return reinterpret_cast<T*>(buf);
			}

			void* GetHead();
			void* GetTail();
			bool  IsInRange(const void* a_ptr);

			// members
			std::uint32_t pageSize;  // 00
			char          buf[0];    // 04
		};
		static_assert(sizeof(MemoryPage) == 0x4);  // pages can be larger
	}
}
