#pragma once

#include "RE/NiMemory.h"  // NiMalloc, NiFree

#define NiTDefaultAllocator DFALL


namespace RE
{
	template <class Ty>
	class NiTDefaultAllocator
	{
	public:
		void* Allocate()
		{
			return NiMalloc(sizeof(Ty));
		}


		void Deallocate(void* a_ptr)
		{
			return NiFree(a_ptr);
		}
	};
}
