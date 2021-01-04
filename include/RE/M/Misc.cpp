#include "RE/M/Misc.h"

#include "RE/I/INIPrefSettingCollection.h"
#include "RE/I/INISettingCollection.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/Setting.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	bool LookupReferenceByHandle_ActorImpl(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_ActorImpl);
		REL::Relocation<func_t> func{ Offset::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}

	bool LookupReferenceByHandle_RefrImpl(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle_RefrImpl);
		REL::Relocation<func_t> func{ Offset::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}

	void CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refTo)
	{
		using func_t = decltype(&CreateRefHandle);
		REL::Relocation<func_t> func{ Offset::CreateRefHandle };
		return func(a_handleOut, a_refTo);
	}

	void DebugNotification(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued)
	{
		using func_t = decltype(&DebugNotification);
		REL::Relocation<func_t> func{ Offset::DebugNotification };
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued);
	}

	Setting* GetINISetting(const char* a_name)
	{
		Setting* setting = nullptr;

		auto iniPrefs = INIPrefSettingCollection::GetSingleton();
		setting = iniPrefs ? iniPrefs->GetSetting(a_name) : nullptr;
		if (!setting) {
			auto ini = INISettingCollection::GetSingleton();
			setting = ini ? ini->GetSetting(a_name) : nullptr;
		}
		return setting;
	}

	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut)
	{
		return LookupReferenceByHandle_ActorImpl(a_handle, a_refrOut);
	}

	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle_RefrImpl(a_handle, a_refrOut);
	}

	void PlaySound(const char* a_editorID)
	{
		using func_t = decltype(&PlaySound);
		REL::Relocation<func_t> func{ Offset::PlaySound };
		return func(a_editorID);
	}

	void ApplyPerkEntries(std::uint8_t a_perkEntryCode, RE::Actor* a_perkOwner, RE::TESForm* a_form, float* a_value)
	{
		using func_t = decltype(&ApplyPerkEntries);
		REL::Relocation<func_t> func{ REL::ID(23073) };
		return func(a_perkEntryCode, a_perkOwner, a_form, a_value);
	}

	float GetArmorFinalRating(RE::InventoryEntryData* a_armorEntryData, float a_armorPerks, float a_skillMultiplier)
	{
		using func_t = decltype(&GetArmorFinalRating);
		REL::Relocation<func_t> func{ REL::ID(15779) };
		return func(a_armorEntryData, a_armorPerks, a_skillMultiplier);
	}
}
