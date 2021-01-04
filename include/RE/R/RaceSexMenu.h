#pragma once

#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/R/RaceSexCamera.h"
#include "RE/S/Sexes.h"

namespace RE
{
	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kRequiresUpdate | kTopmostRenderedMenu | kUpdateUsesCursor
	// context = kItemMenu
	class RaceSexMenu :
		public IMenu,			 // 00
		public MenuEventHandler	 // 30
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_RaceSexMenu;
		constexpr static std::string_view MENU_NAME = "RaceSex Menu";

		virtual ~RaceSexMenu();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;						  // 01
		virtual void			   PostCreate() override;												  // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) = 0;		   // 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event);  // 03
		virtual bool ProcessMouseMove(MouseMoveEvent* a_event);	   // 04
		virtual bool ProcessButton(ButtonEvent* a_event);		   // 05

		// members
		BSTArray<void*>						 unk040[7];	 // 040
		RaceSexCamera						 camera;	 // 0E8
		BSTArray<void*>						 unk140[2];	 // 140
		BSTArray<void*>						 unk170;	 // 170
		std::uint64_t						 unk188;	 // 188
		std::uint32_t						 unk190;	 // 190
		std::uint32_t						 unk194;	 // 194
		stl::enumeration<SEX, std::uint32_t> sex;		 // 198
		std::uint16_t						 unk19C;	 // 19C
		std::uint8_t						 unk19E;	 // 19E
		std::uint8_t						 pad19F;	 // 19F
		std::uint8_t						 unk1A0;	 // 1A0
		std::uint8_t						 unk1A1;	 // 1A1
		std::uint16_t						 unk1A2;	 // 1A2
		std::uint32_t						 unk1A4;	 // 1A4
	};
	static_assert(sizeof(RaceSexMenu) == 0x1A8);
}
