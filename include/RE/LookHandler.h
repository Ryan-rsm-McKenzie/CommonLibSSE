#pragma once

#include "skse64/GameRTTI.h"  // RTTI_LookHandler

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct LookHandler : public PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_LookHandler;


		virtual ~LookHandler();																				// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;											// 01
		virtual	void	ProcessThumbstick(ThumbstickEvent* a_event, MovementData* a_movementData) override;	// 02
		virtual	void	ProcessMouseMove(MouseMoveEvent* a_event, MovementData* a_movementData) override;	// 03
	};
	STATIC_ASSERT(sizeof(LookHandler) == 0x10);
}
