#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/NiRefObject.h"  // NiRefObject
#include "RE/SetEventData.h"  // SetEventData


namespace RE
{
	class AttackAnimationArrayMap :
		public NiRefObject,											// 00
		public BSTHashMap<UInt32, BSTArray<SetEventData> const*>	// 10
	{
	public:
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


		virtual ~AttackAnimationArrayMap();	// 00
	};
	STATIC_ASSERT(sizeof(AttackAnimationArrayMap) == 0x40);
}
