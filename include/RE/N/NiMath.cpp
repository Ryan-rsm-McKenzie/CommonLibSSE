#include "RE/N/NiMath.h"

namespace RE
{
	float NiAbs(float a_value)
	{
		return std::fabs(a_value);
	}

	float NiASin(float a_value)
	{
		if (-1.0 < a_value) {
			if (a_value < 1.0) {
				return std::asin(a_value);
			} else {
				return NI_HALF_PI;
			}
		} else {
			return -NI_HALF_PI;
		}
	}

	float NiFastATan2(float a_y, float a_x)
	{
		if (a_x == 0.0 && a_y == 0.0) {
			return 0.0;
		}

		float offset = 0.0;
		float z;
		if (NiAbs(a_y) > NiAbs(a_x)) {
			z = a_x / a_y;
			if (z > 0.0) {
				offset = NI_HALF_PI;
			} else if (z < 0.0) {
				offset = -NI_HALF_PI;
			} else {
				return (a_y > 0.0) ? NI_HALF_PI : -NI_HALF_PI;
			}
		} else {
			z = a_y / a_x;
			if (z == 0.0) {
				return (a_x > 0.0) ? static_cast<float>(0.0) : NI_PI;
			}
		}

		float z2 = z * z;

		float result;
		result = static_cast<float>(0.0208351);
		result *= z2;
		result -= static_cast<float>(0.0851330);
		result *= z2;
		result += static_cast<float>(0.1801410);
		result *= z2;
		result -= static_cast<float>(0.3302995);
		result *= z2;
		result += static_cast<float>(0.9998660);
		result *= z;

		if (offset) {
			result = offset - result;
		}

		if (a_y < 0.0 && a_x < 0.0) {
			result -= NI_PI;
		}
		if (a_y > 0.0 && a_x < 0.0) {
			result += NI_PI;
		}

		return result;
	}
}
