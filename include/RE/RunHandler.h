#pragma once

#include "RE/HeldStateHandler.h"


namespace RE
{
	struct RunHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_RunHandler;


		virtual ~RunHandler();	// 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	STATIC_ASSERT(sizeof(RunHandler) == 0x18);
}
