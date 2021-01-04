#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 3
	// flags = kPausesGame | kModal | kDisablePauseMenu
	// kUsesCursor is gamepad is disabled
	// context = kMenuMode
	class LevelUpMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_LevelUpMenu;
		constexpr static std::string_view MENU_NAME = "LevelUp Menu";

		virtual ~LevelUpMenu();	 // 00

		// override (IMenu)
		virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01

		// members
		bool		  unk30;  // 30
		std::uint8_t  pad31;  // 31
		std::uint16_t pad32;  // 32
		std::uint32_t pad34;  // 34
	};
	static_assert(sizeof(LevelUpMenu) == 0x38);
}
