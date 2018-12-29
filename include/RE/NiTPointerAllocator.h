#pragma once

#include "RE/NiMemory.h"  // NiMalloc, NiFree
namespace RE
{
	template <class Ty>
	class NiTPointerAllocator
	{
	public:
		class AllocNode
		{
		public:
			AllocNode*	next;
			void*		data;
			Ty			element;
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
	using TestNiTPointerAllocator = NiTPointerAllocator<uint64_t>;
	STATIC_ASSERT(offsetof(TestNiTPointerAllocator, next) == 0x00);
	STATIC_ASSERT(offsetof(TestNiTPointerAllocator, data) == 0x08);
	STATIC_ASSERT(offsetof(TestNiTPointerAllocator, element) == 0x10);
	STATIC_ASSERT(sizeof(TestNiTPointerAllocator) == 0x18);
}
