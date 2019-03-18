#pragma once

#include "RE/GNewOverrideBase.h"  // GNewOverrideBase
#include "RE/GStats.h"  // GStatGroups


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


		// members
		EventType type;	// 0
	};
	STATIC_ASSERT(sizeof(GFxEvent) == 0x4);
}
