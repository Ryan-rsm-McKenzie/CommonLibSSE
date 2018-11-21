#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	class LookHandler : public PlayerInputHandler
	{
	public:
		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;												// 1
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 2
		virtual	void	ProcessMouseMove(MouseMoveEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 3
	};
}
