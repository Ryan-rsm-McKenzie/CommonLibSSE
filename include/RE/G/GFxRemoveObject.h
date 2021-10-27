#pragma once

#include "RE/G/GASExecuteTag.h"

namespace RE
{
	class GFxRemoveObject : public GASExecuteTag
	{
	public:
		~GFxRemoveObject() override;  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		bool Unk_03(void) override;                   // 03
		void Unk_06(void) override;                   // 06

		// members
		std::uint16_t characterId;  // 08
		std::uint16_t depth;        // 0A
		std::uint32_t pad0C;        // 0A
	};
	static_assert(sizeof(GFxRemoveObject) == 0x10);
}
