#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SprintHandler

#include "RE/HeldStateHandler.h"  // HeldStateHandler


namespace RE
{
	struct SprintHandler : public HeldStateHandler
	{
	public:
		inline static const void* RTTI = RTTI_SprintHandler;


		virtual ~SprintHandler();																	// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04
	};
	STATIC_ASSERT(sizeof(SprintHandler) == 0x18);
}
