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
	static_assert(sizeof(NiTList<void*>) == 0x18);
}
