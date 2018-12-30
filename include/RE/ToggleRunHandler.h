#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct ToggleRunHandler : public PlayerInputHandler
	{
	public:
		virtual ~ToggleRunHandler();																	// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 04
	};
	STATIC_ASSERT(sizeof(ToggleRunHandler) == 0x10);
}
