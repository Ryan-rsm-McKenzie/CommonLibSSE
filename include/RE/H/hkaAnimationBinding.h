#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStringPtr.h"
#include "RE/H/hkaAnimation.h"

namespace RE
{
	class hkaAnimationBinding : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaAnimationBinding;

		enum class BlendHint
		{
			kNormal = 0,
			kAdditive
		};

		// members
		hkStringPtr                               originalSkeletonName;          // 10
		hkRefPtr<hkaAnimation>                    animation;                     // 18
		hkArray<std::int16_t>                     transformTrackToBoneIndices;   // 20
		hkArray<std::int16_t>                     floatTrackToFloatSlotIndices;  // 30
		stl::enumeration<BlendHint, std::uint8_t> blendHint;                     // 40
		char                                      pad41[7];                      // 41
	};
	static_assert(sizeof(hkaAnimationBinding) == 0x48);
}
