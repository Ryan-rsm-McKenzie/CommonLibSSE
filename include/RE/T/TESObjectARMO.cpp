#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectARMO.h"


namespace RE
{
	float TESObjectARMO::GetArmorRating()
	{
		return static_cast<float>(armorRating) / static_cast<float>(100.0);
	}
}
