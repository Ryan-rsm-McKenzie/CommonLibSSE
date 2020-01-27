#pragma once


namespace RE
{
	class NiColor;
	class NiColorA;


	class NiColor
	{
	public:
		NiColor();
		NiColor(const NiColor& a_rhs);
		NiColor(NiColor&& a_rhs);
		NiColor(float a_red, float a_green, float a_blue);
		~NiColor() = default;

		NiColor& operator=(const NiColor& a_rhs);
		NiColor& operator=(NiColor&& a_rhs);
		NiColor& operator=(const NiColorA& a_rhs);


		// members
		float	red;	// 0
		float	green;	// 4
		float	blue;	// 8
	};
	STATIC_ASSERT(sizeof(NiColor) == 0xC);


	class NiColorA
	{
	public:
		NiColorA();
		NiColorA(const NiColorA& a_rhs);
		NiColorA(NiColorA&& a_rhs);
		NiColorA(float a_red, float a_green, float a_blue, float a_alpha);
		~NiColorA() = default;

		NiColorA& operator=(const NiColorA& a_rhs);
		NiColorA& operator=(NiColorA&& a_rhs);
		NiColorA& operator=(const NiColor& a_rhs);


		// members
		float	red;	// 00
		float	green;	// 04
		float	blue;	// 08
		float	alpha;	// 0C
	};
	STATIC_ASSERT(sizeof(NiColorA) == 0x10);
}
