#pragma once


namespace RE
{
	class NiPoint3
	{
	public:
		constexpr NiPoint3();
		constexpr NiPoint3(float a_x, float a_y, float a_z);

		float&			operator[](std::size_t a_idx);
		const float&	operator[](std::size_t a_idx) const;
		bool			operator==(const NiPoint3& a_rhs) const;
		bool			operator!=(const NiPoint3& a_rhs) const;
		NiPoint3		operator+(const NiPoint3& a_rhs) const;
		NiPoint3		operator-(const NiPoint3& a_rhs) const;
		float			operator*(const NiPoint3& a_rhs) const;
		NiPoint3		operator*(float a_scalar) const;
		NiPoint3		operator/(float a_scalar) const;
		NiPoint3		operator-() const;
		NiPoint3&		operator+=(const NiPoint3& a_rhs);
		NiPoint3&		operator-=(const NiPoint3& a_rhs);
		NiPoint3&		operator*=(float a_scalar);
		NiPoint3&		operator/=(float a_scalar);

		float			SqrLength() const;
		float			Length() const;
		float			Unitize();
		NiPoint3		Cross(const NiPoint3 &pt) const;
		NiPoint3		UnitCross(const NiPoint3& a_pt) const;


		// members
		float	x;	// 0
		float	y;	// 4
		float	z;	// 8
	};
	STATIC_ASSERT(sizeof(NiPoint3) == 0xC);


	constexpr NiPoint3::NiPoint3() :
		x(0.0),
		y(0.0),
		z(0.0)
	{}


	constexpr NiPoint3::NiPoint3(float a_x, float a_y, float a_z) :
		x(a_x),
		y(a_y),
		z(a_z)
	{};
}
