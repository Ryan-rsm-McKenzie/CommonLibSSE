#pragma once

#include "RE/PlayerInputHandler.h"


namespace RE
{
	class HeldStateHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_HeldStateHandler;


		virtual ~HeldStateHandler();  // 00

		// add
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event);	 // 05
		virtual void SetHeldStateActive(bool a_flag);					 // 06 - { heldStateActive = a_flag; }


		// members
		bool   heldStateActive;		 // 10
		bool   triggerReleaseEvent;	 // 11
		UInt16 pad12;				 // 12
		UInt32 pad14;				 // 14
	};
	STATIC_ASSERT(sizeof(HeldStateHandler) == 0x18);
}
