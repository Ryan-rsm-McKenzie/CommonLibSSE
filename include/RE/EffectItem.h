#pragma once

#include "RE/Condition.h"  // Condition


namespace RE
{
	class Condition;
	class EffectSetting;


	struct EffectItem
	{
		// members
		float			magnitude;	// 00
		UInt32			area;		// 04
		UInt32			duration;	// 08
		UInt32			pad0C;		// 0C
		EffectSetting*	mgef;		// 10
		float			cost;		// 18
		UInt32			pad1C;		// 1C
		Condition		conditions;	// 20
	};
}