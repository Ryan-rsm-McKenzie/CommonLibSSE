#pragma once


namespace RE
{
	class NiQuaternion
	{
	public:
		float w;  // 00
		float x;  // 04
		float y;  // 08
		float z;  // 0C
	};
	STATIC_ASSERT(sizeof(NiQuaternion) == 0x10);
}
