#pragma once

#include "RE/H/hkVector4.h"
#include "RE/H/hkpCollisionInput.h"

namespace RE
{
	struct hkpCollisionAgentConfig;

	struct hkpLinearCastCollisionInput : public hkpCollisionInput
	{
	public:
		// members
		hkVector4                path;                 // 60
		float                    maxExtraPenetration;  // 70
		float                    cachedPathLength;     // 74
		hkpCollisionAgentConfig* config;               // 78
	};
	static_assert(sizeof(hkpLinearCastCollisionInput) == 0x80);
}
