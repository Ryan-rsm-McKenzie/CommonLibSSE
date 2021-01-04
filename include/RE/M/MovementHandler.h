#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	struct MovementHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementHandler;

		virtual ~MovementHandler();	 // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;											// 01
		virtual void ProcessThumbstick(ThumbstickEvent* a_event, PlayerControlsData* a_data) override;	// 02
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;			// 04
	};
	static_assert(sizeof(MovementHandler) == 0x10);
}
