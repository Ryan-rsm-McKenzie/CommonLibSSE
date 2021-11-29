#include "RE/N/NiMatrix3.h"

#include "RE/N/NiMath.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	bool NiMatrix3::ToEulerAnglesXYZ(NiPoint3& a_angle) const
	{
		return ToEulerAnglesXYZ(a_angle.x, a_angle.y, a_angle.z);
	}

	bool NiMatrix3::ToEulerAnglesXYZ(float& a_xAngle, float& a_yAngle, float& a_zAngle) const
	{
		a_yAngle = -NiASin(entry[0][2]);
		if (a_yAngle < NI_HALF_PI) {
			if (a_yAngle > -NI_HALF_PI) {
				a_xAngle = -NiFastATan2(-entry[1][2], entry[2][2]);
				a_zAngle = -NiFastATan2(-entry[0][1], entry[0][0]);
				return true;
			} else {
				float rmY = NiFastATan2(entry[1][0], entry[1][1]);
				a_zAngle = 0.0;
				a_xAngle = rmY - a_zAngle;
				return false;
			}
		} else {
			float rpY = NiFastATan2(entry[1][0], entry[1][1]);
			a_zAngle = 0.0;
			a_xAngle = a_zAngle - rpY;
			return false;
		}
	}
}
