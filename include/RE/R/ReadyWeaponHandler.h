#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	struct ReadyWeaponHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ReadyWeaponHandler;

		virtual ~ReadyWeaponHandler();	// 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
	};
	static_assert(sizeof(ReadyWeaponHandler) == 0x10);
}
