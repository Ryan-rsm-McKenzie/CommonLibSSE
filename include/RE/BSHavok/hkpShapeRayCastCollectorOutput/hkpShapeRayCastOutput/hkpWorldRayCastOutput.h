#pragma once

#include "RE/BSHavok/hkpShapeRayCastCollectorOutput/hkpShapeRayCastOutput/hkpShapeRayCastOutput.h"


namespace RE
{
	class hkpCollidable;


	struct hkpWorldRayCastOutput : public hkpShapeRayCastOutput
	{
	public:
		[[nodiscard]] constexpr bool HasHit() const noexcept { return rootCollidable != nullptr; }

		constexpr void Reset() noexcept
		{
			hkpShapeRayCastOutput::Reset();
			rootCollidable = nullptr;
		}


		// members
		const hkpCollidable* rootCollidable{ nullptr };	 // 50
	};
	static_assert(sizeof(hkpWorldRayCastOutput) == 0x60);
}
