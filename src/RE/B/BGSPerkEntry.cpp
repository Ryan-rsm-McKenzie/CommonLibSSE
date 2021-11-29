#include "RE/B/BGSPerkEntry.h"

namespace RE
{
	std::uint8_t BGSPerkEntry::GetRank() const
	{
		return header.rank;
	}

	std::uint8_t BGSPerkEntry::GetPriority() const
	{
		return header.priority;
	}
}
