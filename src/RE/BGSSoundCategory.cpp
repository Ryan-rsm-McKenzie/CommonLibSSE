#include "RE/BGSSoundCategory.h"


namespace RE
{
	float BGSSoundCategory::GetDefaultMenuValue() const
	{
		return defaultMenuValue / USHRT_MAX;
	}


	float BGSSoundCategory::GetStaticVolumeMultiplier() const
	{
		return staticMult / USHRT_MAX;
	}


	bool BGSSoundCategory::IsMenuCategory() const
	{
		return (flags & Flag::kShouldAppearOnMenu) != Flag::kNone;
	}


	void BGSSoundCategory::SetDefaultMenuValue(float a_val)
	{
		defaultMenuValue = static_cast<UInt16>(a_val * USHRT_MAX);
	}


	void BGSSoundCategory::SetStaticVolumeMultiplier(float a_val)
	{
		staticMult = static_cast<UInt16>(a_val * USHRT_MAX);
	}
}
