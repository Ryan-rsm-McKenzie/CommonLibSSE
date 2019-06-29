#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ToggleRunHandler

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct ToggleRunHandler : public PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_ToggleRunHandler;


		virtual ~ToggleRunHandler();																// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04
	};
	STATIC_ASSERT(sizeof(ToggleRunHandler) == 0x10);
}
