#pragma once

#include "skse64/GameRTTI.h"  // RTTI_HUDMeter

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/HUDObject.h"  // HUDObject


namespace RE
{
	class HUDMeter : public HUDObject
	{
	public:
		inline static const void* RTTI = RTTI_HUDMeter;


		virtual ~HUDMeter();					// 00

		// override (HUDObject)
		virtual void	Update(void) override;	// 01
		virtual void	Unk_02(void) override;	// 02 - { return 0; }

		// add
		virtual float	GetFillPct();			// 05 - { return 100.0; }


		// members
		BSFixedString	setPctName;			// 28
		BSFixedString	setBlinkingName;	// 30
		BSFixedString	fadeOutName;		// 38
		float			fillPct;			// 40
		UInt32			pad44;				// 44
	};
	STATIC_ASSERT(sizeof(HUDMeter) == 0x48);
}
