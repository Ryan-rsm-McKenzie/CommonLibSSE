#pragma once

#include "RE/B/BSInputDevice.h"

namespace RE
{
	class BSMouseDevice : public BSInputDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMouseDevice;

		~BSMouseDevice() override;  // 00

		// add
		virtual void Unk_09(void);  // 09 - { return; }

		// members
		bool          backgroundMouse;  // 70
		std::uint8_t  unk71;            // 71
		std::uint16_t unk72;            // 72
		std::uint32_t unk74;            // 74
	};
	static_assert(sizeof(BSMouseDevice) == 0x78);
}
