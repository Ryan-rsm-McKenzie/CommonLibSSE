#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class BSBatchRenderer
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSBatchRenderer;

		virtual ~BSBatchRenderer();  // 00

		// add
		virtual void Unk_01(void);  // 01
		virtual void Unk_02(void);  // 02
		virtual void Unk_03(void);  // 03

		// members
		BSTArray<void*>              unk008;      // 008
		BSTHashMap<UnkKey, UnkValue> unk020;      // 020
		std::uint64_t                unk050;      // 050
		std::uint64_t                unk058;      // 058
		std::uint64_t                unk060;      // 060
		std::uint64_t                unk068;      // 068
		void*                        unk070[16];  // 070
		std::uint64_t                unk0F0;      // 0F0
		std::uint64_t                unk0F8;      // 0F8
		std::uint64_t                unk100;      // 100
	};
	static_assert(sizeof(BSBatchRenderer) == 0x108);
}
