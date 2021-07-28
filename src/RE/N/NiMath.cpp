#include "RE/N/NiMath.h"

namespace RE
{
	float NiAbs(float a_value)
	{
		return std::fabs(a_value);
	}

	float NiASin(float a_value)
	{
		if (-1.0F < a_value) {
			if (a_value < 1.0F) {
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
		if (a_x == 0.0F && a_y == 0.0F) {
			return 0.0F;
		}

		float offset = 0.0F;
		float z;
		if (NiAbs(a_y) > NiAbs(a_x)) {
			z = a_x / a_y;
			if (z > 0.0F) {
				offset = NI_HALF_PI;
			} else if (z < 0.0F) {
				offset = -NI_HALF_PI;
			} else {
				return (a_y > 0.0F) ? NI_HALF_PI : -NI_HALF_PI;
			}
		} else {
			z = a_y / a_x;
			if (z == 0.0F) {
				return (a_x > 0.0F) ? 0.0F : NI_PI;
			}
		}

		float z2 = z * z;

		float result;
		result = 0.0208351F;
		result *= z2;
		result -= 0.0851330F;
		result *= z2;
		result += 0.1801410F;
		result *= z2;
		result -= 0.3302995F;
		result *= z2;
		result += 0.9998660F;
		result *= z;

		result = offset - result;

		if (a_y < 0.0F && a_x < 0.0F) {
			result -= NI_PI;
		}
		if (a_y > 0.0F && a_x < 0.0F) {
			result += NI_PI;
		}

		return result;
	}
}
