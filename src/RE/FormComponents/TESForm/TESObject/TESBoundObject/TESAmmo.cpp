#include "RE/TESAmmo.h"


namespace RE
{
	bool TESAmmo::IgnoresNormalWeaponResistance()
	{
		return (data.flags & AMMO_DATA::Flag::kIgnoresNormalWeaponResistance) != AMMO_DATA::Flag::kNone;
	}


	bool TESAmmo::IsBolt()
	{
		return (data.flags & AMMO_DATA::Flag::kNonBolt) == AMMO_DATA::Flag::kNone;
	}
}
