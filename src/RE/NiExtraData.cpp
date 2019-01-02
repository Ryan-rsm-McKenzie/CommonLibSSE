#include "RE/NiExtraData.h"


namespace RE
{
	NiExtraData* NiExtraData::Create(UInt32 a_size, uintptr_t a_vtbl)
	{
		void* memory = Heap_Allocate(a_size);
		memset(memory, 0, a_size);
		NiExtraData* xData = (NiExtraData*)memory;
		((uintptr_t*)memory)[0] = a_vtbl;
		return xData;
	}
}
