#pragma once

namespace RE
{
	class NiQuaternion
	{
	public:
		// members
		float w;  // 00
		float x;  // 04
		float y;  // 08
		float z;  // 0C
	};
	static_assert(sizeof(NiQuaternion) == 0x10);
}
