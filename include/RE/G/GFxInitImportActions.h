#pragma once

#include "RE/G/GASExecuteTag.h"

namespace RE
{
	class GFxInitImportActions : public GASExecuteTag
	{
	public:
		virtual ~GFxInitImportActions();  // 00

		// override (GASExecuteTag)
		void Execute1(GFxSprite* a_sprite) override;  // 01
		bool Unk_05(void) override;                   // 05

		// members
		std::uint32_t movieIndex;  // 08
		std::uint32_t pad0C;       // 0C
	};
	static_assert(sizeof(GFxInitImportActions) == 0x10);
}
