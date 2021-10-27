#pragma once

#include "RE/G/GFxShapeBase.h"

namespace RE
{
	class GFxConstShapeNoStyles : public GFxShapeBase
	{
		~GFxConstShapeNoStyles() override;  // 00

		// override (GFxShapeBase)
		bool         HitTest(const GPointF& a_pt, bool a_arg2, void* a_arg3) override;  // 03
		void         Unk_04(void* a_arg1, float a_arg2, void* a_arg3) override;         // 04
		void         Unk_05(GRectF& a_arg1) override;                                   // 05
		void         Unk_06(void* a_arg1, float a_arg2) override;                       // 06
		void         Unk_07(void) override;                                             // 07
		bool         Unk_08(void* a_arg1) override;                                     // 08
		void*        Unk_0F(void) override;                                             // 0F
		std::int32_t Unk_10(void) override;                                             // 10
		void         Unk_11(std::int32_t* a_arg1, std::int32_t* a_arg2) override;       // 11
		void*        Unk_12(void) override;                                             // 12

		// members
		std::uint64_t unk40;  // 40
	};
	static_assert(sizeof(GFxConstShapeNoStyles) == 0x48);
}
