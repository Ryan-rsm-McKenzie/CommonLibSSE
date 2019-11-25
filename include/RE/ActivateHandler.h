#pragma once

#include "RE/HeldStateHandler.h"


namespace RE
{
	struct ActivateHandler : public HeldStateHandler
	{
	public:
		inline static const void* RTTI = RTTI_ActivateHandler;


		virtual ~ActivateHandler();																	// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ActivateHandler) == 0x20);
}
