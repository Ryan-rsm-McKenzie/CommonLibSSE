#pragma once

#include "RE/G/GFxFunctionHandler.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"

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
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03

		// override (GFxFunctionHandler)
		virtual void Call(Params& a_params) override;  // 01

		// members
		std::uint8_t  unk50;  // 50
		std::uint8_t  pad51;  // 51
		std::uint16_t pad52;  // 52
		std::uint32_t pad54;  // 54
	};
	static_assert(sizeof(ModManagerMenu) == 0x58);
}
