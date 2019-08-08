#pragma once

#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class TESObjectREFR;


	struct TESHitEvent
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kPowerAttack = 1 << 0,
			kSneakAttack = 1 << 1,
			kBashAttack = 1 << 2,
			kHitBlocked = 1 << 3
		};


		TESHitEvent();
		TESHitEvent(TESObjectREFR* a_target, TESObjectREFR* a_aggressor, FormID a_weapon, FormID a_projectile, Flag a_flags);
		~TESHitEvent() = default;


		// members
		NiPointer<TESObjectREFR>	target;		// 00
		NiPointer<TESObjectREFR>	aggressor;	// 08
		FormID						weapon;		// 10
		FormID						projectile;	// 14
		Flag						flags;		// 18
		UInt8						pad19;		// 19
		UInt16						pad1A;		// 1A
		UInt32						pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(TESHitEvent) == 0x20);
}
