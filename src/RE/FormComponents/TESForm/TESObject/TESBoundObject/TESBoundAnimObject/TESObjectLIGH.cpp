#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectLIGH.h"


namespace RE
{
	bool TESObjectLIGH::CanBeCarried() const
	{
		return data.flags.all(TES_LIGHT_FLAGS::kCanCarry);
	}
}
