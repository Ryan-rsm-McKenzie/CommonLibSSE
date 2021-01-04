#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	struct MenuOpenHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_MenuOpenHandler;

		virtual ~MenuOpenHandler();	 // 00

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;		// 01
		virtual bool ProcessKinect(KinectEvent* a_event) override;	// 02
		virtual bool ProcessButton(ButtonEvent* a_event) override;	// 05

		// members
		bool		  unk10;  // 10
		std::uint8_t  unk11;  // 11
		std::uint16_t unk12;  // 12
		std::uint32_t unk14;  // 14
	};
	static_assert(sizeof(MenuOpenHandler) == 0x18);
}
