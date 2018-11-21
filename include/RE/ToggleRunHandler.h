#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	class ToggleRunHandler : public PlayerInputHandler
	{
	public:
		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 1
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 4
	};
}
