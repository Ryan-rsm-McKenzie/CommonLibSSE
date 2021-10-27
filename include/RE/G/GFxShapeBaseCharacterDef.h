#pragma once

#include "RE/G/GFxCharacterDef.h"

namespace RE
{
	class GFxShapeBaseCharacterDef : public GFxCharacterDef
	{
	public:
		~GFxShapeBaseCharacterDef() override;  // 00

		// override (GFxResource)
		std::uint32_t GetResourceTypeCode() const override;  // 02

		// override (GFxCharacterDef)
		void Unk_04(void) override = 0;  // 04
		void Unk_06(void) override = 0;  // 06
		void Unk_07(void) override = 0;  // 07

		// add
		virtual void Unk_0A(void) = 0;  // 0A
		virtual void Unk_0B(void) = 0;  // 0B
		virtual void Unk_0C(void) = 0;  // 0C
		virtual void Unk_0D(void) = 0;  // 0D
		virtual void Unk_0E(void) = 0;  // 0E
		virtual void Unk_0F(void) = 0;  // 0F
		virtual void Unk_10(void) = 0;  // 10
		virtual void Unk_11(void) = 0;  // 11
	};
	static_assert(sizeof(GFxShapeBaseCharacterDef) == 0x20);
}
