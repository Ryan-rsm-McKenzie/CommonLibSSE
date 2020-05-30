#pragma once

#include "RE/BSFixedString.h"
#include "RE/IDEvent.h"


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
	STATIC_ASSERT(sizeof(KinectEvent) == 0x30);
}
