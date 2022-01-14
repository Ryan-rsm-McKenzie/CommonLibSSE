#include "RE/T/TESRace.h"

namespace RE
{
	bool TESRace::AllowsPCDialogue() const
	{
		return data.flags.all(RACE_DATA::Flag::kAllowPCDialogue);
	}

	bool TESRace::AllowsPickpocket() const
	{
		return data.flags.all(RACE_DATA::Flag::kAllowPickpocket);
	}

	bool TESRace::IsChildRace() const
	{
		return data.flags.all(RACE_DATA::Flag::kChild);
	}
}
