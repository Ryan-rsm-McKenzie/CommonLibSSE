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


		HUDMeter(GFxMovieView* a_view);
		virtual ~HUDMeter() = default;									// 00

		// override (HUDObject)
		virtual void	Update() override;								// 01
		virtual bool	ProcessMessage(UIMessage* a_message) override;	// 02 - { return false; }

		// add
		virtual float	GetFillPct();									// 05 - { return 100.0; }

		void SetFillPct(bool a_forceUpdate);


		// members
		BSFixedString	_setPctName;		// 28
		BSFixedString	_setBlinkingName;	// 30
		BSFixedString	_fadeOutName;		// 38
		float			_fillPct;			// 40
		UInt32			_pad44;				// 44
	};
	STATIC_ASSERT(sizeof(HUDMeter) == 0x48);
}
