#include "RE/T/TESObjectARMA.h"
#include "RE/T/TESObjectARMO.h"

namespace RE
{
	TESObjectARMA* TESObjectARMO::GetArmorAddonByMask(TESRace* a_race, BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		if (a_race) {
			for (auto& addon : armorAddons) {
				if (addon && addon->IsValidRace(a_race) && (addon->GetSlotMask() & a_slot) == a_slot) {
					return addon;
				}
			}
		}

		return nullptr;
	}

	float TESObjectARMO::GetArmorRating()
	{
		return static_cast<float>(armorRating) / static_cast<float>(100.0);
	}
}
