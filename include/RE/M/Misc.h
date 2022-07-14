#pragma once

#include "RE/B/BSString.h"

namespace RE
{
	class Actor;
	template <class T>
	class NiPointer;
	class Setting;
	class TESObjectREFR;
	class TESForm;
	class InventoryEntryData;

	template <class... Args>
	void ApplyPerkEntries(std::uint8_t a_perkEntryCode, Actor* a_perkOwner, Args... a_args)
	{
		static_assert((std::is_pointer_v<Args> && ...), "arguments must all be pointers");
		using func_t = void(std::uint8_t, Actor*, ...);
		REL::Relocation<func_t> func{ REL::ID(23526) };
		return func(a_perkEntryCode, a_perkOwner, a_args...);
	}

	void     CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refrTo);
	void     DebugNotification(const char* a_notification, const char* a_soundToPlay = 0, bool a_cancelIfAlreadyQueued = true);
	void     DebugMessageBox(const BSString& a_message);
	float    GetDurationOfApplicationRunTime();
	float    GetArmorFinalRating(InventoryEntryData* a_entryData, float a_armorPerks, float a_skillMultiplier);
	Setting* GetINISetting(const char* a_name);
	bool     LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool     LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void     PlaySound(const char* a_editorID);
}
