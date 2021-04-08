#include "RE/B/BGSImpactManager.h"

namespace RE
{
	BGSImpactManager* BGSImpactManager::GetSingleton()
	{
		REL::Relocation<BGSImpactManager**> singleton{ REL::ID(515123) };
		return *singleton;
	}

	bool BGSImpactManager::PlayImpactEffect(TESObjectREFR* a_objectReference, BGSImpactDataSet* a_impactEffect, const char* a_nodeName, NiPoint3 a_pickDirection, float a_pickLength, bool a_applyNodeRotation, bool a_useNodeLocalRotation)
	{
		using func_t = decltype(&BGSImpactManager::PlayImpactEffect);
		REL::Relocation<func_t> func{ REL::ID(35320) };
		return func(this, a_objectReference, a_impactEffect, a_nodeName, a_pickDirection, a_pickLength, a_applyNodeRotation, a_useNodeLocalRotation);
	}

	bool BGSImpactManager::PlaySound(IMPACT_SOUND_DATA& a_impactSoundData)
	{
		using func_t = decltype(&BGSImpactManager::PlaySound);
		REL::Relocation<func_t> func{ REL::ID(35317) };
		return func(this, a_impactSoundData);
	}
}
