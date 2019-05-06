#pragma once

#include <xmmintrin.h>  // __m128


namespace RE
{
	using hkQuadReal = __m128;
	STATIC_ASSERT(sizeof(hkQuadReal) == 0x10);


	class hkVector4Comparison
	{
	public:
		enum class Mask : UInt32
		{
			kNone = 0,

			kX = 1,
			kY = 2,
			kXY = 3,

			kZ = 4,
			kXZ = 5,
			kYZ = 6,
			kXYZ = 7,

			kW = 8,
			kXW = 9,
			kYW = 10,
			kXYW = 11,

			kZW = 12,
			kXZW = 13,
			kYZW = 14,
			kXYZW = 15
		};


		// members
		hkQuadReal mask;	// 00
	};
	STATIC_ASSERT(sizeof(hkVector4Comparison) == 0x10);
}
