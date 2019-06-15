#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SneakHandler

#include "RE/PlayerInputHandler.h"  // PlayerInputHandler


namespace RE
{
	struct SneakHandler : public PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_SneakHandler;


		virtual ~SneakHandler();																		// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;										// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControls::Data024* a_arg2) override;	// 04
	};
	STATIC_ASSERT(sizeof(SneakHandler) == 0x10);
}
