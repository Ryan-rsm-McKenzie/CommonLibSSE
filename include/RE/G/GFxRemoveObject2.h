#pragma once

#include "RE/G/GASExecuteTag.h"

namespace RE
{
	class GFxRemoveObject2 : public GASExecuteTag
	{
	public:
		~GFxRemoveObject2() override;  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		bool Unk_03(void) override;                   // 03
		void Unk_06(void) override;                   // 06

		// members
		std::uint16_t depth;  // 08
		std::uint16_t pad0A;  // 0A
		std::uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(GFxRemoveObject2) == 0x10);
}
