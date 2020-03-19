#include "RE/Actor.h"

#include <type_traits>

#include "RE/AIProcess.h"
#include "RE/BGSAttackData.h"
#include "RE/BGSColorForm.h"
#include "RE/BGSDefaultObjectManager.h"
#include "RE/BSFaceGenAnimationData.h"
#include "RE/ExtraCanTalkToPlayer.h"
#include "RE/ExtraFactionChanges.h"
#include "RE/FormTraits.h"
#include "RE/HighProcessData.h"
#include "RE/InventoryEntryData.h"
#include "RE/MiddleHighProcessData.h"
#include "RE/Misc.h"
#include "RE/NiColor.h"
#include "RE/NiNode.h"
#include "RE/NiPoint3.h"
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
		using func_t = decltype(&Actor::AddSpell);
		REL::Offset<func_t> func(Offset::Actor::AddSpell);
		return func(this, a_spell);
	}


	void Actor::AllowBleedoutDialogue(bool a_canTalk)
	{
		if (a_canTalk) {
			boolFlags |= BOOL_FLAGS::kCanSpeakToEssentialDown;
		} else {
			boolFlags &= ~BOOL_FLAGS::kCanSpeakToEssentialDown;
		}
	}


	void Actor::AllowPCDialogue(bool a_talk)
	{
		auto xTalk = extraList.GetByType<ExtraCanTalkToPlayer>();
		if (xTalk) {
			xTalk = new ExtraCanTalkToPlayer();
			extraList.Add(xTalk);
		}

		xTalk->talk = a_talk;
	}


	bool Actor::CanFlyHere() const
	{
		const auto* worldSpace = GetWorldspace();
		return worldSpace && worldSpace->HasMaxHeightData();
	}


	bool Actor::CanPickpocket() const
	{
		if (!race) {
			return false;
		}

		return race->AllowsPickpocket() && !IsPlayerTeammate();
	}


	bool Actor::CanTalkToPlayer() const
	{
		auto xTalk = extraList.GetByType<ExtraCanTalkToPlayer>();
		if (xTalk) {
			return xTalk->talk;
		} else {
			return race ? race->AllowsPCDialogue() : false;
		}
	}


	void Actor::ClearArrested()
	{
		if (currentProcess && currentProcess->IsArrested()) {
			currentProcess->SetArrested(false);
			EvaluatePackage(false, false);
			auto procManager = ProcessLists::GetSingleton();
			if (procManager) {
				procManager->StopCombatAndAlarmOnActor(this, true);
			}
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
		extraList.RemoveByType(ExtraDataType::kAttachedArrows3D);
	}


	ActorHandle Actor::CreateRefHandle()
	{
		return ActorHandle(this);
	}


	void Actor::DispelWornItemEnchantments()
	{
		using func_t = decltype(&Actor::DispelWornItemEnchantments);
		REL::Offset<func_t> func(Offset::Actor::DispelWornItemEnchantments);
		return func(this);
	}


	void Actor::DoReset3D(bool a_updateWeight)
	{
		using func_t = decltype(&Actor::DoReset3D);
		REL::Offset<func_t> func(Offset::Actor::DoReset3D);
		return func(this, a_updateWeight);
	}


	void Actor::EvaluatePackage(bool a_arg1, bool a_arg2)
	{
		using func_t = decltype(&Actor::EvaluatePackage);
		REL::Offset<func_t> func(Offset::Actor::EvaluatePackage);
		return func(this, a_arg1, a_arg2);
	}


	TESNPC* Actor::GetActorBase()
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESNPC>() : nullptr;
	}


	const TESNPC* Actor::GetActorBase() const
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESNPC>() : nullptr;
	}


	InventoryEntryData* Actor::GetAttackingWeapon()
	{
		if (!currentProcess || !currentProcess->high || !currentProcess->high->attackData || !currentProcess->middleHigh) {
			return nullptr;
		}

		auto attackData = currentProcess->high->attackData;
		auto proc = currentProcess->middleHigh;

		return attackData->IsLeftAttack() ? proc->leftHand : proc->rightHand;
	}


	const InventoryEntryData* Actor::GetAttackingWeapon() const
	{
		if (!currentProcess || !currentProcess->high || !currentProcess->high->attackData || !currentProcess->middleHigh) {
			return nullptr;
		}

		auto attackData = currentProcess->high->attackData;
		auto proc = currentProcess->middleHigh;

		return attackData->IsLeftAttack() ? proc->leftHand : proc->rightHand;
	}


	bhkCharacterController* Actor::GetCharController() const
	{
		return currentProcess ? currentProcess->GetCharController() : nullptr;
	}


	TESFaction* Actor::GetCrimeFaction()
	{
		return GetCrimeFactionImpl();
	}


	const TESFaction* Actor::GetCrimeFaction() const
	{
		return GetCrimeFactionImpl();
	}


	InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand) const
	{
		if (!currentProcess || !currentProcess->middleHigh) {
			return nullptr;
		}

		auto proc = currentProcess->middleHigh;
		if (proc->bothHands) {
			return proc->bothHands;
		} else {
			return a_leftHand ? proc->leftHand : proc->rightHand;
		}
	}


	TESForm* Actor::GetEquippedObject(bool a_leftHand) const
	{
		if (currentProcess) {
			if (a_leftHand) {
				return currentProcess->GetEquippedLeftHand();
			} else {
				return currentProcess->GetEquippedRightHand();
			}
		} else {
			return nullptr;
		}
	}


	SInt32 Actor::GetGoldAmount()
	{
		auto inv = GetInventory([](TESBoundObject* a_object) -> bool {
			return a_object->IsGold();
		});

		auto dobj = BGSDefaultObjectManager::GetSingleton();
		if (!dobj) {
			return 0;
		}

		auto gold = dobj->GetObject<TESObjectMISC>(DEFAULT_OBJECT::kGold);
		auto it = inv.find(gold);
		return it != inv.end() ? it->second.first : 0;
	}


	float Actor::GetHeight()
	{
		const auto min = GetBoundMin();
		const auto max = GetBoundMax();
		const auto diff = max.z - min.z;
		const auto height = GetBaseHeight() * diff;

		if (!currentProcess || !currentProcess->InHighProcess()) {
			return height;
		}

		const auto cachedHeight = currentProcess->GetCachedHeight();
		if (cachedHeight == 0.0) {
			currentProcess->SetCachedHeight(height);
			return height;
		} else {
			return cachedHeight;
		}
	}


	UInt16 Actor::GetLevel() const
	{
		using func_t = decltype(&Actor::GetLevel);
		REL::Offset<func_t> func(Offset::Actor::GetLevel);
		return func(this);
	}


	TESRace* Actor::GetRace() const
	{
		auto base = GetActorBase();
		return base ? base->race : nullptr;
	}


	bool Actor::HasPerk(BGSPerk* a_perk) const
	{
		using func_t = decltype(&Actor::HasPerk);
		REL::Offset<func_t> func(Offset::Actor::HasPerk);
		return func(this, a_perk);
	}


	bool Actor::IsAIEnabled() const
	{
		return (boolBits & BOOL_BITS::kProcessMe) != BOOL_BITS::kNone;
	}


	bool Actor::IsAMount() const
	{
		return (boolFlags & BOOL_FLAGS::kIsAMount) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsBeingRidden() const
	{
		return IsAMount() && extraList.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsCommandedActor() const
	{
		return (boolFlags & BOOL_FLAGS::kIsCommandedActor) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsEssential() const
	{
		return (boolFlags & BOOL_FLAGS::kEssential) != BOOL_FLAGS::kNone;
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
		using func_t = decltype(&Actor::IsGhost);
		REL::Offset<func_t> func(Offset::Actor::GetGhost);
		return func(this);
	}


	bool Actor::IsGuard() const
	{
		return (boolBits & BOOL_BITS::kGuard) != BOOL_BITS::kNone;
	}


	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		using func_t = decltype(&Actor::IsHostileToActor);
		REL::Offset<func_t> func(Offset::Actor::GetHostileToActor);
		return func(this, a_actor);
	}


	bool Actor::IsInKillMove() const
	{
		return (boolFlags & BOOL_FLAGS::kIsInKillMove) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsOnMount() const
	{
		return !IsAMount() && extraList.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsPlayerTeammate() const
	{
		return (boolBits & BOOL_BITS::kPlayerTeammate) != BOOL_BITS::kNone;
	}


	bool Actor::IsRunning() const
	{
		using func_t = decltype(&Actor::IsRunning);
		REL::Offset<func_t> func(Offset::Actor::IsRunning);
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
		return (boolFlags & BOOL_FLAGS::kIsTrespassing) != BOOL_FLAGS::kNone;
	}


	SInt32 Actor::RequestDetectionLevel(Actor* a_target, DETECTION_PRIORITY a_priority)
	{
		using func_t = decltype(&Actor::RequestDetectionLevel);
		REL::Offset<func_t> func(Offset::Actor::RequestDetectionLevel);
		return func(this, a_target, a_priority);
	}


	void Actor::StealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, SInt32 a_numItems, SInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage)
	{
		using func_t = decltype(&Actor::StealAlarm);
		REL::Offset<func_t> func(Offset::Actor::StealAlarm);
		return func(this, a_refItemOrContainer, a_stolenItem, a_numItems, a_value, a_owner, a_allowGetBackStolenItemPackage);
	}


	void Actor::SwitchRace(TESRace* a_race, bool a_player)
	{
		using func_t = decltype(&Actor::SwitchRace);
		REL::Offset<func_t> func(Offset::Actor::SwitchRace);
		return func(this, a_race, a_player);
	}


	void Actor::UpdateArmorAbility(TESForm* a_armor, ExtraDataList* a_extraData)
	{
		using func_t = decltype(&Actor::UpdateArmorAbility);
		REL::Offset<func_t> func(Offset::Actor::UpdateArmorAbility);
		return func(this, a_armor, a_extraData);
	}


	void Actor::Update3DModel()
	{
		if (currentProcess) {
			currentProcess->Update3DModel(this);
		}
	}


	void Actor::UpdateHairColor()
	{
		auto npc = GetActorBase();
		if (npc && npc->headRelatedData) {
			const auto hairColor = npc->headRelatedData->hairColor;
			if (hairColor) {
				NiColor color;
				color.red = hairColor->color.red / static_cast<float>(128.0);
				color.green = hairColor->color.green / static_cast<float>(128.0);
				color.blue = hairColor->color.blue / static_cast<float>(128.0);

				auto model = Get3D(false);
				if (model) {
					model->UpdateHairColor(color);
				}
			}
		}
	}


	void Actor::UpdateSkinColor()
	{
		const auto* npc = GetActorBase();
		if (npc) {
			NiColor color;
			color.red = npc->bodyTintColor.red / static_cast<float>(255.0);
			color.green = npc->bodyTintColor.green / static_cast<float>(255.0);
			color.blue = npc->bodyTintColor.blue / static_cast<float>(255.0);

			auto thirdPerson = Get3D(false);
			if (thirdPerson) {
				thirdPerson->UpdateBodyTint(color);
			}

			auto firstPerson = Get3D(true);
			if (firstPerson) {
				firstPerson->UpdateBodyTint(color);
			}
		}
	}


	void Actor::UpdateWeaponAbility(TESForm* a_weapon, ExtraDataList* a_extraData, bool a_leftHand)
	{
		using func_t = decltype(&Actor::UpdateWeaponAbility);
		REL::Offset<func_t> func(Offset::Actor::UpdateWeaponAbility);
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

			auto factionChanges = extraList.GetByType<ExtraFactionChanges>();
			if (factionChanges) {
				for (auto& change : factionChanges->factionChanges) {
					if (a_visitor(change.faction, change.rank)) {
						return true;
					}
				}
			}
		}

		return false;
	}


	TESFaction* Actor::GetCrimeFactionImpl() const
	{
		if (IsCommandedActor()) {
			return nullptr;
		}

		auto xFac = extraList.GetByType<ExtraFactionChanges>();
		if (xFac && (xFac->crimeFaction || xFac->removeCrimeFaction)) {
			return xFac->crimeFaction;
		}

		auto base = GetActorBase();
		return base ? base->crimeFaction : nullptr;
	}
}
