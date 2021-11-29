#pragma once

#include "RE/I/InputEvent.h"

namespace RE
{
	class DeviceConnectEvent : public InputEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_DeviceConnectEvent;

		~DeviceConnectEvent() override;  // 00

		// members
		bool          connected;  // 18
		std::uint8_t  pad19;      // 19
		std::uint16_t pad1A;      // 1A
		std::uint32_t pad1C;      // 1C
	};
	static_assert(sizeof(DeviceConnectEvent) == 0x20);
}
