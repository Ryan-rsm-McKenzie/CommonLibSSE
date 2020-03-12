#pragma once

#include "RE/PlayerInputHandler.h"


namespace RE
{
	struct ShoutHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShoutHandler;


		virtual ~ShoutHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04


		// members
		UInt64 unk10;  // 10
		UInt64 unk18;  // 18
	};
	STATIC_ASSERT(sizeof(ShoutHandler) == 0x20);
}
