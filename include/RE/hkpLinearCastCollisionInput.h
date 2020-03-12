#pragma once

#include "RE/hkVector4.h"
#include "RE/hkpCollisionInput.h"


namespace RE
{
	struct hkpCollisionAgentConfig;


	struct hkpLinearCastCollisionInput : public hkpCollisionInput
	{
	public:
		// members
		hkVector4				 path;				   // 60
		float					 maxExtraPenetration;  // 70
		float					 cachedPathLength;	   // 74
		hkpCollisionAgentConfig* config;			   // 78
	};
	STATIC_ASSERT(sizeof(hkpLinearCastCollisionInput) == 0x80);
}
