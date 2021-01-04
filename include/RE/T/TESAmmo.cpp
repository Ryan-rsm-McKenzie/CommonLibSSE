#include "RE/T/TESAmmo.h"

namespace RE
{
	bool TESAmmo::IgnoresNormalWeaponResistance()
	{
		return data.flags.all(AMMO_DATA::Flag::kIgnoresNormalWeaponResistance);
	}

	bool TESAmmo::IsBolt()
	{
		return data.flags.none(AMMO_DATA::Flag::kNonBolt);
	}
}
