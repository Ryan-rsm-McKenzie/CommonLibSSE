#include "RE/BSExtraData.h"

#include <cstring>  // memset

#include "RE/Memory.h"  // malloc


namespace RE
{
	BSExtraData* BSExtraData::Create(std::size_t a_size, std::uintptr_t a_vtbl)
	{
		void* memory = malloc(a_size);
		std::memset(memory, 0, a_size);
		((std::uintptr_t*)memory)[0] = a_vtbl;
		BSExtraData* xData = static_cast<BSExtraData*>(memory);
		return xData;
	}
}
