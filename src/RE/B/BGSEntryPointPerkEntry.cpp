#include "RE/B/BGSEntryPointPerkEntry.h"

namespace RE
{
	bool BGSEntryPointPerkEntry::IsEntryPoint(EntryPoint a_entryPoint) const
	{
		return entryData.entryPoint == a_entryPoint;
	}
}
