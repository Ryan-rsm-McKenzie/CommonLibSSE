#include "RE/hkContainerAllocators.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	hkContainerHeapAllocator::Allocator* hkContainerHeapAllocator::GetSingleton()
	{
		REL::Offset<hkContainerHeapAllocator::Allocator*> singleton(RE::Offset::hkContainerHeapAllocator::Singleton);
		return singleton.GetType();
	}
}
