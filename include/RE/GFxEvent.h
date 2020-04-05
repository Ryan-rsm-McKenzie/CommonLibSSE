#pragma once

#include "RE/GNewOverrideBase.h"
#include "RE/GStats.h"


namespace RE
{
	class GFxEvent : public GNewOverrideBase<GStatGroups::kGStat_Default_Mem>
	{
	public:
		enum class EventType : UInt32
		{
			kNone,

			// Informative events sent to the player.
			kMouseMove,
			kMouseDown,
			kMouseUp,
			kMouseWheel,
			kKeyDown,
			kKeyUp,
			kSceneResize,
			kSetFocus,
			kKillFocus,

			// Action events, to be handled by user.
			kDoShowMouse,
			kDoHideMouse,
			kDoSetMouseCursor,

			kCharEvent,
			kIMEEvent
		};


		GFxEvent(EventType a_eventType = EventType::kNone) :
			GNewOverrideBase<GStatGroups::kGStat_Default_Mem>(),
			type(a_eventType)
		{}


		// members
		EventType type;	 // 0
	};
	STATIC_ASSERT(sizeof(GFxEvent) == 0x4);


	class GFxMouseEvent : public GFxEvent
	{
	public:
		inline GFxMouseEvent() :
			GFxEvent(),
			x(0.0),
			y(0.0),
			scrollDelta(0.0),
			button(0),
			mouseIndex(0)
		{}


		inline GFxMouseEvent(EventType a_eventType, UInt32 a_button, float a_x, float a_y, float a_scrollDelta = 0.0, UInt32 a_mouseIndex = 0) :
			GFxEvent(a_eventType),
			x(a_x),
			y(a_y),
			scrollDelta(a_scrollDelta),
			button(a_button),
			mouseIndex(a_mouseIndex)
		{}


		inline GFxMouseEvent(EventType a_eventType, UInt32 a_mouseIndex) :
			GFxEvent(a_eventType),
			x(0.0),
			y(0.0),
			scrollDelta(0.0),
			button(0),
			mouseIndex(a_mouseIndex)
		{}


		// members
		float  x;			 // 04
		float  y;			 // 08
		float  scrollDelta;	 // 0C
		UInt32 button;		 // 10
		UInt32 mouseIndex;	 // 14
	};
	STATIC_ASSERT(sizeof(GFxMouseEvent) == 0x18);
}
