#pragma once

#include "RE/HeldStateHandler.h"  // HeldStateHandler
#include "RE/PlayerControls.h"  // PlayerControls::Data024

class InputEvent;


namespace RE
{
	class ButtonEvent;


	struct ActivateHandler : public HeldStateHandler
	{
	public:
		virtual ~ActivateHandler();																		// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 04


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ActivateHandler) == 0x20);
}
