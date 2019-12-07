#include "RE/Actor.h"

#include "skse64/GameReferences.h"

#include "RE/ActorProcessManager.h"
#include "RE/BGSAttackData.h"
#include "RE/BGSColorForm.h"
#include "RE/ExtraCanTalkToPlayer.h"
#include "RE/ExtraFactionChanges.h"
#include "RE/HighProcess.h"
#include "RE/InventoryChanges.h"
#include "RE/InventoryEntryData.h"
#include "RE/MiddleProcess.h"
#include "RE/NiColor.h"
#include "RE/NiNode.h"
#include "RE/Offsets.h"
#include "RE/TESActorBaseData.h"
#include "RE/TESFaction.h"
#include "RE/TESNPC.h"
#include "RE/TESRace.h"
#include "RE/TESWorldSpace.h"
#include "REL/Relocation.h"


namespace RE
{
	bool Actor::AddSpell(SpellItem* a_spell)
	{
		using func_t = function_type_t<decltype(&Actor::AddSpell)>;
		REL::Offset<func_t*> func(Offset::Actor::AddSpell);
		return func(this, a_spell);
	}


	void Actor::AllowBleedoutDialogue(bool a_canTalk)
	{
		if (a_canTalk) {
			flags2 |= Flag2::kAllowBleedoutDialogue;
		} else {
			flags2 &= ~Flag2::kAllowBleedoutDialogue;
		}
	}


	void Actor::AllowPCDialogue(bool a_talk)
	{
		auto xTalk = extraData.GetByType<ExtraCanTalkToPlayer>();
		if (xTalk) {
			xTalk = new ExtraCanTalkToPlayer();
			extraData.Add(xTalk);
		}

		xTalk->canTalkToPlayer = a_talk;
	}


