#pragma once

#include "RE/NiTDefaultAllocator.h"
#include "RE/NiTPointerListBase.h"


namespace RE
{
	template <class T>
	class NiTList : public NiTPointerListBase<NiTDefaultAllocator<T>, T>
	{
	public:
	};
	STATIC_ASSERT(sizeof(NiTList<void*>) == 0x18);
}
