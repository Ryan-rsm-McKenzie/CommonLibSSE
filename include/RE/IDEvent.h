#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/InputEvent.h"  // InputEvent


namespace RE
{
	class IDEvent : public InputEvent
	{
	public:
		virtual	~IDEvent();												// 0

		// override
		virtual bool					IsIDEvent() const override;		// 1 - { return true; }
		virtual const BSFixedString&	GetControlID() const override;	// 2 - { return controlID; }


		// members
		BSFixedString	controlID;	// 18
	};
}
