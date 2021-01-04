#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSMouseDevice.h"

namespace RE
{
	class BSWin32MouseDevice : public BSMouseDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32MouseDevice;

		struct Keys
		{
			enum Key : std::uint32_t
			{
				kLeftButton,
				kRightButton,
				kMiddleButton,
				kButton3,
				kButton4,
				kButton5,
				kButton6,
				kButton7,
				kWheelUp,
				kWheelDown
			};
		};
		using Key = Keys::Key;

		virtual ~BSWin32MouseDevice();	// 00

		// override (BSMouseDevice)
		virtual void Initialize() override;			  // 01
		virtual void Process(float a_arg1) override;  // 02
		virtual void Unk_03(void) override;			  // 03
		virtual void Reset() override;				  // 08
		virtual void Unk_09(void) override;			  // 09

		// members
		std::uint64_t	   unk78;  // 78
		std::uint64_t	   unk80;  // 80
		std::uint64_t	   unk88;  // 88
		std::uint64_t	   unk90;  // 90
		std::uint64_t	   unk98;  // 98
		std::uint64_t	   unkA0;  // A0
		std::uint32_t	   unkA8;  // A8
		mutable BSSpinLock unkAC;  // AC
		std::uint32_t	   unkB4;  // B4
	};
	static_assert(sizeof(BSWin32MouseDevice) == 0xB8);
}
