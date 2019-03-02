#include "RE/Actor.h"

#include "skse64/GameReferences.h"  // Actor
#include "skse64/GameRTTI.h"  // DYNAMIC_CAST

#include <cstdint>  // uintptr_t

#include "RE/ExtraFactionChanges.h"  // ExtraFactionChanges
#include "RE/Offsets.h"
#include "RE/TESActorBaseData.h"  // TESActorBaseData
#include "RE/TESFaction.h"  // TESFaction
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESRace.h"  // TESRace


namespace RE
{
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


	void Actor::UpdateSkinColor()
	{
		typedef void _UpdateSkinColor_t(Actor* a_this);
		_UpdateSkinColor_t* _UpdateSkinColor = reinterpret_cast<_UpdateSkinColor_t*>(GetFnAddr(&::Actor::UpdateSkinColor));
		_UpdateSkinColor(this);
	}


	void Actor::UpdateHairColor()
	{
		typedef void _UpdateHairColor_t(Actor* a_this);
		_UpdateHairColor_t* _UpdateHairColor = reinterpret_cast<_UpdateHairColor_t*>(GetFnAddr(&::Actor::UpdateHairColor));
		_UpdateHairColor(this);
	}


	void Actor::QueueNiNodeUpdate(bool a_updateWeight)
	{
		typedef void _QueueNiNodeUpdate_t(Actor* a_this, bool a_updateWeight);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::Actor*>(this)->_QueueNiNodeUpdate_GetPtr());
		_QueueNiNodeUpdate_t* _QueueNiNodeUpdate = reinterpret_cast<_QueueNiNodeUpdate_t*>(*ptr);
		_QueueNiNodeUpdate(this, a_updateWeight);
	}


	bool Actor::HasPerk(BGSPerk* a_perk) const
	{
		typedef bool _HasPerk_t(const Actor* a_this, BGSPerk* a_perk);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(const_cast<::Actor*>(reinterpret_cast<const ::Actor*>(this))->_HasPerk_GetPtr());
		_HasPerk_t* _HasPerk = reinterpret_cast<_HasPerk_t*>(*ptr);
		return _HasPerk(this, a_perk);
	}


	UInt16 Actor::GetLevel() const
	{
		typedef UInt16 _GetLevel_t(const Actor* a_this);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(const_cast<::Actor*>(reinterpret_cast<const ::Actor*>(this))->_GetLevel_GetPtr());
		_GetLevel_t* _GetLevel = reinterpret_cast<_GetLevel_t*>(*ptr);
		return _GetLevel(this);
	}


	void Actor::SetRace(TESRace* a_race, bool a_isPlayer)
	{
		typedef void _SetRace_t(Actor* a_this, TESRace* a_race, bool a_isPlayer);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::Actor*>(this)->_SetRace_GetPtr());
		_SetRace_t* _SetRace = reinterpret_cast<_SetRace_t*>(*ptr);
		_SetRace(this, a_race, a_isPlayer);
	}


	void Actor::UpdateWeaponAbility(TESForm* a_weapon, BaseExtraList* a_extraData, bool a_bLeftHand)
	{
		typedef void _UpdateWeaponAbility_t(Actor* a_this, TESForm* a_weapon, BaseExtraList* a_extraData, bool a_bLeftHand);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::Actor*>(this)->_UpdateWeaponAbility_GetPtr());
		_UpdateWeaponAbility_t* _UpdateWeaponAbility = reinterpret_cast<_UpdateWeaponAbility_t*>(*ptr);
		_UpdateWeaponAbility(this, a_weapon, a_extraData, a_bLeftHand);
	}


	void Actor::UpdateArmorAbility(TESForm* a_armor, BaseExtraList* a_extraData)
	{
		typedef void _UpdateArmorAbility_t(Actor* a_this, TESForm* a_armor, BaseExtraList* a_extraData);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::Actor*>(this)->_UpdateArmorAbility_GetPtr());
		_UpdateArmorAbility_t* _UpdateArmorAbility = reinterpret_cast<_UpdateArmorAbility_t*>(*ptr);
		_UpdateArmorAbility(this, a_armor, a_extraData);
	}


	bool Actor::IsHostileToActor(Actor* a_actor) const
	{
		typedef bool _IsHostileToActor_t(const Actor* a_this, Actor* a_actor);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(const_cast<::Actor*>(reinterpret_cast<const ::Actor*>(this))->_IsHostileToActor_GetPtr());
		_IsHostileToActor_t* _IsHostileToActor = reinterpret_cast<_IsHostileToActor_t*>(*ptr);
		return _IsHostileToActor(this, a_actor);
	}


	void Actor::ResetAI(UInt32 a_unk1, UInt32 a_unk2)
	{
		typedef void _ResetAI_t(Actor* a_this, UInt32 a_unk1, UInt32 a_unk2);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::Actor*>(this)->_ResetAI_GetPtr());
		_ResetAI_t* _ResetAI = reinterpret_cast<_ResetAI_t*>(*ptr);
		_ResetAI(this, a_unk1, a_unk2);
	}


	bool Actor::VisitFactions(FactionVisitor& visitor)
	{
		TESNPC* npc = GetActorBase();
		if (npc) {
			for (auto& factionInfo : npc->factions) {
				if (visitor.Accept(factionInfo.faction, factionInfo.rank)) {
					return true;
				}
			}

			ExtraFactionChanges* pFactionChanges = static_cast<ExtraFactionChanges*>(extraData.GetByType(ExtraDataType::kFactionChanges));
			if (pFactionChanges) {
				for (auto& info : pFactionChanges->factions) {
					if (visitor.Accept(info.faction, info.rank)) {
						return true;
					}
				}
			}
		}

		return false;
	}


	TESNPC* Actor::GetActorBase() const
	{
		return static_cast<TESNPC*>(baseForm);
	}


	TESRace* Actor::GetRace() const
	{
		return GetActorBase() ? GetActorBase()->race : 0;
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


	bool Actor::IsGuard() const
	{
		return (flags1 & Flag1::kIsGuard) != Flag1::kNone;
	}


	bool Actor::IsInKillMove() const
	{
		return (flags2 & Flag2::kIsInKillMove) != Flag2::kNone;
	}


	bool Actor::IsAIEnabled() const
	{
		return (flags1 & Flag1::kAIEnabled) != Flag1::kNone;
	}


	bool Actor::IsOnMount() const
	{
		return ((flags2 & Flag2::kHasInteraction) != Flag2::kNone) && extraData.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsPlayerTeammate() const
	{
		return (flags1 & Flag1::kIsPlayerTeammate) != Flag1::kNone;
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


	bool Actor::IsTrespassing() const
	{
		return (flags2 & Flag2::kIsTrespassing) != Flag2::kNone;
	}


	void Actor::DispelWornItemEnchantments()
	{
		typedef void _DispelWornItemEnchantments_t(Actor* a_this);
		RelocAddr<_DispelWornItemEnchantments_t*> _DispelWornItemEnchantments(ACTOR_DISPEL_WORN_ITEM_ENCHANTMENTS);
		_DispelWornItemEnchantments(this);
	}


	Actor::CaughtState Actor::SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage)
	{
		typedef Actor::CaughtState _SendStealAlarm_t(Actor* a_this, TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage);
		RelocAddr<_SendStealAlarm_t*> _SendStealAlarm(ACTOR_SEND_STEAL_ALARM);
		return _SendStealAlarm(this, a_refItemOrContainer, a_stolenItem, a_numItems, a_value, a_owner, a_allowGetBackStolenItemPackage);
	}


	SInt32 Actor::CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_multiplyValueByRemainingItems) const
	{
		typedef SInt32 _CalcEntryValue_t(const Actor* a_this, InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_multiplyValueByRemainingItems);
		RelocAddr<_CalcEntryValue_t*> _CalcEntryValue(ACTOR_CALC_ENTRY_VALUE);
		return _CalcEntryValue(this, a_entryData, a_numItems, a_multiplyValueByRemainingItems);
	}


	SInt32 Actor::GetDetectionLevel(Actor* a_target, UInt32 a_flag) const
	{
		typedef SInt32 _GetDetectionLevel_t(const Actor* a_this, Actor* a_target, UInt32 a_flag);
		RelocAddr<_GetDetectionLevel_t*> _GetDetectionLevel(ACTOR_GET_DETECTION_LEVEL);
		return _GetDetectionLevel(this, a_target, a_flag);
	}


	bool Actor::IsGhost() const
	{
		typedef bool _IsGhost_t(const Actor* a_this);
		RelocAddr<_IsGhost_t*> _IsGhost(ACTOR_IS_GHOST);
		return _IsGhost(this);
	}


	bool Actor::IsSummoned() const
	{
		return GetActorBase() ? GetActorBase()->IsSummonable() : false;
	}


	bool Actor::IsRunning() const
	{
		typedef bool _IsRunning_t(const Actor* a_this);
		RelocAddr<_IsRunning_t*> _IsRunning(ACTOR_IS_RUNNING);
		return _IsRunning(this);
	}
}
