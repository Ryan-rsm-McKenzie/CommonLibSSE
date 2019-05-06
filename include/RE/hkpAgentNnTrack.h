#pragma once

#include "RE/hkArray.h"  // hkInplaceArray


namespace RE
{
	struct hkpAgentNnSector;


	enum class hkpAgentNnTrackType : UInt8
	{
		kInvalid = 0,
		kMidPhase = 1,
		kNarrowPhase = 2
	};


	struct hkpAgentNnTrack
	{
		UInt16									bytesUsedInLastSector;	// 00
		hkpAgentNnTrackType						nnTrackType;			// 02
		UInt8									padding;				// 03
		UInt32									pad04;					// 04
		hkInplaceArray<hkpAgentNnSector*, 1>	sectors;				// 08
	};
	STATIC_ASSERT(sizeof(hkpAgentNnTrack) == 0x20);
}
