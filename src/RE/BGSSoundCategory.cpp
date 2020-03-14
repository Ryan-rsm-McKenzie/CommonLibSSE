#include "RE/BGSSoundCategory.h"

#include <numeric>


namespace RE
{
	float BGSSoundCategory::GetDefaultMenuValue() const
	{
		return static_cast<float>(defaultMenuValue / std::numeric_limits<UInt16>::max());
	}


	float BGSSoundCategory::GetStaticVolumeMultiplier() const
	{
		return static_cast<float>(staticMult / std::numeric_limits<UInt16>::max());
	}


	bool BGSSoundCategory::IsMenuCategory() const
	{
		return (flags & Flag::kShouldAppearOnMenu) != Flag::kNone;
	}


	void BGSSoundCategory::SetDefaultMenuValue(float a_val)
	{
		defaultMenuValue = static_cast<UInt16>(a_val * std::numeric_limits<UInt16>::max());
	}


	void BGSSoundCategory::SetStaticVolumeMultiplier(float a_val)
	{
		staticMult = static_cast<UInt16>(a_val * std::numeric_limits<UInt16>::max());
	}
}
