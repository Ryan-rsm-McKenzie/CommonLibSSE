#pragma once

#include "RE/BSFixedString.h"
#include "RE/HUDObject.h"


namespace RE
{
	class HUDMeter : public HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDMeter;


		HUDMeter(GFxMovieView* a_view);
		virtual ~HUDMeter() = default;	// 00

		// override (HUDObject)
		virtual void Update() override;								 // 01
		virtual bool ProcessMessage(UIMessage* a_message) override;	 // 02 - { return false; }

		// add
		virtual float GetFillPct();	 // 05 - { return 100.0; }

		void SetFillPct(bool a_forceUpdate);


		// members
		BSFixedString setPctName;		// 28
		BSFixedString setBlinkingName;	// 30
		BSFixedString fadeOutName;		// 38
		float		  fillPct;			// 40
		UInt32		  pad44;			// 44
	};
	STATIC_ASSERT(sizeof(HUDMeter) == 0x48);
}
