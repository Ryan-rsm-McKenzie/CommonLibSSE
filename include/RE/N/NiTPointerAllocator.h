#pragma once

#include "RE/N/NiTCollection.h"

namespace RE
{
	template <class T>
	class NiTPointerAllocator
	{
	public:
		class AllocNode
		{
		public:
			AllocNode* next;     // 00
			void*      data;     // 08
			T          element;  // 10
		};

		void* Allocate()
		{
			return NiMalloc(sizeof(AllocNode));
		}

		void Deallocate(void* a_ptr)
		{
			return NiFree(a_ptr);
		}
	};
}
