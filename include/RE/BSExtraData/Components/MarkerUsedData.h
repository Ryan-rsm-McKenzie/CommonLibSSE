#pragma once

#include "RE/AITimeStamp.h"
#include "RE/BSPointerHandle.h"


namespace RE
{
	struct MarkerUsedData
	{
	public:
		// members
		ActorHandle actorinMarker;	// 0
		UInt32		markerID;		// 4
		AITimeStamp expiration;		// 8
	};
	STATIC_ASSERT(sizeof(MarkerUsedData) == 0xC);
}
