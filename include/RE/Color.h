#pragma once


namespace RE
{
	struct Color
	{
		UInt8	red;	// 0
		UInt8	green;	// 1
		UInt8	blue;	// 2
		UInt8	alpha;	// 3
	};
	STATIC_ASSERT(sizeof(Color) == 0x4);
}
