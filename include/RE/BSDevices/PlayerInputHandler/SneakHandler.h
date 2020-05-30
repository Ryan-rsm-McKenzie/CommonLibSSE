#pragma once

#include "RE/PlayerInputHandler.h"


namespace RE
{
	struct SneakHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_SneakHandler;


		virtual ~SneakHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	STATIC_ASSERT(sizeof(SneakHandler) == 0x10);
}
