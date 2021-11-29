#pragma once

#include "RE/C/CollisionLayers.h"

namespace RE
{
	enum class BIPED_PART
	{
		kOther = 0,
		kHead = 1,
		kBody = 2,
		kSpine1 = 3,
		kSpine2 = 4,
		kLUpperArm = 5,
		kLForearm = 6,
		kLHand = 7,
		kLThigh = 8,
		kLCalf = 9,
		kLFoot = 10,
		kRUpperArm = 11,
		kRForearm = 12,
		kRHand = 13,
		kRThigh = 14,
		kRCalf = 15,
		kRFoot = 16,
		kTail = 17,
		kShield = 18,
		kQuiver = 19,
		kWeapon = 20,
		kPonyTail = 21,
		kWing = 22,
		kPack = 23,
		kChain = 24,
		kAddonHead = 25,
		kAddonChest = 26,
		kAddonLeg = 27,
		kAddonArm = 28
	};

	class CFilter
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kNoCollision = 1 << 14,

			kLayerMask = 0x7F  // COL_LAYER
		};

		// members
		stl::enumeration<Flag, std::uint32_t> flags;  // 0
	};
	static_assert(sizeof(CFilter) == 0x4);
}
