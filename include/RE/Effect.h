#pragma once

#include "RE/Condition.h"  // Condition
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class EffectSetting;


	struct Effect
	{
		struct EffectItem	// EFIT
		{
			EffectItem();
			~EffectItem() = default;

			float	magnitude;	// 0
			UInt32	area;		// 4
			UInt32	duration;	// 8
		};
		STATIC_ASSERT(sizeof(EffectItem) == 0xC);


		Effect();
		~Effect() = default;

		TES_HEAP_REDEFINE_NEW();


		// members
		EffectItem		effectItem;	// 00 - EFIT
		UInt32			pad0C;		// 0C
		EffectSetting*	baseEffect;	// 10 - EFID
		float			cost;		// 18
		UInt32			pad1C;		// 1C
		Condition		conditions;	// 20 - CTDA
	};
	STATIC_ASSERT(sizeof(Effect) == 0x28);
}
