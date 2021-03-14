#include "RE/B/BGSDecalManager.h"

namespace RE
{
	BGSDecalManager* BGSDecalManager::GetSingleton()
	{
		REL::Relocation<BGSDecalManager**> singleton{ Offset::BGSDecalManager::Singleton };
		return *singleton;
	}

	bool BGSDecalManager::IsApplyingDecal()
	{
		REL::Relocation<bool*> isApplyingDecal{ Offset::BGSDecalManager::IsApplyingDecal };
		return *isApplyingDecal;
	}

	void BGSDecalManager::SetApplyingDecal(bool a_isApplyingDecal)
	{
		using func_t = decltype(&BGSDecalManager::SetApplyingDecal);
		REL::Relocation<func_t> func{ Offset::BGSDecalManager::SetApplyingDecal };
		return func(a_isApplyingDecal);
	}

	bool BGSDecalManager::ShouldApplyDecal(RE::TESObjectREFR* a_objectReference)
	{
		using func_t = decltype(&BGSDecalManager::ShouldApplyDecal);
		REL::Relocation<func_t> func{ Offset::BGSDecalManager::ShouldApplyDecal };
		return func(a_objectReference);
	}

	void BGSDecalManager::ApplyDecal(RE::DECAL_CREATION_DATA& a_decalCreationData, bool a_forceDecal, RE::BGSDecalGroup* a_decalGroup)
	{
		using func_t = decltype(&BGSDecalManager::ApplyDecal);
		REL::Relocation<func_t> func{ Offset::BGSDecalManager::ApplyDecal };
		return func(this, a_decalCreationData, a_forceDecal, a_decalGroup);
	}
}
