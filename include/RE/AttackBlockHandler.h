#pragma once

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	class AttackBlockHandler : public PlayerInputHandler
	{
	public:
		AttackBlockHandler();
		virtual ~AttackBlockHandler();																	// 0

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 1
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 4

		// add
		virtual void	Unk_05(void);																	// 5
		virtual void	Unk_06(void);																	// 6
	};
}
