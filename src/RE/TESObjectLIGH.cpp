#include "RE/TESObjectLIGH.h"


namespace RE
{
	bool TESObjectLIGH::CanBeCarried() const
	{
		return (unkE0.flags & kFlag_Carryable) != 0;
	}
}
