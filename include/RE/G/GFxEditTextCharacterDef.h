#pragma once

#include "RE/G/GFxCharacterDef.h"

namespace RE
{
	class GFxEditTextCharacterDef : public GFxCharacterDef
	{
	public:
		~GFxEditTextCharacterDef() override;  // 00

		// override (GFxResource)
		std::uint32_t GetResourceTypeCode() const override;  // 02

		// override (GFxCharacterDef)
		virtual GFxCharacter* CreateCharacter();  // 09

		// members
		std::uint64_t unk20[11];  // 20
	};
	static_assert(sizeof(GFxEditTextCharacterDef) == 0x78);
}
