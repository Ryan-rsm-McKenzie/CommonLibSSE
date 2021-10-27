#pragma once

#include "RE/G/GFxShapeNoStyles.h"

namespace RE
{
	class GFxShapeWithStyles : public GFxShapeNoStyles
	{
		~GFxShapeWithStyles() override;

		// override (GFxShapeBase)
		void* GetBounds(GRectF& a_arg1) const override;                                                          // 01
		void  SetBounds(GRectF& a_arg1) override;                                                                // 02
		void  Unk_04(void* a_arg1, float a_arg2, void* a_arg3) override;                                         // 04
		void* GetFillStyles(std::int32_t& a_arg1) const override;                                                // 09
		void* GetLineStyles(std::int32_t& a_arg1) const override;                                                // 0A
		void  GetStyles(void* a_arg1) const override;                                                            // 0B
		void  GetStyles(void* a_arg1, std::int32_t* a_arg2, void* a_arg3, std::int32_t* a_arg4) const override;  // 0C
		void  SetPercent(float a_arg1) override;                                                                 // 0D
		float GetPercent() const override;                                                                       // 0E

		// members
		void*         unk70;            // 70
		std::uint64_t unk78;            // 78
		std::uint16_t unk80;            // 80
		std::uint16_t unk82;            // 82
		std::uint32_t pad84;            // 84
		void*         fillStyles;       // 88 - array with elements 0x38 wide (GFxGradientData?) - fill styles?
		std::int32_t  fillStylesCount;  // 90
		std::uint32_t unk94;            // 94
		std::uint64_t unk98;            // 98
		void*         lineStyles;       // A0 - line styles? (GFxLineStyle)
		std::int32_t  lineStylesCount;  // A8
		std::uint32_t unkAC;            // AC
		std::uint64_t unkB0;            // B0
		float         percent;          // B8
		GRectF        shapeBounds;      // BC
		std::uint32_t padCC;            // CC
	};
	static_assert(sizeof(GFxShapeWithStyles) == 0xD0);
}
