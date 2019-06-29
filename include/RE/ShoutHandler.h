#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ShoutHandler

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct ShoutHandler : public PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_ShoutHandler;


		virtual ~ShoutHandler();																	// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ShoutHandler) == 0x20);
}
