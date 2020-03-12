#pragma once


namespace RE
{
	class NiFrustum
	{
	public:
		float fLeft;	// 00
		float fRight;	// 04
		float fTop;		// 08
		float fBottom;	// 0C
		float fNear;	// 10
		float fFar;		// 14
		bool  bOrtho;	// 18
	};
	STATIC_ASSERT(sizeof(NiFrustum) == 0x1C);
}
