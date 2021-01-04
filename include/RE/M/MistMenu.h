#pragma once

#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiColor.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

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
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		virtual void			   PostDisplay() override;												  // 06

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool ProcessMouseMove(MouseMoveEvent* a_event) override;	// 04
		virtual bool ProcessButton(ButtonEvent* a_event) override;			// 05

		// members
		NiColor		  ambientColors[Colors::kTotal];  // 058
		std::uint32_t unk0A0;						  // 0A0
		std::uint32_t unk0A4;						  // 0A4
		std::uint64_t unk0A8;						  // 0A8
		void*		  unk0B0;						  // 0B0 - smart ptr
		void*		  unk0B8;						  // 0B8
		void*		  unk0C0;						  // 0C0
		void*		  unk0C8;						  // 0C8 - smart ptr
		void*		  unk0D0;						  // 0D0 - smart ptr
		void*		  unk0D8;						  // 0D8 - smart ptr
		void*		  unk0E0;						  // 0E0 - smart ptr
		std::uint64_t unk0E8;						  // 0E8
		std::uint64_t unk0F0;						  // 0F0
		std::uint64_t unk0F8;						  // 0F8
		std::uint32_t unk100;						  // 100
		std::uint32_t unk104;						  // 104
		std::uint32_t unk108;						  // 108
		std::uint32_t unk10C;						  // 10C
		float		  unk110;						  // 110
		std::uint32_t unk114;						  // 114
		std::uint64_t unk118;						  // 118
		float		  unk120;						  // 120
		std::uint32_t unk124;						  // 124
		std::uint64_t unk128;						  // 128
		float		  unk130;						  // 130
		std::uint8_t  unk134;						  // 134
		std::uint8_t  unk135;						  // 135
		std::uint16_t unk136;						  // 136
		std::uint32_t unk138;						  // 138
		std::uint32_t pad13C;						  // 13C
	};
	static_assert(sizeof(MistMenu) == 0x140);
}
