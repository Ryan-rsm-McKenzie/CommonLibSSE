#include "RE/TESObjectARMA.h"

#include "RE/FormTraits.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectARMO.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESRace.h"


namespace RE
{
	bool HasArmorRace(TESRace* a_sourceRace, TESRace* a_targetRace)
	{
		if (a_sourceRace == a_targetRace) {
			return true;
		}

		// Check if this race inherits the source race
		TESRace* armorRace = a_sourceRace->armorRace;
		while (armorRace) {
			if (armorRace == a_targetRace) {
				return true;
			}
			armorRace = armorRace->armorRace;
		}

		return false;
	}


	bool TESObjectARMA::IsValidRace(TESRace* a_sourceRace) const
	{
		// Found race is the race this armor is designed for, or inherits a race this armor is designed for
		if (HasArmorRace(a_sourceRace, race)) {
			return true;
		}

		for (auto& targetRace : additionalRaces) {
			// Source race is a found race, or inherits one of the found races
			if (HasArmorRace(a_sourceRace, targetRace)) {
				return true;
			}
		}

		return false;
	}


	void TESObjectARMA::GetNodeName(char* a_dstBuff, TESObjectREFR* a_refr, TESObjectARMO* a_armor, float a_weightOverride)
	{
		float weight = 100.0;
		auto npc = a_refr->baseForm->As<TESNPC*>();
		if (npc && npc->nextTemplate) {
			auto templ = npc->GetRootTemplate();
			if (templ) {
				weight = templ->weight;
			}
		} else {
			weight = a_refr->GetWeight();
		}

		// Determines whether to factor weight into the name, -1 true, 1 false
		if (a_weightOverride >= 0.0) {
			weight = a_weightOverride * 100.0;
		}

		UInt32 sex = npc ? static_cast<UInt32>(npc->GetSex()) : 0;
		sprintf_s(a_dstBuff, MAX_PATH, " (%08X)[%d]/ (%08X) [%2.0f%%]", formID, sex, a_armor->formID, weight);
	}
}
