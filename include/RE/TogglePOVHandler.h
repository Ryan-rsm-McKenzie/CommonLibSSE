#pragma once

#include "RE/HeldStateHandler.h"


namespace RE
{
	struct TogglePOVHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_TogglePOVHandler;


		virtual ~TogglePOVHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04


		// members
		UInt64 unk18;  // 18
	};
	STATIC_ASSERT(sizeof(TogglePOVHandler) == 0x20);
}
