#pragma once

#include "RE/G/GMemory.h"
#include "RE/G/GMemoryHeap.h"
#include "RE/G/GString.h"

namespace RE
{
	class GStringDH : public GString
	{
	public:
		GStringDH(GMemoryHeap* a_heap = GMemory::GetGlobalHeap()) :
			heap(a_heap)
		{}

		GStringDH(GMemoryHeap* a_heap, const char* a_data) :
			GString(a_data),
			heap(a_heap)
		{}

		// members
		GMemoryHeap* heap;  // 08
	};
	static_assert(sizeof(GStringDH) == 0x10);
}
