#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MenuOpenHandler

#include "RE/MenuEventHandler.h"  // MenuEventHandler


namespace RE
{
	struct MenuOpenHandler : public MenuEventHandler
	{
	public:
		inline static const void* RTTI = RTTI_MenuOpenHandler;


		virtual ~MenuOpenHandler();										// 00

		// override (MenuEventHandler)
		virtual bool	CanProcess(InputEvent* a_event) override;		// 01
		virtual bool	ProcessKinect(KinectEvent* a_event) override;	// 02
		virtual bool	ProcessButton(ButtonEvent* a_event) override;	// 05


		// members
		bool	unk10;	// 10
		UInt8	unk11;	// 11
		UInt16	unk12;	// 12
		UInt32	unk14;	// 14
	};
	STATIC_ASSERT(sizeof(MenuOpenHandler) == 0x18);
}
