#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct MovementHandler : public PlayerInputHandler
	{
	public:
		virtual ~MovementHandler();																				// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;												// 01
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 02
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;			// 04
	};
	STATIC_ASSERT(sizeof(MovementHandler) == 0x10);
}
