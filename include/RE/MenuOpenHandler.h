#pragma once

#include "RE/MenuEventHandler.h"  // MenuEventHandler

class KinectEvent;
namespace RE
{
	class ButtonEvent;
	class InputEvent;


	struct MenuOpenHandler : public MenuEventHandler
	{
	public:
		// override (MenuEventHandler)
		virtual bool	CanProcess(InputEvent* a_event) override;		// 1
		virtual bool	ProcessKinect(KinectEvent* a_event) override;	// 2
		virtual bool	ProcessButton(ButtonEvent* a_event) override;	// 5


		// members
		bool	unk10;	// 10 - Init'd 1
		UInt8	unk11;	// 11
		UInt16	unk12;	// 12
		UInt32	unk14;	// 14
	};
	STATIC_ASSERT(sizeof(MenuOpenHandler) == 0x18);
}
