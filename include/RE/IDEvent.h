#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IDEvent

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/InputEvent.h"  // InputEvent


namespace RE
{
	class IDEvent : public InputEvent
	{
	public:
		inline static const void* RTTI = RTTI_IDEvent;


		virtual	~IDEvent();												// 00

		// override
		virtual bool					IsIDEvent() const override;		// 01 - { return true; }
		virtual const BSFixedString&	GetControlID() const override;	// 02 - { return controlID; }


		// members
		BSFixedString	controlID;	// 18
		UInt32			keyMask;	// 20
		UInt32			pad24;		// 24
	};
	STATIC_ASSERT(sizeof(IDEvent) == 0x28);
}
