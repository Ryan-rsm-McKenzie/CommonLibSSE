#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/AITimer.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatLocation.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class CombatController;

	class CombatTimers
	{
	public:
		struct Data80
		{
			CombatLocation unk00;  // 10
			AITimeStamp    unk18;  // 18
			float          unk20;  // 20
		};
		static_assert(sizeof(Data80) == 0x20);

		// members
		float             unk00;                         // 00
		bool              fleeing;                       // 04
		std::uint8_t      unk05;                         // 05
		std::uint8_t      unk06;                         // 06
		std::uint8_t      unk07;                         // 07
		std::uint8_t      unk08;                         // 08
		std::uint8_t      unk09;                         // 09
		std::uint8_t      unk0A;                         // 0A
		std::uint8_t      unk0B;                         // 0B
		std::uint32_t     unk0C;                         // 0C
		NiPoint3          unk10;                         // 10
		AITimeStamp       activeCombatantLastSeenTimer;  // 1C
		AITimeStamp       unk20;                         // 20
		AITimeStamp       unk24;                         // 24
		AITimeStamp       unk28;                         // 28
		AITimer           attackDialogueTimer;           // 2C
		AITimer           tauntDialogueTimer;            // 34
		AITimer           bleedOutDialogueTimer;         // 3C
		AITimer           fleeDialogueTimer;             // 44
		std::uint32_t     unk4C;                         // 4C
		BSTArray<void*>   unk50;                         // 50
		AITimeStamp       unk68;                         // 68
		std::uint8_t      unk6C;                         // 6C
		std::uint8_t      unk6D;                         // 6D
		float             confidenceModifier;            // 70
		float             threatValue;                   // 74
		float             unk78;                         // 78
		std::uint32_t     unk7C;                         // 7C
		BSTArray<Data80>  unk80;                         // 80
		CombatController* unk98;                         // 98
		std::uint8_t      unkA0;                         // A0
		AITimer           strengthUpdateTimer;           // A4
		AITimer           threatRatioUpdateTimer;        // AC
		AITimer           threatUpdateTimer;             // B4
	};
	static_assert(sizeof(CombatTimers) == 0xC0);
}
