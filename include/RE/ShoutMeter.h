#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ShoutMeter

#include "RE/HUDMeter.h"  // HUDMeter


namespace RE
{
	class ShoutMeter : public HUDMeter
	{
	public:
		inline static const void* RTTI = RTTI_ShoutMeter;


		virtual ~ShoutMeter();					// 00

		// override (HUDMeter)
		virtual void	Unk_02(void) override;	// 02
		virtual float	GetFillPct() override;	// 05


		// members
		float	cooldown;	// 48 - in seconds
		UInt32	pad4C;		// 4C
	};
	STATIC_ASSERT(sizeof(ShoutMeter) == 0x50);
}
