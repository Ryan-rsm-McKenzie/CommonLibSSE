#pragma once

#include "RE/BSHavok/hkpShapeRayCastCollectorOutput/hkpShapeRayCastOutput/hkpShapeRayCastOutput.h"


namespace RE
{
	class hkpCollidable;


	struct hkpWorldRayCastOutput : public hkpShapeRayCastOutput
	{
	public:
		[[nodiscard]] constexpr bool hasHit() const noexcept { return rootCollidable != nullptr; }

		constexpr void reset() noexcept
		{
			hkpShapeRayCastOutput::reset();
			rootCollidable = nullptr;
		}


		// members
		const hkpCollidable* rootCollidable{ nullptr };	 // 50
	};
	static_assert(sizeof(hkpWorldRayCastOutput) == 0x60);
}
