#pragma once

#include "RE/H/hkpShape.h"
#include "RE/H/hkpShapeRayCastCollectorOutput.h"

namespace RE
{
	struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
	{
	public:
		enum
		{
			kMaxHierarchyDepth = 8
		};

		constexpr void ChangeLevel(std::int32_t a_delta) noexcept
		{
			assert(shapeKeyIndex + a_delta < kMaxHierarchyDepth);
			shapeKeyIndex += a_delta;
		}

		constexpr void SetKey(hkpShapeKey a_key) noexcept { shapeKeys[shapeKeyIndex] = a_key; }

		constexpr void Reset() noexcept
		{
			hkpShapeRayCastCollectorOutput::Reset();
			shapeKeys[0] = HK_INVALID_SHAPE_KEY;
			shapeKeyIndex = 0;
		}

		// members
		hkpShapeKey	 shapeKeys[kMaxHierarchyDepth]{ HK_INVALID_SHAPE_KEY };	 // 20
		std::int32_t shapeKeyIndex{ 0 };									 // 40
	};
	static_assert(sizeof(hkpShapeRayCastOutput) == 0x50);
}
