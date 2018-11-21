#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	class ShoutHandler : public PlayerInputHandler
	{
	public:
		ShoutHandler();
		virtual ~ShoutHandler();																		// 0

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 1
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 4
	};
}
