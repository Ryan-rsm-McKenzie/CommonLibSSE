#pragma once

#include "RE/MemoryManager.h"


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
			bool  IsInRange(void* a_ptr);


			// members
			UInt32 pageSize;  // 00
			char   buf[0];	  // 04
		};
		STATIC_ASSERT(sizeof(MemoryPage) == 0x4);  // pages can be larger
	}
}
