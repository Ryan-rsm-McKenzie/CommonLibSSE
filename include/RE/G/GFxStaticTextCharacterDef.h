#pragma once

#include "RE/G/GFxCharacterDef.h"

namespace RE
{
	class GFxStaticTextCharacterDef : public GFxCharacterDef
	{
	public:
		~GFxStaticTextCharacterDef() override;  // 00

		// override (GFxCharacterDef)
		bool          Unk_05(const GPointF& a_pt, bool a_arg2, void* a_arg3) override;  // 05
		void          Unk_06(void) override;                                            // 06
		GFxCharacter* CreateCharacter() override;                                       // 09

		// override (GFxResource)
		std::uint32_t GetResourceTypeCode() const override;  // 02

		// members
		GRectF        bounds;    // 20
		std::uint64_t unk30[7];  // 30
	};
	static_assert(sizeof(GFxStaticTextCharacterDef) == 0x68);
}