	SInt32 Actor::CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_multiplyValueByRemainingItems) const
	{
		using func_t = function_type_t<decltype(&Actor::CalcEntryValue)>;
		REL::Offset<func_t*> func(Offset::Actor::CalcEntryValue);
		return func(this, a_entryData, a_numItems, a_multiplyValueByRemainingItems);
	}


	bool Actor::CanFlyHere() const
	{
		auto worldSpace = GetWorldspace();
		return worldSpace && worldSpace->HasMaxHeightData();
	}


	void Actor::DispelWornItemEnchantments()
	{
		using func_t = function_type_t<decltype(&Actor::DispelWornItemEnchantments)>;
		REL::Offset<func_t*> func(Offset::Actor::DispelWornItemEnchantments);
		return func(this);
	}


	TESNPC* Actor::GetActorBase() const
	{
		return baseForm->As<TESNPC*>();
	}


	InventoryEntryData* Actor::GetAttackingWeapon()
	{
		if (!processManager || !processManager->highProcess || !processManager->highProcess->attackData || !processManager->middleProcess) {
			return 0;
		}

		auto attackData = processManager->highProcess->attackData;
		auto middleProcess = processManager->middleProcess;

		return attackData->IsLeftAttack() ? middleProcess->leftHand : middleProcess->rightHand;
	}


	const InventoryEntryData* Actor::GetAttackingWeapon() const
	{
		if (!processManager || !processManager->highProcess || !processManager->highProcess->attackData || !processManager->middleProcess) {
			return 0;
		}

		auto attackData = processManager->highProcess->attackData;
		auto middleProcess = processManager->middleProcess;

		return attackData->IsLeftAttack() ? middleProcess->leftHand : middleProcess->rightHand;
	}


	InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand)
	{
		if (!processManager || !processManager->middleProcess) {
			return 0;
		}

		auto middleProcess = processManager->middleProcess;
		return a_leftHand ? middleProcess->leftHand : middleProcess->rightHand;
	}


	const InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand) const
	{
		if (!processManager || !processManager->middleProcess) {
			return 0;
		}

		auto middleProcess = processManager->middleProcess;
		return a_leftHand ? middleProcess->leftHand : middleProcess->rightHand;
	}


	SInt32 Actor::GetDetectionLevel(Actor* a_target, UInt32 a_idx)
	{
		using func_t = function_type_t<decltype(&Actor::GetDetectionLevel)>;
		REL::Offset<func_t*> func(Offset::Actor::GetDetectionLevel);
		return func(this, a_target, a_idx);
	}


	TESForm* Actor::GetEquippedObject(bool a_leftHand) const
	{
		if (processManager) {
			if (a_leftHand) {
				return processManager->GetEquippedLeftHand();
			} else {
				return processManager->GetEquippedRightHand();
			}
		} else {
			return 0;
		}
	}


	SInt32 Actor::GetGoldAmount()
	{
		SInt32 gold = 0;

		auto invChanges = GetInventoryChanges();
		if (invChanges && invChanges->entryList) {
			for (auto& entry : *invChanges->entryList) {
				if (entry->type && entry->type->IsGold()) {
					gold += entry->countDelta;
				}
			}
		}

		auto cont = GetContainer();
		if (cont) {
			cont->ForEach([&](RE::TESContainer::Entry* a_entry) -> bool
			{
				if (a_entry->form && a_entry->form->IsGold()) {
					gold += a_entry->count;
				}
				return true;
			});
		}

		return gold;
	}


	float Actor::GetHeight()
	{
		using func_t = function_type_t<decltype(&Actor::GetHeight)>;
		REL::Offset<func_t*> func(Offset::Actor::GetHeight);
		return func(this);
	}


	UInt16 Actor::GetLevel() const
	{
		using func_t = function_type_t<decltype(&Actor::GetLevel)>;
		REL::Offset<func_t*> func(Offset::Actor::GetLevel);
		return func(this);
	}


	TESRace* Actor::GetRace() const
	{
		auto base = GetActorBase();
		return base ? base->race : 0;
	}


	bool Actor::HasPerk(BGSPerk* a_perk) const
	{
		using func_t = function_type_t<decltype(&Actor::HasPerk)>;
		REL::Offset<func_t*> func(Offset::Actor::HasPerk);
		return func(this, a_perk);
	}


	bool Actor::IsAIEnabled() const
	{
		return (flags1 & Flag1::kAIEnabled) != Flag1::kNone;
	}


	bool Actor::IsBeingRidden() const
	{
		return ((flags2 & Flag2::kHasInteraction) != Flag2::kNone) && extraData.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsCommandedActor() const
	{
		return (flags2 & Flag2::kIsCommandedActor) != Flag2::kNone;
	}


	bool Actor::IsEssential() const
	{
		return (flags2 & Flag2::kIsEssential) != Flag2::kNone;
	}


	bool Actor::IsGhost() const
	{
		using func_t = function_type_t<decltype(&Actor::IsGhost)>;
		REL::Offset<func_t*> func(Offset::Actor::IsGhost);
		return func(this);
	}


	bool Actor::IsGuard() const
	{
		return (flags1 & Flag1::kIsGuard) != Flag1::kNone;
	}


	bool Actor::IsHostileToActor(Actor* a_actor) const
	{
		using func_t = function_type_t<decltype(&Actor::IsHostileToActor)>;
		REL::Offset<func_t*> func(Offset::Actor::IsHostileToActor);
		return func(this, a_actor);
	}


	bool Actor::IsInKillMove() const
	{
		return (flags2 & Flag2::kIsInKillMove) != Flag2::kNone;
	}


	bool Actor::IsOnMount() const
	{
		return ((flags2 & Flag2::kHasInteraction) != Flag2::kNone) && extraData.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsPlayerTeammate() const
	{
		return (flags1 & Flag1::kIsPlayerTeammate) != Flag1::kNone;
	}


	bool Actor::IsRunning() const
	{
		using func_t = function_type_t<decltype(&Actor::IsRunning)>;
		REL::Offset<func_t*> func(Offset::Actor::IsRunning);
		return func(this);
	}


	bool Actor::IsSneaking() const
	{
		if (!ActorState::IsSneaking()) {
			return false;
		}

		if (ActorState::IsSwimming()) {
			return false;
		}

		if (IsOnMount()) {
			return false;
		}

		return true;
	}


	bool Actor::IsSummoned() const
	{
		auto base = GetActorBase();
		return base ? base->IsSummonable() : false;
	}


	bool Actor::IsTrespassing() const
	{
		return (flags2 & Flag2::kIsTrespassing) != Flag2::kNone;
	}


	void Actor::QueueNiNodeUpdate(bool a_updateWeight)
	{
		using func_t = function_type_t<decltype(&Actor::QueueNiNodeUpdate)>;
		REL::Offset<func_t*> func(Offset::Actor::QueueNiNodeUpdate);
		return func(this, a_updateWeight);
	}


	void Actor::ResetAI(bool a_arg1, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&Actor::ResetAI)>;
		REL::Offset<func_t*> func(Offset::Actor::ResetAI);
		return func(this, a_arg1, a_arg2);
	}


	void Actor::SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, SInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage)
	{
		using func_t = function_type_t<decltype(&Actor::SendStealAlarm)>;
		REL::Offset<func_t*> func(Offset::Actor::SendStealAlarm);
		return func(this, a_refItemOrContainer, a_stolenItem, a_numItems, a_value, a_owner, a_allowGetBackStolenItemPackage);
	}


	void Actor::SetRace(TESRace* a_race, bool a_isPlayer)
	{
		using func_t = function_type_t<decltype(&Actor::SetRace)>;
		REL::Offset<func_t*> func(Offset::Actor::SetRace);
		return func(this, a_race, a_isPlayer);
	}


	void Actor::UpdateArmorAbility(TESForm* a_armor, BaseExtraList* a_extraData)
	{
		using func_t = function_type_t<decltype(&Actor::UpdateArmorAbility)>;
		REL::Offset<func_t*> func(Offset::Actor::UpdateArmorAbility);
		return func(this, a_armor, a_extraData);
	}


	void Actor::UpdateHairColor()
	{
		auto npc = GetActorBase();
		if (npc && npc->headData) {
			auto hairColor = npc->headData->hairColor;
			if (hairColor) {
				NiColorA val;
				val.red = hairColor->color.red / 128.0;
				val.green = hairColor->color.green / 128.0;
				val.blue = hairColor->color.blue / 128.0;
				auto color = &val;

				auto model = GetNiRootNode(0);
				if (model) {
					model->UpdateModelHair(&color);
				}
			}
		}
	}


	void Actor::UpdateSkinColor()
	{
		auto npc = GetActorBase();
		if (npc) {
			NiColorA val;
			val.red = npc->textureLighting.red / 255.0;
			val.green = npc->textureLighting.green / 255.0;
			val.blue = npc->textureLighting.blue / 255.0;
			auto color = &val;

			auto thirdPerson = GetNiRootNode(0);
			if (thirdPerson) {
				thirdPerson->UpdateModelSkin(&color);
			}

			auto firstPerson = GetNiRootNode(1);
			if (firstPerson) {
				firstPerson->UpdateModelSkin(&color);
			}
		}
	}


	void Actor::UpdateWeaponAbility(TESForm* a_weapon, BaseExtraList* a_extraData, bool a_leftHand)
	{
		using func_t = function_type_t<decltype(&Actor::UpdateWeaponAbility)>;
		REL::Offset<func_t*> func(Offset::Actor::UpdateWeaponAbility);
		return func(this, a_weapon, a_extraData, a_leftHand);
	}


	bool Actor::VisitFactions(llvm::function_ref<bool(RE::TESFaction* a_faction, SInt8 a_rank)> a_visitor)
	{
		auto base = GetActorBase();
		if (base) {
			for (auto& factionInfo : base->factions) {
				if (a_visitor(factionInfo.faction, factionInfo.rank)) {
					return true;
				}
			}

			auto factionChanges = extraData.GetByType<ExtraFactionChanges>();
			if (factionChanges) {
				for (auto& info : factionChanges->factions) {
					if (a_visitor(info.faction, info.rank)) {
						return true;
					}
				}
			}
		}

		return false;
	}
}
