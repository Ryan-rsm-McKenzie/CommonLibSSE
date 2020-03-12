#pragma once

#include <string_view>

#include "RE/GFxFunctionHandler.h"
#include "RE/IMenu.h"
#include "RE/MenuEventHandler.h"


namespace RE
{
	// menuDepth = 9
	// flags = kPausesGame | kUsesMenuContext | kModal | kDisablePauseMenu | kRequiresUpdate | kTopmostRenderedMenu | kUpdateUsesCursor
	// context = kMenuMode
	class ModManagerMenu :
		public IMenu,			   // 00
		public MenuEventHandler,   // 30
		public GFxFunctionHandler  // 40
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_ModManagerMenu;
		constexpr static std::string_view MENU_NAME = "Mod Manager Menu";


		virtual ~ModManagerMenu();	// 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03

		// override (GFxFunctionHandler)
		virtual void Call(Params& a_params) override;  // 01


		// members
		UInt8  unk50;  // 50
		UInt8  pad51;  // 51
		UInt16 pad52;  // 52
		UInt32 pad54;  // 54
	};
	STATIC_ASSERT(sizeof(ModManagerMenu) == 0x58);
}
