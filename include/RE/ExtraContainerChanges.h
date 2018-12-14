#pragma once

#include "skse64/GameExtraData.h"  // ExtraContainerChanges

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/InventoryChanges.h"  // InventoryChanges
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraContainerChanges : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kContainerChanges };

		
		virtual	~ExtraContainerChanges();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kContainerChanges; }

		::ExtraContainerChanges::FoundEquipData		FindEquipped(FormMatcher& a_matcher, bool a_isWorn = true, bool a_isWornLeft = true);
		::ExtraContainerChanges::FoundHotkeyData	FindHotkey(SInt32 a_hotkey);
		::ExtraContainerChanges::FoundHotkeyData	FindHotkey(TESForm* a_form);


		// members
		InventoryChanges*	changes;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraContainerChanges) == 0x18);
}
