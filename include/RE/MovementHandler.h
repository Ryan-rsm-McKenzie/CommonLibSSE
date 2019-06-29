#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MovementHandler

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct MovementHandler : public PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_MovementHandler;


		virtual ~MovementHandler();																			// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;											// 01
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, MovementData* a_movementData) override;	// 02
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;			// 04
	};
	STATIC_ASSERT(sizeof(MovementHandler) == 0x10);
}
