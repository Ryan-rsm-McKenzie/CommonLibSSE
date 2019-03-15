#include "RE/BSExtraData.h"

#include <cstdint>  // uintptr_t
#include <cstring>  // memset


namespace RE
{
	BSExtraData* BSExtraData::Create(UInt32 a_size, uintptr_t a_vtbl)
	{
		void* memory = Heap_Allocate(a_size);
		std::memset(memory, 0, a_size);
		((std::uintptr_t*)memory)[0] = a_vtbl;
		BSExtraData* xData = (BSExtraData*)memory;
		return xData;
	}
}
