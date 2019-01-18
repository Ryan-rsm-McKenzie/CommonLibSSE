#include "RE/TESRace.h"


namespace RE
{
	bool TESRace::AllowsPickpocket() const
	{
		return (data.flags & Data::Flag::kAllowPickpocket) != Data::Flag::kNone;
	}
}
