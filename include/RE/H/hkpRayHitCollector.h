#pragma once

namespace RE
{
	class hkpRayHitCollector
	{
	public:
		std::uintptr_t virtualFunctionTable{ 0 };	 // 0
		float		   earlyOutHitFraction{ 1.0f };	 // 8
		std::uint32_t  padC;						 // C
	};
	static_assert(sizeof(hkpRayHitCollector) == 0x10);
}
