#pragma once


namespace RE
{
	constexpr float NI_INFINITY = FLT_MAX;
	constexpr float NI_PI = 3.1415926535897932;
	constexpr float NI_HALF_PI = 0.5 * NI_PI;
	constexpr float NI_TWO_PI = 2.0 * NI_PI;


	float NiAbs(float a_value);
	float NiASin(float a_value);
	float NiFastATan2(float a_y, float a_x);
}
