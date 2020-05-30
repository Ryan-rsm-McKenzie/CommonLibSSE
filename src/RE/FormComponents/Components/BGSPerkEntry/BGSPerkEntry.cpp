#include "RE/BGSPerkEntry.h"


namespace RE
{
	UInt8 BGSPerkEntry::GetRank() const
	{
		return header.rank;
	}


	UInt8 BGSPerkEntry::GetPriority() const
	{
		return header.priority;
	}
}
