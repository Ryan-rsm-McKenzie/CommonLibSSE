#include "RE/TESRace.h"


namespace RE
{
	bool TESRace::AllowsPCDialogue() const
	{
		return (data.flags & RACE_DATA::Flag::kAllowPCDialogue) != RACE_DATA::Flag::kNone;
	}


	bool TESRace::AllowsPickpocket() const
	{
		return (data.flags & RACE_DATA::Flag::kAllowPickpocket) != RACE_DATA::Flag::kNone;
	}
}
