#include "RE/TESRace.h"


namespace RE
{
	bool TESRace::AllowsPickpocket() const
	{
		return (data.flags & RACE_DATA::Flag::kAllowPickpocket) != RACE_DATA::Flag::kNone;
	}
}
