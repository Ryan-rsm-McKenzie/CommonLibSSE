#pragma once

#include <xmmintrin.h>  // __m128


namespace RE
{
	using hkQuadReal = __m128;
	STATIC_ASSERT(sizeof(hkQuadReal) == 0x10);
}
