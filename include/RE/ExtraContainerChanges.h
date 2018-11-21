#pragma once

#include "skse64/GameExtraData.h"  // BSExtraData, ExtraContainerChanges

#include "RE/InventoryChanges.h"  // InventoryChanges

class TESForm;


namespace RE
{
	class ExtraContainerChanges : public BSExtraData
	{
	public:
		ExtraContainerChanges();
		virtual	~ExtraContainerChanges();

		::ExtraContainerChanges::FoundEquipData		FindEquipped(FormMatcher& a_matcher, bool a_isWorn = true, bool a_isWornLeft = true);
		::ExtraContainerChanges::FoundHotkeyData	FindHotkey(SInt32 a_hotkey);
		::ExtraContainerChanges::FoundHotkeyData	FindHotkey(TESForm* a_form);


		InventoryChanges*	changes;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraContainerChanges) == 0x18);
}
