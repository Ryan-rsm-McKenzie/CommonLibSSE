#pragma once

#include "RE/NetImmerse/NiTDefaultAllocator.h"
#include "RE/NetImmerse/NiTListBase/NiTPointerListBase/NiTPointerListBase.h"


namespace RE
{
	template <class T>
	class NiTList : public NiTPointerListBase<NiTDefaultAllocator<T>, T>
	{
	public:
	};
	STATIC_ASSERT(sizeof(NiTList<void*>) == 0x18);
}
