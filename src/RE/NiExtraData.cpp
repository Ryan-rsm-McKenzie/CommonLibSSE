#include "RE/NiExtraData.h"

#include <cstring>  // memset

#include "RE/TESMemoryManager.h"


namespace RE
{
	NiExtraData* NiExtraData::Create(std::size_t a_size, std::uintptr_t a_vtbl)
	{
		void* memory = malloc(a_size);
		std::memset(memory, 0, a_size);
		NiExtraData* xData = (NiExtraData*)memory;
		((std::uintptr_t*)memory)[0] = a_vtbl;
		return xData;
	}
}
