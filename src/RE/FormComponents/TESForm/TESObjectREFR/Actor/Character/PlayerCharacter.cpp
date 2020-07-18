#include "RE/FormComponents/TESForm/TESObjectREFR/Actor/Character/PlayerCharacter.h"

#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"


namespace RE
{
	void PlayerCharacter::PlayerSkills::AdvanceLevel(bool a_addThreshold)
	{
		using func_t = decltype(&PlayerCharacter::PlayerSkills::AdvanceLevel);
		REL::Offset<func_t> func(Offset::PlayerCharacter::PlayerSkills::AdvanceLevel);
		return func(this, a_addThreshold);
	}


	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		REL::Offset<NiPointer<PlayerCharacter>*> singleton(Offset::PlayerCharacter::Singleton);
		return singleton->get();
	}


	void PlayerCharacter::ActivatePickRef()
	{
		using func_t = decltype(&PlayerCharacter::ActivatePickRef);
		REL::Offset<func_t> func(Offset::PlayerCharacter::ActivatePickRef);
		return func(this);
	}


	bool PlayerCharacter::AttemptPickpocket(TESObjectREFR* a_containerRef, InventoryEntryData* a_entry, std::int32_t a_number, bool a_fromContainer)
	{
		using func_t = decltype(&PlayerCharacter::AttemptPickpocket);
		REL::Offset<func_t> func = REL::ID(39568);
		return func(this, a_containerRef, a_entry, a_number, a_fromContainer);
	}


	NiPointer<Actor> PlayerCharacter::GetActorDoingPlayerCommand() const
	{
		return actorDoingPlayerCommand.get();
	}


	float PlayerCharacter::GetArmorValue(InventoryEntryData* a_form)
	{
		using func_t = decltype(&PlayerCharacter::GetArmorValue);
		REL::Offset<func_t> func(Offset::PlayerCharacter::GetArmorValue);
		return func(this, a_form);
	}


	float PlayerCharacter::GetDamage(InventoryEntryData* a_form)
	{
		using func_t = decltype(&PlayerCharacter::GetDamage);
		REL::Offset<func_t> func(Offset::PlayerCharacter::GetDamage);
		return func(this, a_form);
	}


	NiPointer<TESObjectREFR> PlayerCharacter::GetGrabbedRef()
	{
		return grabbedObject.get();
	}


	std::uint32_t PlayerCharacter::GetNumTints(std::uint32_t a_tintType)
	{
		using func_t = decltype(&PlayerCharacter::GetNumTints);
		REL::Offset<func_t> func(Offset::PlayerCharacter::GetNumTints);
		return func(this, a_tintType);
	}


	TintMask* PlayerCharacter::GetOverlayTintMask(TintMask* a_original)
	{
		if (!overlayTintMasks) {
			return nullptr;
		}

		for (std::uint32_t i = 0; i < tintMasks.size(); ++i) {
			if (tintMasks[i] == a_original) {
				return i < overlayTintMasks->size() ? (*overlayTintMasks)[i] : nullptr;
			}
		}

		return nullptr;
	}


	BSTArray<TintMask*>& PlayerCharacter::GetTintList()
	{
		return overlayTintMasks ? *overlayTintMasks : tintMasks;
	}


	TintMask* PlayerCharacter::GetTintMask(std::uint32_t a_tintType, std::uint32_t a_index)
	{
		using func_t = decltype(&PlayerCharacter::GetTintMask);
		REL::Offset<func_t> func(Offset::PlayerCharacter::GetTintMask);
		return func(this, a_tintType, a_index);
	}


	bool PlayerCharacter::IsGrabbing() const
	{
		return static_cast<bool>(grabbedObject);
	}


	void PlayerCharacter::PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType)
	{
		using func_t = decltype(&PlayerCharacter::PlayPickupEvent);
		REL::Offset<func_t> func(Offset::PlayerCharacter::PlayPickupEvent);
		return func(this, a_item, a_containerOwner, a_containerRef, a_eventType);
	}


	void PlayerCharacter::StartGrabObject()
	{
		using func_t = decltype(&PlayerCharacter::StartGrabObject);
		REL::Offset<func_t> func(Offset::PlayerCharacter::StartGrabObject);
		return func(this);
	}
}
