#include "RE/TESObjectLIGH.h"


namespace RE
{
	float TESObjectLIGH::Data::FlickerEffect::GetPeriod() const
	{
		return period * 100.0;
	}


	bool TESObjectLIGH::CanBeCarried() const
	{
		return (data.flags & Data::Flag::kCanBeCarried) != Data::Flag::kNone;
	}
}
