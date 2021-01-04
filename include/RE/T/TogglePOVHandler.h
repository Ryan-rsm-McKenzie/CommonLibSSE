#pragma once

#include "RE/H/HeldStateHandler.h"

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
		bool		  pressRegistered;	// 18
		std::uint8_t  pad19;			// 19
		std::uint16_t pad1A;			// 1A
		std::uint32_t pad1C;			// 1C
	};
	static_assert(sizeof(TogglePOVHandler) == 0x20);
}
