#include "RE/B/BGSDecalManager.h"

namespace RE
{
	BGSDecalManager* BGSDecalManager::GetSingleton()
	{
		REL::Relocation<BGSDecalManager**> singleton{ REL::ID(514414) };
		return *singleton;
	}

	bool BGSDecalManager::IsApplyingDecal()
	{
		REL::Relocation<bool*> isApplyingDecal{ REL::ID(525040) };
		return *isApplyingDecal;
	}

	void BGSDecalManager::SetApplyingDecal(bool a_isApplyingDecal)
	{
		using func_t = decltype(&BGSDecalManager::SetApplyingDecal);
		REL::Relocation<func_t> func{ REL::ID(76070) };
		return func(a_isApplyingDecal);
	}

	bool BGSDecalManager::ShouldApplyDecal(RE::TESObjectREFR* a_objectReference)
	{
		using func_t = decltype(&BGSDecalManager::ShouldApplyDecal);
		REL::Relocation<func_t> func{ REL::ID(15044) };
		return func(a_objectReference);
	}

	void BGSDecalManager::ApplyDecal(RE::DECAL_CREATION_DATA& a_decalCreationData, bool a_forceDecal, RE::BGSDecalGroup* a_decalGroup)
	{
		using func_t = decltype(&BGSDecalManager::ApplyDecal);
		REL::Relocation<func_t> func{ REL::ID(15029) };
		return func(this, a_decalCreationData, a_forceDecal, a_decalGroup);
	}
}
