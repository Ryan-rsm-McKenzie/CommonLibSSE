#pragma once

#include "RE/G/GFxConstShapeNoStyles.h"

namespace RE
{
	class GFxConstShapeWithStyles : public GFxConstShapeNoStyles
	{
		~GFxConstShapeWithStyles() override;

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
		std::uint64_t unk48;        // 48
		std::uint64_t unk50;        // 50
		std::uint32_t unk58;        // 58
		std::uint32_t unk5C;        // 5C
		float         percent;      // 60
		GRectF        shapeBounds;  // 64
		std::uint32_t pad74;        // 74
	};
	static_assert(sizeof(GFxConstShapeWithStyles) == 0x78);
}
