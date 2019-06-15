#pragma once

#include "RE/NiTCollection.h"  // NiMalloc, NiFree


namespace RE
{
	template <class T>
	class NiTPointerAllocator
	{
	public:
		class AllocNode
		{
		public:
			AllocNode*	next;		// 00
			void*		data;		// 08
			T			element;	// 10
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
	STATIC_ASSERT(offsetof(TestNiTPointerAllocator::AllocNode, next) == 0x00);
	STATIC_ASSERT(offsetof(TestNiTPointerAllocator::AllocNode, data) == 0x08);
	STATIC_ASSERT(offsetof(TestNiTPointerAllocator::AllocNode, element) == 0x10);
	STATIC_ASSERT(sizeof(TestNiTPointerAllocator::AllocNode) == 0x18);
}
