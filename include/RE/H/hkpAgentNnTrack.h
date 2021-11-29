#pragma once

#include "RE/H/hkArray.h"

namespace RE
{
	struct hkpAgentNnSector;

	enum class hkpAgentNnTrackType
	{
		kInvalid = 0,
		kMidPhase = 1,
		kNarrowPhase = 2
	};

	struct hkpAgentNnTrack
	{
	public:
		// members
		std::uint16_t                                       bytesUsedInLastSector;  // 00
		stl::enumeration<hkpAgentNnTrackType, std::uint8_t> nnTrackType;            // 02
		std::uint8_t                                        padding;                // 03
		std::uint32_t                                       pad04;                  // 04
		hkInplaceArray<hkpAgentNnSector*, 1>                sectors;                // 08
	};
	static_assert(sizeof(hkpAgentNnTrack) == 0x20);
}
