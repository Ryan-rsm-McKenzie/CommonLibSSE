#pragma once

#include <string_view>

#include "RE/IMenu.h"
#include "RE/MenuEventHandler.h"
#include "RE/NiColor.h"
#include "RE/SimpleAnimationGraphManagerHolder.h"


namespace RE
{
	// menuDepth = 8
	// flags = kDisablePauseMenu | kAllowSaving | kDontHideCursorWhenTopmost
	// context = kNone
	class MistMenu :
		public IMenu,							   // 00
		public SimpleAnimationGraphManagerHolder,  // 30
		public MenuEventHandler					   // 48
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_MistMenu;
		constexpr static std::string_view MENU_NAME = "Mist Menu";


		struct Colors
		{
			enum Color
			{
				kXNeg,
				kXPos,
				kYNeg,
				kYPos,
				kZNeg,
				kZPos,

				kTotal
			};
		};


		virtual ~MistMenu();  // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05
		virtual void			   PostDisplay() override;										   // 06

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool ProcessMouseMove(MouseMoveEvent* a_event) override;	// 04
		virtual bool ProcessButton(ButtonEvent* a_event) override;			// 05


		// members
		NiColor ambientColors[Colors::kTotal];	// 058
		UInt32	unk0A0;							// 0A0
		UInt32	unk0A4;							// 0A4
		UInt64	unk0A8;							// 0A8
		void*	unk0B0;							// 0B0 - smart ptr
		void*	unk0B8;							// 0B8
		void*	unk0C0;							// 0C0
		void*	unk0C8;							// 0C8 - smart ptr
		void*	unk0D0;							// 0D0 - smart ptr
		void*	unk0D8;							// 0D8 - smart ptr
		void*	unk0E0;							// 0E0 - smart ptr
		UInt64	unk0E8;							// 0E8
		UInt64	unk0F0;							// 0F0
		UInt64	unk0F8;							// 0F8
		UInt32	unk100;							// 100
		UInt32	unk104;							// 104
		UInt32	unk108;							// 108
		UInt32	unk10C;							// 10C
		float	unk110;							// 110
		UInt32	unk114;							// 114
		UInt64	unk118;							// 118
		float	unk120;							// 120
		UInt32	unk124;							// 124
		UInt64	unk128;							// 128
		float	unk130;							// 130
		UInt8	unk134;							// 134
		UInt8	unk135;							// 135
		UInt16	unk136;							// 136
		UInt32	unk138;							// 138
		UInt32	pad13C;							// 13C
	};
	STATIC_ASSERT(sizeof(MistMenu) == 0x140);
}
