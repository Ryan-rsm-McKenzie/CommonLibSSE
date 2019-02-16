#pragma once

#include "RE/Condition.h"  // Condition


namespace RE
{
	class EffectSetting;


	struct Effect
	{
		struct EffectItem	// EFIT
		{
			float	magnitude;	// 00
			UInt32	area;		// 04
			UInt32	duration;	// 08
			UInt32	pad0C;		// 0C
		};
		STATIC_ASSERT(sizeof(EffectItem) == 0x10);


		// members
		EffectItem		effectItem;	// 00 - EFIT
		EffectSetting*	baseEffect;	// 10 - EFID
		float			cost;		// 18
		UInt32			pad1C;		// 1C
		Condition		conditions;	// 20 - CTDA
	};
	STATIC_ASSERT(sizeof(Effect) == 0x28);
}
