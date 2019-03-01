#pragma once


namespace RE
{
	struct NiColor
	{
		float	red;	// 0
		float	green;	// 4
		float	blue;	// 8
	};
	STATIC_ASSERT(sizeof(NiColor) == 0xC);


	struct NiColorA
	{
		float	red;	// 00
		float	green;	// 04
		float	blue;	// 08
		float	alpha;	// 0C
	};
	STATIC_ASSERT(sizeof(NiColorA) == 0x10);
}
