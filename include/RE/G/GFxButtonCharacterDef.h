#pragma once

#include "RE/G/GFxCharacterDef.h"

namespace RE
{
	// 0x17e8568
	class GFxButtonCharacterDef : public GFxCharacterDef
	{
	public:
		~GFxButtonCharacterDef() override;  // 00

		// override (GFxResource)
		std::uint32_t GetResourceTypeCode() const override;  // 02

		// override (GFxCharacterDef)
		virtual void          Unk_06(void);       // 06
		virtual GFxCharacter* CreateCharacter();  // 09

		// members
		std::uint64_t unk20[8];  // 20
	};
	static_assert(sizeof(GFxButtonCharacterDef) == 0x60);
}
