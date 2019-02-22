#include "RE/TESAmmo.h"


namespace RE
{
	bool TESAmmo::IgnoresNormalWeaponResistance()
	{
		return (data.flags & Data::Flag::kIgnoresNormalWeaponResistance) != Data::Flag::kNone;
	}


	bool TESAmmo::IsBolt()
	{
		return (data.flags & Data::Flag::kNonBolt) == Data::Flag::kNone;
	}
}
