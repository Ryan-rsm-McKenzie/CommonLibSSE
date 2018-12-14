#include "RE/BSExtraData.h"


namespace RE
{
	BSExtraData* BSExtraData::Create(UInt32 a_size, uintptr_t a_vtbl)
	{
		void* memory = Heap_Allocate(a_size);
		memset(memory, 0, a_size);
		((uintptr_t*)memory)[0] = a_vtbl;
		BSExtraData* xData = (BSExtraData*)memory;
		return xData;
	}
}
