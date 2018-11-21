#pragma once

#include "RE/PlayerControls.h"  // PlayerControls::Data024

class InputEvent;
class MouseMoveEvent;
class ThumbstickEvent;


namespace RE
{
	class ButtonEvent;


	class PlayerInputHandler
	{
	public:
		PlayerInputHandler();
		virtual ~PlayerInputHandler();																	// 0

		virtual	bool	CanProcess(InputEvent* a_event) = 0;											// 1
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, PlayerControls::Data024* a_arg2);	// 2
		virtual	void	ProcessMouseMove(MouseMoveEvent* a_event, PlayerControls::Data024* a_arg2);		// 3
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2);			// 4

		bool			IsEnabled() const;
		void			Enable(bool a_enable = true);

		// members
		UInt32			enabled;	// 08
	};
}
