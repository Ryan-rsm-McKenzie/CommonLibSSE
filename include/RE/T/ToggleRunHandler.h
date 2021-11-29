#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	struct ToggleRunHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ToggleRunHandler;

		~ToggleRunHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                  // 01
		void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 04
	};
	static_assert(sizeof(ToggleRunHandler) == 0x10);
}
