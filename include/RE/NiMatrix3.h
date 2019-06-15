#pragma once


namespace RE
{
	class NiMatrix3
	{
	public:
		float entry[3][3];	// 00
	};
	STATIC_ASSERT(sizeof(NiMatrix3) == 0x24);
}
