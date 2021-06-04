#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiRefObject.h"
#include "RE/S/SetEventData.h"

namespace RE
{
	class AttackAnimationArrayMap :
		public NiRefObject,                                              // 00
		public BSTHashMap<std::uint32_t, BSTArray<SetEventData> const*>  // 10
	{
	public:
		inline static constexpr auto RTTI = RTTI_AttackAnimationArrayMap;

		// hash key (hiword = right hand | loward = left hand)
		enum HashKey : std::uint32_t
		{
			kHandToHandMelee,
			kOneHandSword,
			kOneHandDagger,
			kOneHandAxe,
			kOneHandMace,
			kTwoHandSword,
			kTwoHandAxe,
			kBow,
			kStaff,
			kCrossbow,
			kSpell,
			kShield
		};

		virtual ~AttackAnimationArrayMap();  // 00
	};
	static_assert(sizeof(AttackAnimationArrayMap) == 0x40);
}
