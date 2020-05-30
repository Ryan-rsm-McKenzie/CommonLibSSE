#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/NiRefObject.h"
#include "RE/SetEventData.h"


namespace RE
{
	class AttackAnimationArrayMap :
		public NiRefObject,										  // 00
		public BSTHashMap<UInt32, BSTArray<SetEventData> const*>  // 10
	{
	public:
		inline static constexpr auto RTTI = RTTI_AttackAnimationArrayMap;


		// hash key (hiword = right hand | loward = left hand)
		enum HashKey : UInt32
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


		virtual ~AttackAnimationArrayMap();	 // 00
	};
	STATIC_ASSERT(sizeof(AttackAnimationArrayMap) == 0x40);
}
