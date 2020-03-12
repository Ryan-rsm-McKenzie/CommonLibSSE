#pragma once

#include "RE/HeldStateHandler.h"


namespace RE
{
	struct ActivateHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActivateHandler;


		virtual ~ActivateHandler();	 // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04


		// members
		UInt8  unk18;	  // 18
		UInt8  unk19;	  // 19
		UInt8  unk1A;	  // 1A - isGrabbing?
		bool   disabled;  // 1B
		UInt32 unk1C;	  // 1C
	};
	STATIC_ASSERT(sizeof(ActivateHandler) == 0x20);
}
