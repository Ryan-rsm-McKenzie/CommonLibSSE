#include "RE/BSHavok/hkMemoryAllocator/hkContainerAllocators.h"


namespace RE
{
	hkContainerHeapAllocator::Allocator* hkContainerHeapAllocator::GetSingleton()
	{
		REL::Relocation<hkContainerHeapAllocator::Allocator*> singleton{ RE::Offset::hkContainerHeapAllocator::Singleton };
		return singleton.type();
	}
}
