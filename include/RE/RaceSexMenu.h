#pragma once

#include <string_view>

#include "RE/IMenu.h"
#include "RE/MenuEventHandler.h"
#include "RE/RaceSexCamera.h"


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


		enum class Sex : UInt32
		{
			kError = static_cast<std::underlying_type_t<Sex>>(-1),
			kMale = 0,
			kFemale = 1
		};


		virtual ~RaceSexMenu();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;				   // 01
		virtual void			   PostCreate() override;										   // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) = 0;		   // 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event);  // 03
		virtual bool ProcessMouseMove(MouseMoveEvent* a_event);	   // 04
		virtual bool ProcessButton(ButtonEvent* a_event);		   // 05


		// members
		BSTArray<void*> unk040[7];	// 040
		RaceSexCamera	camera;		// 0E8
		BSTArray<void*> unk140[2];	// 140
		BSTArray<void*> unk170;		// 170
		UInt64			unk188;		// 188
		UInt32			unk190;		// 190
		UInt32			unk194;		// 194
		Sex				sex;		// 198
		UInt16			unk19C;		// 19C
		UInt8			unk19E;		// 19E
		UInt8			pad19F;		// 19F
		UInt8			unk1A0;		// 1A0
		UInt8			unk1A1;		// 1A1
		UInt16			unk1A2;		// 1A2
		UInt32			unk1A4;		// 1A4
	};
	STATIC_ASSERT(sizeof(RaceSexMenu) == 0x1A8);
}
