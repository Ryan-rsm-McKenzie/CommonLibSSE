#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/Events/InputEvent/IDEvent/IDEvent.h"


namespace RE
{
	class KinectEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_KinectEvent;


		virtual ~KinectEvent();	 // 00


		// members
		BSFixedString heard;  // 28
	};
	static_assert(sizeof(KinectEvent) == 0x30);
}
