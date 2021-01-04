#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	struct JumpHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_JumpHandler;

		virtual ~JumpHandler();	 // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	static_assert(sizeof(JumpHandler) == 0x10);
}
