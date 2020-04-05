#pragma once

#include "RE/InputEvent.h"


namespace RE
{
	class DeviceConnectEvent : public InputEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_DeviceConnectEvent;


		virtual ~DeviceConnectEvent();	// 00


		// members
		bool   connected;  // 18
		UInt8  pad19;	   // 19
		UInt16 pad1A;	   // 1A
		UInt32 pad1C;	   // 1C
	};
	STATIC_ASSERT(sizeof(DeviceConnectEvent) == 0x20);
}
