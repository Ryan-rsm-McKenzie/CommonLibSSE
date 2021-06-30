#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/H/HUDObject.h"

namespace RE
{
	class HUDMeter : public HUDObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDMeter;

		HUDMeter(GFxMovieView* a_view);
		~HUDMeter() override = default;  // 00

		// override (HUDObject)
		void Update() override;                              // 01
		bool ProcessMessage(UIMessage* a_message) override;  // 02 - { return false; }

		// add
		virtual float GetFillPct();  // 05 - { return 100.0; }

		void SetFillPct(bool a_forceUpdate);

		// members
		BSFixedString setPctName;       // 28
		BSFixedString setBlinkingName;  // 30
		BSFixedString fadeOutName;      // 38
		float         fillPct;          // 40
		std::uint32_t pad44;            // 44
	};
	static_assert(sizeof(HUDMeter) == 0x48);
}
