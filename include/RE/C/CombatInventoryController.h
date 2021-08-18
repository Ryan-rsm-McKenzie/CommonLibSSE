#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/AITimer.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSEquipSlot;
	class CombatController;
	class CombatInventoryItem;
	class CombatObject;
	class TESObjectWEAP;
	class TESForm;

	class CombatInventoryController
	{
	public:
		struct UnkStruct
		{
			BSTArray<void*> unk00;
			std::uint32_t   unk18;
			float           unk1C;
			float           unk20;  //combat range
			float           unk24;  //combat range
			std::uint32_t   unk28;
		};
		static_assert(sizeof(UnkStruct) == 0x30);

		struct Data178
		{
			NiPointer<CombatInventoryItem> unk00;
			AITimeStamp                    unk08;
		};
		static_assert(sizeof(Data178) == 0x10);

		// members
		CombatController*                        parentController;   // 000
		BSTArray<NiPointer<CombatInventoryItem>> inventoryItems[7];  // 008
		BSTArray<TESForm*>                       unk0B0;             // 0B0
		BSTArray<TESForm*>                       unk0C8;             // 0C8
		BSTArray<BGSEquipSlot*>*                 raceEquipSlots;     // 0E0
		std::uint64_t                            unk0E8;             // 0E8
		std::uint32_t                            unk0F0;             // 0F0
		std::uint32_t                            unk0F4;             // 0F4
		std::uint32_t                            unk0F8;             // 0F8
		std::uint32_t                            unk0FC;             // 0FC
		std::uint64_t                            unk100;             // 100
		std::uint64_t                            unk108;             // 108
		std::uint64_t                            unk110;             // 110
		UnkStruct                                unk118;             // 118
		UnkStruct                                unk148;             // 148
		BSTArray<Data178>                        unk178;             // 178
		std::int32_t                             unk190;             // 190
		AITimer                                  unk194;             // 194
		std::uint32_t                            unk19C;             // 19C
		std::uint32_t                            unk1A0;             // 1A0
		std::uint32_t                            unk1A4;             // 1A4
		float                                    unk1A8;             // 1A8
		float                                    unk1AC;             // 1AC
		float                                    unk1B0;             // 1B0
		float                                    unk1B4;             // 1B4
		float                                    unk1B8;             // 1B8
		float                                    unk1BC;             // 1BC
		float                                    unk1C0;             // 1C0
		std::uint8_t                             unk1C4;             // 1C4
	};
	static_assert(sizeof(CombatInventoryController) == 0x1C8);
}
