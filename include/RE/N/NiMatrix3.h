#pragma once

namespace RE
{
	class NiPoint3;

	class NiMatrix3
	{
	public:
		bool ToEulerAnglesXYZ(NiPoint3& a_angle) const;
		bool ToEulerAnglesXYZ(float& a_xAngle, float& a_yAngle, float& a_zAngle) const;

		// members
		float entry[3][3];	// 00
	};
	static_assert(sizeof(NiMatrix3) == 0x24);
}
