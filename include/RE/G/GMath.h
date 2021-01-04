#pragma once

namespace RE
{
	constexpr double GFC_MATH_LN2 = 0.69314718055994530942;

	constexpr std::int32_t gfchop(float a_val)
	{
		return static_cast<std::int32_t>(a_val);
	}

	inline float glog2f(float a_val)
	{
		return std::logf(a_val) / static_cast<float>(GFC_MATH_LN2);
	}
}
