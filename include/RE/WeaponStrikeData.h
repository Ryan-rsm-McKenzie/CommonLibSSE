#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiRefObject;
	class TESObjectWEAP;


	class WeaponStrikeData
	{
	public:
		enum class Flag : UInt32
		{
			kNone = 0,
			kCriticalStrike = 1 << 3,
			kSneakAttack = 1 << 11,
			kPowerAttack = 1 << 16,
			kLeftHand = 1 << 17
		};


		// members
		float					unk00;		// 00
		float					unk04;		// 04
		float					unk08;		// 08
		float					unk0C;		// 0C
		float					unk10;		// 10
		float					unk14;		// 14
		RefHandle				unk18;		// 18
		UInt32					unk1C;		// 1C
		RefHandle				unk20;		// 20
		UInt32					unk24;		// 24
		NiPointer<NiRefObject>	unk28;		// 28
		TESObjectWEAP*			unk30;		// 30
		UInt64					unk38;		// 38
		UInt64					unk40;		// 40
		UInt64					unk48;		// 48
		UInt32					unk50;		// 50
		UInt32					unk54;		// 54
		UInt64					unk58;		// 58
		UInt64					unk60;		// 60
		float					unk68;		// 68
		float					unk6C;		// 6C
		float					damageMult;	// 70
		UInt32					unk74;		// 74
		float					unk78;		// 78
		UInt32					unk7C;		// 7C
		Flag					flags;		// 80
		UInt32					unk84;		// 84
		SInt32					unk88;		// 88
		SInt32					unk8C;		// 8C
	};
	STATIC_ASSERT(sizeof(WeaponStrikeData) == 0x90);
}
