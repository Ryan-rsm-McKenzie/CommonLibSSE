#pragma once

#include "RE/B/BSInputDevice.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	struct BSGamepadEvent;

	class BSGamepadDevice :
		public BSInputDevice,                  // 00
		public BSTEventSource<BSGamepadEvent>  // 70
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSGamepadDevice;

		~BSGamepadDevice() override;  // 00

		// override (BSInputDevice)
		bool IsEnabled() const override;  // 07 - { return connected && userIndex != -1; }

		// add
		virtual void Unk_09() = 0;  // 09
		virtual void Unk_0A();      // 0A - { return; }
		virtual void Unk_0B();      // 0B - { return; }
		virtual void Unk_0C();      // 0C - { return 0; }
		virtual void Unk_0D();      // 0D
		virtual void Unk_0E();      // 0E - { return; }

		// members
		std::int32_t  userIndex;          // C8
		bool          connected;          // CC
		bool          listeningForInput;  // CD
		std::uint16_t padCE;              // CE
	};
	static_assert(sizeof(BSGamepadDevice) == 0xD0);
}
