#include "RE/B/BGSSoundCategory.h"

namespace RE
{
	float BGSSoundCategory::GetDefaultMenuValue() const
	{
		return static_cast<float>(defaultMenuValue / std::numeric_limits<std::uint16_t>::max());
	}

	float BGSSoundCategory::GetStaticVolumeMultiplier() const
	{
		return static_cast<float>(staticMult / std::numeric_limits<std::uint16_t>::max());
	}

	bool BGSSoundCategory::IsMenuCategory() const
	{
		return flags.all(Flag::kShouldAppearOnMenu);
	}

	void BGSSoundCategory::SetDefaultMenuValue(float a_val)
	{
		defaultMenuValue = static_cast<std::uint16_t>(a_val * std::numeric_limits<std::uint16_t>::max());
	}

	void BGSSoundCategory::SetStaticVolumeMultiplier(float a_val)
	{
		staticMult = static_cast<std::uint16_t>(a_val * std::numeric_limits<std::uint16_t>::max());
	}
}
