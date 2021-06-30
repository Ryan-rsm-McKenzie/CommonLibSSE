#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IDEvent.h"

namespace RE
{
	class KinectEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_KinectEvent;

		~KinectEvent() override;  // 00

		// members
		BSFixedString heard;  // 28
	};
	static_assert(sizeof(KinectEvent) == 0x30);
}
