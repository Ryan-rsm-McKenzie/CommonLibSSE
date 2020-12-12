#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/A/AITimeStamp.h"


namespace RE
{
	struct MarkerUsedData
	{
	public:
		// members
		ActorHandle	  actorinMarker;  // 0
		std::uint32_t markerID;		  // 4
		AITimeStamp	  expiration;	  // 8
	};
	static_assert(sizeof(MarkerUsedData) == 0xC);
}
