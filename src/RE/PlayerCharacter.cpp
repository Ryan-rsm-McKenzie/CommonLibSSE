#include "RE/PlayerCharacter.h"

#include "skse64/GameReferences.h"  // PlayerCharacter

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"  // TESObjectREFR
#include "REL/Relocation.h"


namespace RE
{
	void PlayerCharacter::PlayerSkills::AdvanceLevel(bool a_addThreshold)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::PlayerSkills::AdvanceLevel)>;
		REL::Offset<func_t*> func(Offset::PlayerCharacter::PlayerSkills::AdvanceLevel);
		return func(this, a_addThreshold);
	}


	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		return reinterpret_cast<PlayerCharacter*>(*g_thePlayer);
	}


	UInt32 PlayerCharacter::GetPickpocketChance(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_itemWeight, Actor* a_player, Actor* a_target, bool a_isDetected, TESForm* a_item)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::GetPickpocketChance)>;
		REL::Offset<func_t*> func(Offset::PlayerCharacter::GetPickpocketChance);
		return func(a_playerSkill, a_targetSkill, a_totalValue, a_itemWeight, a_player, a_target, a_isDetected, a_item);
	}


	Actor* PlayerCharacter::GetActorInFavorState() const
	{
		RE::TESObjectREFRPtr ref;
		RE::TESObjectREFR::LookupByHandle(actorInFavorState, ref);
		return static_cast<Actor*>(ref.get());
	}


	float PlayerCharacter::GetArmorValue(InventoryEntryData* a_form)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::GetArmorValue)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerCharacter, GetArmorValue, func_t*);
		return func(this, a_form);
	}


	float PlayerCharacter::GetDamage(InventoryEntryData* a_form)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::GetDamage)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerCharacter, GetDamage, func_t*);
		return func(this, a_form);
	}


	NiPointer<TESObjectREFR> PlayerCharacter::GetGrabbedRef()
	{
		TESObjectREFRPtr refPtr;
		UInt32 handle = grabbedHandle;
		TESObjectREFR::LookupByHandle(handle, refPtr);
		return refPtr;
	}


	UInt32 PlayerCharacter::GetNumTints(UInt32 a_tintType)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::GetNumTints)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerCharacter, GetNumTints, func_t*);
		return func(this, a_tintType);
	}


	TintMask* PlayerCharacter::GetOverlayTintMask(TintMask* a_original)
	{
		if (!overlayTintMasks) {
			return 0;
		}

		for (UInt32 i = 0; i < tintMasks.size(); ++i) {
			if (tintMasks[i] == a_original) {
				return i < overlayTintMasks->size() ? (*overlayTintMasks)[i] : 0;
			}
		}
		return 0;
	}


	BSTArray<TintMask*>& PlayerCharacter::GetTintList()
	{
		return overlayTintMasks ? *overlayTintMasks : tintMasks;
	}


	TintMask* PlayerCharacter::GetTintMask(UInt32 a_tintType, UInt32 a_index)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::GetTintMask)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::PlayerCharacter, GetTintMask, func_t*);
		return func(this, a_tintType, a_index);
	}

	
	void PlayerCharacter::PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::PlayPickupEvent)>;
		REL::Offset<func_t*> func(Offset::PlayerCharacter::PlayPickupEvent);
		return func(this, a_item, a_containerOwner, a_containerRef, a_eventType);
	}

	
	void PlayerCharacter::SetCollision(bool a_enable)
	{
		REL::Offset<bool*> g_collisionDisabled(Offset::PlayerCharacter::CollisionDisabled);
		if (a_enable) {
			*g_collisionDisabled = false;
		} else {
			*g_collisionDisabled = true;
		}
		Character::SetCollision(a_enable);
	}

	
	void PlayerCharacter::StartActivation()
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::StartActivation)>;
		REL::Offset<func_t*> func(Offset::PlayerCharacter::StartActivation);
		return func(this);
	}


	bool PlayerCharacter::TryToPickPocket(Actor* a_target, InventoryEntryData* a_entry, UInt32 a_numItems, bool a_arg4)
	{
		using func_t = function_type_t<decltype(&PlayerCharacter::TryToPickPocket)>;
		REL::Offset<func_t*> func(Offset::PlayerCharacter::TryToPickPocket);
		return func(this, a_target, a_entry, a_numItems, a_arg4);
	}
}
