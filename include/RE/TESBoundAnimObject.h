#pragma once

#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		virtual ~TESBoundAnimObject();			// 00

		// override (TESBoundObject)
		virtual bool CanAnimate(void) override;	// 3C - { return true; }
	};
	STATIC_ASSERT(sizeof(TESBoundAnimObject) == 0x30);
}
