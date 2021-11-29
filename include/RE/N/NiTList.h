#pragma once

#include "RE/N/NiTDefaultAllocator.h"
#include "RE/N/NiTPointerListBase.h"

namespace RE
{
	template <class T>
	class NiTList : public NiTPointerListBase<NiTDefaultAllocator<T>, T>
	{
	public:
	};
	static_assert(sizeof(NiTList<void*>) == 0x18);
}
