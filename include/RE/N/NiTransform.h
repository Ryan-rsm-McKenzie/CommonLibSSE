#pragma once

#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiTransform
	{
	public:

		NiTransform() = default;
		NiTransform(const NiMatrix3& a_rotate, const NiPoint3& a_translate, float a_scale = 0.f);

		NiMatrix3 rotate;     // 00
		NiPoint3  translate;  // 24
		float     scale;      // 30

		float GetHeadingAngle(const NiPoint3& a_targPos, bool b_abs = false) const;

	};

	static_assert(sizeof(NiTransform) == 0x34);
}
