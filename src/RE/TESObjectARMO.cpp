#include "RE/TESObjectARMO.h"


namespace RE
{
	float TESObjectARMO::GetArmorRating()
	{
		return static_cast<float>(armorRating) / static_cast<float>(100.0);
	}
}
