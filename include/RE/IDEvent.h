#pragma once

#include "RE/BSFixedString.h"
#include "RE/InputEvent.h"


namespace RE
{
	class IDEvent : public InputEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_IDEvent;


		virtual ~IDEvent();	 // 00

		// override
		virtual bool				 HasIDCode() const override;   // 01 - { return true; }
		virtual const BSFixedString& QUserEvent() const override;  // 02 - { return userEvent; }


		// members
		BSFixedString userEvent;  // 18
		UInt32		  idCode;	  // 20
		UInt32		  pad24;	  // 24
	};
	STATIC_ASSERT(sizeof(IDEvent) == 0x28);
}
