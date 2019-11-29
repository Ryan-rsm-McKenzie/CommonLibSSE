#include "RE/BGSEntryPointPerkEntry.h"


namespace RE
{
	bool BGSEntryPointPerkEntry::IsEntryPoint(EntryPoint a_entryPoint) const
	{
		return entryData.entryPoint == a_entryPoint;
	}


	UInt32 BGSEntryPointPerkEntry::GetNumConditions() const
	{
		return *reinterpret_cast<UInt32*>(reinterpret_cast<std::uintptr_t>(conditions) - sizeof(void*));
	}
}
