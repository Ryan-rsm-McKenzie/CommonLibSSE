#pragma once

#include "RE/G/GNewOverrideBase.h"
#include "RE/G/GRect.h"

namespace RE
{
	class GFxShapeBase : public GNewOverrideBase<GFxStatMovieData::kGFxStatMD_CharDefs_Mem>
	{
		virtual ~GFxShapeBase();  // 00

		// add
		virtual void*        GetBounds(GRectF& a_arg1) const;                                                          // 01
		virtual void         SetBounds(GRectF& a_arg1);                                                                // 02
		virtual bool         HitTest(const GPointF& a_pt, bool a_arg2, void* a_arg3) = 0;                              // 03
		virtual void         Unk_04(void* a_arg1, float a_arg2, void* a_arg3) = 0;                                     // 04
		virtual void         Unk_05(GRectF& a_arg1) = 0;                                                               // 05
		virtual void         Unk_06(void* a_arg1, float a_arg2) = 0;                                                   // 06
		virtual void         Unk_07(void) = 0;                                                                         // 07
		virtual bool         Unk_08(void* a_arg1) = 0;                                                                 // 08
		virtual void*        GetFillStyles(std::int32_t& a_arg1) const;                                                // 09 - { return nullptr; }
		virtual void*        GetLineStyles(std::int32_t& a_arg1) const;                                                // 0A - { return nullptr; }
		virtual void         GetStyles(void* a_arg1) const;                                                            // 0B
		virtual void         GetStyles(void* a_arg1, std::int32_t* a_arg2, void* a_arg3, std::int32_t* a_arg4) const;  // 0C
		virtual void         SetPercent(float a_arg1);                                                                 // 0D
		virtual float        GetPercent() const;                                                                       // 0E - { return 100.0f; }
		virtual void*        Unk_0F(void) = 0;                                                                         // 0F
		virtual std::int32_t Unk_10(void) = 0;                                                                         // 10
		virtual void         Unk_11(std::int32_t* a_arg1, std::int32_t* a_arg2) = 0;                                   // 11
		virtual void*        Unk_12(void) = 0;                                                                         // 12

		// members
		GRectF        edgeBounds;  // 08
		std::int32_t  unk18;       // 18
		std::uint32_t pad1C;       // 1C
		std::uint64_t unk20;       // 20
		std::uint64_t unk28;       // 28
		std::uint64_t unk30;       // 30
		std::uint32_t unk38;       // 38
		std::uint32_t pad3C;       // 3C
	};
	static_assert(sizeof(GFxShapeBase) == 0x40);
}
