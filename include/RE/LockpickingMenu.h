#pragma once

#include <string_view>

#include "RE/BSSoundHandle.h"
#include "RE/BSTEvent.h"
#include "RE/IMenu.h"
#include "RE/MenuEventHandler.h"


namespace RE
{
	class MenuOpenCloseEvent;


	// menuDepth = 3
	// flags = kPausesGame | kDisablePauseMenu | kRequiresUpdate
	// context = kLockpicking
	class LockpickingMenu :
		public IMenu,							 // 00
		public MenuEventHandler,				 // 30
		public BSTEventSink<MenuOpenCloseEvent>	 // 40
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_LockpickingMenu;
		constexpr static std::string_view MENU_NAME = "Lockpicking Menu";


		virtual ~LockpickingMenu();	 // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool ProcessMouseMove(MouseMoveEvent* a_event) override;	// 04
		virtual bool ProcessButton(ButtonEvent* a_event) override;			// 05

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01


		// members
		void*		  unk048;  // 048
		void*		  unk050;  // 050
		float		  unk058;  // 058
		UInt32		  unk05C;  // 05C
		UInt64		  unk060;  // 060
		float		  unk068;  // 068
		UInt32		  unk06C;  // 06C
		UInt64		  unk070;  // 070
		UInt32		  unk078;  // 078
		UInt32		  unk07C;  // 07C
		UInt32		  unk080;  // 080
		UInt32		  unk084;  // 084
		UInt64		  unk088;  // 088
		UInt64		  unk090;  // 090
		UInt64		  unk098;  // 098
		UInt64		  unk0A0;  // 0A0
		UInt64		  unk0A8;  // 0A8
		UInt64		  unk0B0;  // 0B0
		UInt64		  unk0B8;  // 0B8
		UInt64		  unk0C0;  // 0C0
		float		  unk0C8;  // 0C8
		UInt32		  unk0CC;  // 0CC
		UInt64		  unk0D0;  // 0D0
		float		  unk0D8;  // 0D8
		UInt32		  unk0DC;  // 0DC
		UInt32		  unk0E0;  // 0E0
		UInt32		  unk0E4;  // 0E4
		UInt32		  unk0E8;  // 0E8
		BSSoundHandle unk0EC;  // 0EC
		UInt32		  unk0F8;  // 0F8
		UInt32		  unk0FC;  // 0FC
		UInt32		  unk100;  // 100
		UInt32		  unk104;  // 104
		UInt16		  unk108;  // 108
		UInt8		  unk10A;  // 10A
		UInt8		  unk10B;  // 10B
		UInt8		  unk10C;  // 10C
		UInt8		  unk10D;  // 10D
		UInt8		  unk10E;  // 10E
		UInt8		  pad10F;  // 10F
	};
	STATIC_ASSERT(sizeof(LockpickingMenu) == 0x110);
}
