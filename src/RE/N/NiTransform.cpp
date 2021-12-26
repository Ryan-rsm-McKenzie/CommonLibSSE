#include "RE/N/NiTransform.h"

namespace RE
{
	NiTransform::NiTransform(const NiMatrix3& a_rotate, const NiPoint3& a_translate, float a_scale)
	{
		this->rotate = a_rotate;
		this->translate = a_translate;
		this->scale = a_scale;
	}


	float NiTransform::GetHeadingAngle(const NiPoint3& a_targPos, bool b_abs) const
	{
		auto ToEulerAngleZ = [](const NiMatrix3& R) -> float {
			auto sy = std::sqrt(R.entry[0][0] * R.entry[0][0] + R.entry[0][1] * R.entry[0][1]);
			return sy < 1e-6 ? 0.f : std::atan2f(R.entry[0][1], R.entry[0][0]);
		};
		
		float theta = std::atan2f(a_targPos.x - translate.x, a_targPos.y - translate.y);
		float heading = static_cast<float>(180.0f / std::numbers::pi * (theta - ToEulerAngleZ(rotate)));

		if (heading < -180.f)
			heading += 360.f;

		if (heading > 180.f)
			heading -= 360.f;

		return b_abs ? abs(heading) : heading;
	}
}
