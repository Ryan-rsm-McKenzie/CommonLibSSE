#pragma once

#include "skse64/GameRTTI.h"  // RTTI_CraftingSubMenus__AlchemyMenu, RTTI_CraftingSubMenus__AlchemyMenu__QuitMenuCallback

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/CraftingSubMenu.h"  // CraftingSubMenu
#include "RE/IMessageBoxCallback.h"  // IMessageBoxCallback


namespace RE
{
	namespace CraftingSubMenus
	{
		class AlchemyMenu : public CraftingSubMenu
		{
		public:
			inline static const void* RTTI = RTTI_CraftingSubMenus__AlchemyMenu;


			class QuitMenuCallback : public IMessageBoxCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__AlchemyMenu__QuitMenuCallback;


				virtual ~QuitMenuCallback();				// 00

				// override (IMessageBoxCallback)
				virtual void Run(Message a_msg) override;	// 01


				// members
				AlchemyMenu* subMenu;	// 10
			};
			STATIC_ASSERT(sizeof(QuitMenuCallback) == 0x18);


			virtual ~AlchemyMenu();											// 00

			// override (CraftingSubMenu)
			virtual void	Accept(CallbackProcessor* a_cbReg) override;	// 01
			virtual void	Unk_05(void) override;							// 05


			// members
			BSTArray<void*>	unk100;	// 100
			BSTArray<void*>	unk118;	// 118
			UInt64			unk130;	// 130
			BSTArray<void*>	unk138;	// 138
			UInt64			unk150;	// 150
			GFxValue		unk158;	// 158
			UInt64			unk170;	// 170
			TESForm*		unk178;	// 178
			TESForm*		unk180;	// 180
			UInt64			unk188;	// 188
			BSFixedString	unk190;	// 190
			UInt64			unk198;	// 198
		};
		STATIC_ASSERT(sizeof(AlchemyMenu) == 0x1A0);
	}
}
