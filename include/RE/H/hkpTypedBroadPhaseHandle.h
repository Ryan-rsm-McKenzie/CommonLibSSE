#pragma once

#include "RE/H/hkpBroadPhaseHandle.h"

namespace RE
{
	class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
	{
	public:
		enum
		{
			kInvalidOffset = 127
		};

		std::int8_t   type;                 // 4
		std::int8_t   ownerOffset;          // 5
		std::int8_t   objectQualityType;    // 6
		std::int8_t   pad7;                 // 7
		std::uint32_t collisionFilterInfo;  // 8
	};
	static_assert(sizeof(hkpTypedBroadPhaseHandle) == 0xC);
}
