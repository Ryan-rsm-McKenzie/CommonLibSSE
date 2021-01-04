#pragma once

#include "RE/B/BSVirtualKeyboardDevice.h"

namespace RE
{
	class BSWin32VirtualKeyboardDevice : public BSVirtualKeyboardDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32VirtualKeyboardDevice;

		virtual ~BSWin32VirtualKeyboardDevice();  // 00

		// override (BSVirtualKeyboardDevice)
		virtual void Initialize() override;			  // 01 - { return; }
		virtual void Process(float a_arg1) override;  // 02 - { return; }
		virtual void Unk_03(void) override;			  // 03 - { return; }
		virtual void Reset() override;				  // 08 - { return; }
		virtual void Unk_0B(void) override;			  // 0B - { return; }
		virtual void Unk_0C(void) override;			  // 0C - { return; }
		virtual void Unk_0D(void) override;			  // 0D - { return; }
	};
	static_assert(sizeof(BSWin32VirtualKeyboardDevice) == 0x70);
}
