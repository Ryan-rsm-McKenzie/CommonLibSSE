#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TogglePOVHandler

#include "RE/HeldStateHandler.h"  // HeldStateHandler


namespace RE
{
	struct TogglePOVHandler : public HeldStateHandler
	{
	public:
		inline static const void* RTTI = RTTI_TogglePOVHandler;


		virtual ~TogglePOVHandler();																// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(TogglePOVHandler) == 0x20);
}
