#pragma once

#include <cmath>


namespace RE
{
	constexpr double GFC_MATH_LN2 = 0.69314718055994530942;


	constexpr SInt32 gfchop(float a_val)
	{
		return static_cast<SInt32>(a_val);
	}


	inline float glog2f(float a_val)
	{
		return std::logf(a_val) / static_cast<float>(GFC_MATH_LN2);
	}
}
