#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	struct SprintHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_SprintHandler;

		virtual ~SprintHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	static_assert(sizeof(SprintHandler) == 0x18);
}
