#pragma once

#include "skse64/GameRTTI.h"  // RTTI_LevelUpMenu

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class LevelUpMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_LevelUpMenu;


		virtual ~LevelUpMenu();										// 00

		// override (IMenu)
		virtual void Accept(CallbackProcessor* a_cbReg) override;	// 01


		// members
		bool	unk30;	// 30
		UInt8	pad31;	// 31
		UInt16	pad32;	// 32
		UInt32	pad34;	// 34
	};
	STATIC_ASSERT(sizeof(LevelUpMenu) == 0x38);
}
