#pragma once

#include "RE/PlayerControls.h"  // PlayerControls::Data024
#include "RE/PlayerInputHandler.h"

class InputEvent;
class ThumbstickEvent;



namespace RE
{
	class ButtonEvent;


	class MovementHandler : public PlayerInputHandler
	{
		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;												// 1
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 2
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;			// 4
	};
}
