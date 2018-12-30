#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct LookHandler : public PlayerInputHandler
	{
	public:
		virtual ~LookHandler();																					// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;												// 01
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 02
		virtual	void	ProcessMouseMove(MouseMoveEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 03
	};
	STATIC_ASSERT(sizeof(LookHandler) == 0x10);
}
