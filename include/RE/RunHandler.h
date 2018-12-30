#pragma once

#include "RE/HeldStateHandler.h"  // HeldStateHandler


namespace RE
{
	struct RunHandler : public HeldStateHandler
	{
	public:
		virtual ~RunHandler();																			// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 04


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(RunHandler) == 0x18);
}
