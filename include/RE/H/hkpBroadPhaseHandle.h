#pragma once

namespace RE
{
	class hkpBroadPhaseHandle
	{
	public:
		std::uint32_t id;  // 0
	};
	static_assert(sizeof(hkpBroadPhaseHandle) == 0x4);
}
