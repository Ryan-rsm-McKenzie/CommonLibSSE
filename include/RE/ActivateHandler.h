#pragma once

#include "RE/HeldStateHandler.h"  // HeldStateHandler
#include "RE/PlayerControls.h"  // PlayerControls::Data024

class InputEvent;


namespace RE
{
	class ButtonEvent;


	class ActivateHandler : public HeldStateHandler
	{
	public:
		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 04

		// add
		virtual void	Unk_05(void);																	// 05
		virtual void	Unk_06(void);																	// 06


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ActivateHandler) == 0x20);
}
