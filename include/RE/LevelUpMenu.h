#pragma once

#include <string_view>

#include "RE/IMenu.h"


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
		bool   unk30;  // 30
		UInt8  pad31;  // 31
		UInt16 pad32;  // 32
		UInt32 pad34;  // 34
	};
	STATIC_ASSERT(sizeof(LevelUpMenu) == 0x38);
}
