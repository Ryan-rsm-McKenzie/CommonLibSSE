#pragma once

#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiTransform
	{
	public:
		NiMatrix3 rotate;     // 00
		NiPoint3  translate;  // 24
		float     scale;      // 30

		float GetHeadingAngle(const NiPoint3& a_targPos, bool b_abs = false) const
		{
			auto ToEulerAngleZ = [](const NiMatrix3& R) -> float {
				auto sy = std::sqrt(R.entry[0][0] * R.entry[0][0] + R.entry[0][1] * R.entry[0][1]);
				auto singular = sy < 1e-6;
				if (!singular)
					return std::atan2f(R.entry[0][1], R.entry[0][0]);
				else
					return 0.f;
			};
			
			float theta = std::atan2f(a_targPos.x - translate.x, a_targPos.y - translate.y);
			float heading = static_cast<float>(180.0f / std::numbers::pi * (theta - ToEulerAngleZ(rotate)));

			if (heading < -180.f)
				heading += 360.f;

			if (heading > 180.f)
				heading -= 360.f;

			return b_abs ? abs(heading) : heading;
		}
	};

	static_assert(sizeof(NiTransform) == 0x34);
}
