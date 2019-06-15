#pragma once

#undef near
#undef far


namespace RE
{
	class NiFrustum
	{
	public:
		float	left;	// 00
		float	right;	// 04
		float	top;	// 08
		float	bottom;	// 0C
		float	near;	// 10
		float	far;	// 14
		bool	ortho;	// 18
	};
	STATIC_ASSERT(sizeof(NiFrustum) == 0x1C);
}
