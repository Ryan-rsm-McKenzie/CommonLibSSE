#pragma once

#include "RE/MemoryManager.h"
#include "RE/TESCondition.h"


namespace RE
{
	class EffectSetting;


	struct Effect
	{
	public:
		struct EffectItem  // EFIT
		{
		public:
			EffectItem();
			~EffectItem() = default;


			// members
			float  magnitude;  // 0
			UInt32 area;	   // 4
			UInt32 duration;   // 8
		};
		STATIC_ASSERT(sizeof(EffectItem) == 0xC);


		Effect();
		~Effect() = default;

		TES_HEAP_REDEFINE_NEW();


		// members
		EffectItem	   effectItem;	// 00 - EFIT
		UInt32		   pad0C;		// 0C
		EffectSetting* baseEffect;	// 10 - EFID
		float		   cost;		// 18
		UInt32		   pad1C;		// 1C
		TESCondition   conditions;	// 20 - CTDA
	};
	STATIC_ASSERT(sizeof(Effect) == 0x28);
}
