#include "RE/NiPoint3.h"


namespace RE
{
	NiPoint3::NiPoint3() :
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{}


	NiPoint3::NiPoint3(float a_x, float a_y, float a_z) :
		x(a_x),
		y(a_y),
		z(a_z)
	{};


	float& NiPoint3::operator[](std::size_t a_idx)
	{
		const float *arr = &x;
		return (float &)arr[a_idx];
	}


	const float& NiPoint3::operator[](std::size_t a_idx) const
	{
		const float *arr = &x;
		return (float &)arr[a_idx];
	}


	bool NiPoint3::operator==(const NiPoint3& a_rhs) const
	{
		return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z);
	}


	bool NiPoint3::operator!=(const NiPoint3& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	NiPoint3 NiPoint3::operator+(const NiPoint3& a_rhs) const
	{
		return NiPoint3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
	}


	NiPoint3 NiPoint3::operator-(const NiPoint3& a_rhs) const
	{
		return NiPoint3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
	}


	float NiPoint3::operator*(const NiPoint3& a_rhs) const
	{
		return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z;
	}


	NiPoint3 NiPoint3::operator*(float a_scalar) const
	{
		return NiPoint3(x * a_scalar, y * a_scalar, z * a_scalar);
	}


	NiPoint3 NiPoint3::operator/(float a_scalar) const
	{
		return (*this) * (1.0f / a_scalar);
	}


	NiPoint3 NiPoint3::operator-() const
	{
		return NiPoint3(-x, -y, -z);
	}


	NiPoint3& NiPoint3::operator+=(const NiPoint3& a_rhs)
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		return *this;
	}


	NiPoint3& NiPoint3::operator-=(const NiPoint3& a_rhs)
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		return *this;
	}


	NiPoint3& NiPoint3::operator*=(float a_scalar)
	{
		x *= a_scalar;
		y *= a_scalar;
		z *= a_scalar;
		return *this;
	}


	NiPoint3& NiPoint3::operator/=(float a_scalar)
	{
		return (*this) *= (1.0f / a_scalar);
	}


	float NiPoint3::SqrLength() const
	{
		return x * x + y * y + z * z;
	}


	float NiPoint3::Length() const
	{
		return std::sqrt(x*x + y * y + z * z);
	}


	float NiPoint3::Unitize()
	{
		float length = Length();
		if (length > 1e-6f) {
			(*this) /= length;
		} else {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			length = 0.0f;
		}
		return length;
	}


	float NiPoint3::QuickLength() const
	{
		float length = SqrLength();
		unsigned int *rep = (unsigned int*)&length;

		if (*rep == 0) {
			length = 0.0f;
		} else {
			short exp = ((*rep) >> 23) - 127;
			*rep &= 0x007fffff;
			if (exp & 1) {
				*rep |= 0x00800000;
			}
			exp >>= 1;
			*rep = _sqrtTable[(*rep) >> 16] | ((exp + 127) << 23);
		}

		return length;
	}


	float NiPoint3::QuickUnitize()
	{
		float length = QuickLength();
		if (length > 1e-6f) {
			(*this) /= length;
		} else {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			length = 0.0f;
		}
		return length;
	}


	NiPoint3 NiPoint3::Cross(const NiPoint3& a_pt) const
	{
		return NiPoint3(
			y * a_pt.z - z * a_pt.y,
			z * a_pt.x - x * a_pt.z,
			x * a_pt.y - y * a_pt.x
		);
	}


	NiPoint3 NiPoint3::UnitCross(const NiPoint3& a_pt) const
	{
		NiPoint3 cross = Cross(a_pt);
		cross.Unitize();
		return cross;
	}


	float NiPoint3::VectorLength(const NiPoint3& a_vec)
	{
		return a_vec.QuickLength();
	}


	float NiPoint3::UnitizeVector(NiPoint3& a_vec)
	{
		return a_vec.QuickUnitize();
	}
}
