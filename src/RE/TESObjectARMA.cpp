#include "RE/TESObjectARMA.h"

#include <cassert>

#include "RE/FormTraits.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectARMO.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESRace.h"


namespace RE
{
	bool HasArmorRace(const TESRace* a_sourceRace, const TESRace* a_targetRace)
	{
		if (a_sourceRace == a_targetRace) {
			return true;
		}

		// Check if this race inherits the source race
		TESRace* armorRace = a_sourceRace->armorParentRace;
		while (armorRace) {
			if (armorRace == a_targetRace) {
				return true;
			}
			armorRace = armorRace->armorParentRace;
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


	void TESObjectARMA::GetNodeName(char* a_dstBuff, const TESObjectREFR* a_refr, const TESObjectARMO* a_armor, float a_weightOverride)
	{
		assert(a_refr);

		float weight = 100.0F;
		auto baseObj = a_refr->GetBaseObject();
		auto npc = baseObj ? baseObj->As<TESNPC>() : nullptr;
		if (npc) {
			npc = npc->GetRootFaceNPC();
			weight = npc->weight;
		} else {
			weight = a_refr->GetWeight();
		}

		// Determines whether to factor weight into the name, -1 true, 1 false
		if (a_weightOverride >= 0.0F) {
			weight = a_weightOverride * 100.0F;
		}

		UInt32 sex = npc ? static_cast<UInt32>(npc->GetSex()) : 0;
		sprintf_s(a_dstBuff, MAX_PATH, " (%08X)[%d]/ (%08X) [%2.0f%%]", GetFormID(), sex, a_armor->GetFormID(), weight);
	}
}
