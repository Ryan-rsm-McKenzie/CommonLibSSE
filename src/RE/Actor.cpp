#include "RE/Actor.h"

#include "skse64/GameReferences.h"

#include <type_traits>

#include "RE/AIProcess.h"
#include "RE/BGSAttackData.h"
#include "RE/BGSColorForm.h"
#include "RE/BSFaceGenAnimationData.h"
#include "RE/ExtraCanTalkToPlayer.h"
#include "RE/ExtraFactionChanges.h"
#include "RE/HighProcess.h"
#include "RE/InventoryEntryData.h"
#include "RE/MiddleProcess.h"
#include "RE/Misc.h"
#include "RE/NiColor.h"
#include "RE/NiNode.h"
#include "RE/Offsets.h"
#include "RE/ProcessLists.h"
#include "RE/TESFaction.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectMISC.h"
#include "RE/TESRace.h"
#include "RE/TESWorldSpace.h"
#include "REL/Relocation.h"


namespace RE
{
	NiPointer<Actor> Actor::LookupByHandle(RefHandle a_refHandle)
	{
		NiPointer<Actor> ref;
		LookupReferenceByHandle(a_refHandle, ref);
		return ref;
	}


	bool Actor::LookupByHandle(RefHandle a_refHandle, NiPointer<Actor>& a_refrOut)
	{
		return LookupReferenceByHandle(a_refHandle, a_refrOut);
	}


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


	void Actor::ClearArrested()
	{
		if (aiProcess && aiProcess->IsArrested()) {
			aiProcess->SetArrested(false);
			ResetAI(0, 0);
			auto procManager = ProcessLists::GetSingleton();
			procManager->SetCombatAlarmState(this, true);
		}
	}


	void Actor::ClearExpressionOverride()
	{
		auto faceGen = GetFaceGenAnimationData();
		if (faceGen) {
			faceGen->ClearExpressionOverride();
		}
	}


	void Actor::ClearExtraArrows()
	{
		extraData.RemoveByType(ExtraDataType::kAttachedArrows3D);
	}


	void Actor::DispelWornItemEnchantments()
	{
		using func_t = function_type_t<decltype(&Actor::DispelWornItemEnchantments)>;
		REL::Offset<func_t*> func(Offset::Actor::DispelWornItemEnchantments);
		return func(this);
	}


	TESNPC* Actor::GetActorBase()
	{
		return baseForm->As<TESNPC*>();
	}


	const TESNPC* Actor::GetActorBase() const
	{
		return baseForm->As<TESNPC*>();
	}


	InventoryEntryData* Actor::GetAttackingWeapon()
	{
		if (!aiProcess || !aiProcess->highProcess || !aiProcess->highProcess->attackData || !aiProcess->middleProcess) {
			return 0;
		}

		auto attackData = aiProcess->highProcess->attackData;
		auto middleProcess = aiProcess->middleProcess;

		return attackData->IsLeftAttack() ? middleProcess->leftHand : middleProcess->rightHand;
	}


	const InventoryEntryData* Actor::GetAttackingWeapon() const
	{
		if (!aiProcess || !aiProcess->highProcess || !aiProcess->highProcess->attackData || !aiProcess->middleProcess) {
			return 0;
		}

		auto attackData = aiProcess->highProcess->attackData;
		auto middleProcess = aiProcess->middleProcess;

		return attackData->IsLeftAttack() ? middleProcess->leftHand : middleProcess->rightHand;
	}


	TESFaction* Actor::GetCrimeFaction()
	{
		auto thisPtr = const_cast<const Actor*>(this);
		auto fac = thisPtr->GetCrimeFaction();
		return const_cast<TESFaction*>(fac);
	}


	const TESFaction* Actor::GetCrimeFaction() const
	{
		if (IsCommandedActor()) {
			return 0;
		}

		auto xFac = extraData.GetByType<ExtraFactionChanges>();
		if (xFac && (xFac->crimeFaction || xFac->noTrackCrime)) {
			return xFac->crimeFaction;
		}

		auto base = GetActorBase();
		return base ? base->crimeFaction : 0;
	}


	InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand)
	{
		if (!aiProcess || !aiProcess->middleProcess) {
			return 0;
		}

		auto middleProcess = aiProcess->middleProcess;
		return a_leftHand ? middleProcess->leftHand : middleProcess->rightHand;
	}


	const InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand) const
	{
		if (!aiProcess || !aiProcess->middleProcess) {
			return 0;
		}

		auto middleProcess = aiProcess->middleProcess;
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
		if (aiProcess) {
			if (a_leftHand) {
				return aiProcess->GetEquippedLeftHand();
			} else {
				return aiProcess->GetEquippedRightHand();
			}
		} else {
			return 0;
		}
	}


	SInt32 Actor::GetGoldAmount()
	{
		auto inv = GetInventory([](TESBoundObject* a_object) -> bool
		{
			return a_object->IsGold();
		});

		auto gold = TESObjectMISC::GetGoldForm();
		auto it = inv.find(gold);
		return it != inv.end() ? it->second.first : 0;
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


	bool Actor::IsFactionInCrimeGroup(const TESFaction* a_faction) const
	{
		auto crimFac = GetCrimeFaction();
		if (!crimFac) {
			return false;
		}

		if (crimFac == a_faction) {
			return true;
		} else {
			return crimFac->IsFactionInCrimeGroup(a_faction);
		}
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


	void Actor::ResetAI(UInt32 a_arg1, UInt32 a_arg2)
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


	void Actor::UpdateArmorAbility(TESForm* a_armor, ExtraDataList* a_extraData)
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

				auto model = Get3D(0);
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

			auto thirdPerson = Get3D(0);
			if (thirdPerson) {
				thirdPerson->UpdateModelSkin(&color);
			}

			auto firstPerson = Get3D(1);
			if (firstPerson) {
				firstPerson->UpdateModelSkin(&color);
			}
		}
	}


	void Actor::UpdateWeaponAbility(TESForm* a_weapon, ExtraDataList* a_extraData, bool a_leftHand)
	{
		using func_t = function_type_t<decltype(&Actor::UpdateWeaponAbility)>;
		REL::Offset<func_t*> func(Offset::Actor::UpdateWeaponAbility);
		return func(this, a_weapon, a_extraData, a_leftHand);
	}


	bool Actor::VisitFactions(llvm::function_ref<bool(TESFaction* a_faction, SInt8 a_rank)> a_visitor)
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
