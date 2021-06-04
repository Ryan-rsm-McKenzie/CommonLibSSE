#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESHitEvent
	{
	public:
		enum class Flag
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
		NiPointer<TESObjectREFR>             target;      // 00
		NiPointer<TESObjectREFR>             cause;       // 08
		FormID                               source;      // 10
		FormID                               projectile;  // 14
		stl::enumeration<Flag, std::uint8_t> flags;       // 18
		std::uint8_t                         pad19;       // 19
		std::uint16_t                        pad1A;       // 1A
		std::uint32_t                        pad1C;       // 1C
	};
	static_assert(sizeof(TESHitEvent) == 0x20);
}
