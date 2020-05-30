#pragma once

#include "RE/PlayerInputHandler.h"


namespace RE
{
	struct AutoMoveHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_AutoMoveHandler;


		virtual ~AutoMoveHandler();	 // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	STATIC_ASSERT(sizeof(AutoMoveHandler) == 0x10);
}
