#include "RE/H/hkVector4.h"

namespace RE
{
	hkVector4& hkVector4::operator=(const hkVector4& a_rhs)
	{
		quad = a_rhs.quad;
		return *this;
	}

	hkVector4 hkVector4::operator+(const hkVector4& a_rhs) const
	{
		return _mm_add_ps(quad, a_rhs.quad);
	}

	hkVector4 hkVector4::operator-(const hkVector4& a_rhs) const
	{
		return _mm_sub_ps(quad, a_rhs.quad);
	}

	hkVector4 hkVector4::operator*(const hkVector4& a_rhs) const
	{
		return _mm_mul_ps(quad, a_rhs.quad);
	}

	hkVector4 hkVector4::operator/(const hkVector4& a_rhs) const
	{
		return _mm_div_ps(quad, a_rhs.quad);
	}
}
