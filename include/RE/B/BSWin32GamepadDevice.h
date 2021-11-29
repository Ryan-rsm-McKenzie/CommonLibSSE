#pragma once

#include "RE/B/BSPCGamepadDeviceDelegate.h"

namespace RE
{
	class BSWin32GamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32GamepadDevice;

		struct Keys
		{
			enum Key : std::uint32_t
			{
				kUp = 0x0001,
				kDown = 0x0002,
				kLeft = 0x0004,
				kRight = 0x0008,
				kStart = 0x0010,
				kBack = 0x0020,
				kLeftThumb = 0x0040,
				kRightThumb = 0x0080,
				kLeftShoulder = 0x0100,
				kRightShoulder = 0x0200,

				kA = 0x1000,
				kB = 0x2000,
				kX = 0x4000,
				kY = 0x8000,

				kLeftTrigger = 0x0009,
				kRightTrigger = 0x000A
			};
		};
		using Key = Keys::Key;

		~BSWin32GamepadDevice() override;  // 00

		// override (BSPCGamepadDeviceDelegate)
		void Initialize() override;           // 01
		void Process(float a_arg1) override;  // 02
		void Unk_03(void) override;           // 03 - { return; }
		void Reset() override;                // 08 - { std::memset(&unk0D8, 0, 0x50); }
		void Unk_09(void) override;           // 09 - { return; }

		// members
		std::uint32_t unk0D8;     // 0D8
		std::uint8_t  unk0DC;     // 0DC
		std::uint8_t  curState;   // 0DD
		std::uint16_t unk0DE;     // 0DE
		std::uint64_t unk0E0;     // 0E0
		std::uint64_t unk0E8;     // 0E8
		float         curLX;      // 0F0
		float         curLY;      // 0F4
		float         curRX;      // 0F8
		float         curRY;      // 0FC
		std::uint32_t unk100;     // 100
		std::uint8_t  unk104;     // 104
		std::uint8_t  prevState;  // 105
		std::uint16_t unk106;     // 106
		std::uint64_t unk108;     // 108
		std::uint64_t unk110;     // 110
		float         prevLX;     // 118
		float         prevLY;     // 11C
		float         prevRX;     // 120
		float         prevRY;     // 124
	};
	static_assert(sizeof(BSWin32GamepadDevice) == 0x128);
}
