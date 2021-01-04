#pragma once

#include "RE/M/MemoryManager.h"
#include "RE/T/TESCondition.h"

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
			float		  magnitude;  // 0
			std::uint32_t area;		  // 4
			std::uint32_t duration;	  // 8
		};
		static_assert(sizeof(EffectItem) == 0xC);

		Effect();
		~Effect() = default;

		TES_HEAP_REDEFINE_NEW();

		// members
		EffectItem	   effectItem;	// 00 - EFIT
		std::uint32_t  pad0C;		// 0C
		EffectSetting* baseEffect;	// 10 - EFID
		float		   cost;		// 18
		std::uint32_t  pad1C;		// 1C
		TESCondition   conditions;	// 20 - CTDA
	};
	static_assert(sizeof(Effect) == 0x28);
}
