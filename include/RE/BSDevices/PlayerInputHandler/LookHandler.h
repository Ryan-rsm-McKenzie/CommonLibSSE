#pragma once

#include "RE/PlayerInputHandler.h"


namespace RE
{
	struct LookHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_LookHandler;


		virtual ~LookHandler();	 // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;											// 01
		virtual void ProcessThumbstick(ThumbstickEvent* a_event, PlayerControlsData* a_data) override;	// 02
		virtual void ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data) override;	// 03
	};
	STATIC_ASSERT(sizeof(LookHandler) == 0x10);
}
