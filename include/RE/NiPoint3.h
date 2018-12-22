#pragma once


namespace RE
{
	class NiPoint3
	{
	public:
		NiPoint3();
		NiPoint3(float a_x, float a_y, float a_z);

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
		float			QuickLength() const;
		float			QuickUnitize();
		NiPoint3		Cross(const NiPoint3 &pt) const;
		NiPoint3		UnitCross(const NiPoint3& a_pt) const;

		static float	VectorLength(const NiPoint3& a_vec);
		static float	UnitizeVector(NiPoint3& a_vec);


		// members
		float	x;	// 0
		float	y;	// 4
		float	z;	// 8

	protected:
		static unsigned int _sqrtTable[256];
	};
	STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
}
