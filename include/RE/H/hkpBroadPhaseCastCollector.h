#pragma once

namespace RE
{
	class hkpBroadPhaseHandle;

	class hkpBroadPhaseCastCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpBroadPhaseCastCollector;

		virtual ~hkpBroadPhaseCastCollector() = default;  // 00

		// add
		virtual float AddBroadPhaseHandle(const hkpBroadPhaseHandle* a_broadphaseHandle, std::int32_t a_castIndex) = 0;  // 01
	};
	static_assert(sizeof(hkpBroadPhaseCastCollector) == 0x8);
}
