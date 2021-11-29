#pragma once

#include "RE/H/HUDMeter.h"

namespace RE
{
	class ShoutMeter : public HUDMeter
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShoutMeter;

		~ShoutMeter() override;  // 00

		// override (HUDMeter)
		bool  ProcessMessage(UIMessage* a_message) override;  // 02
		float GetFillPct() override;                          // 05

		// members
		float         cooldown;  // 48 - in seconds
		std::uint32_t unk4C;     // 4C
	};
	static_assert(sizeof(ShoutMeter) == 0x50);
}
