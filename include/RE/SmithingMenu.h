#pragma once

#include "skse64/GameRTTI.h"  // RTTI_CraftingSubMenus__SmithingMenu, RTTI_CraftingSubMenus__SmithingMenu__SmithingConfirmCallback

#include "RE/CraftingSubMenu.h"  // CraftingSubMenu
#include "RE/IMessageBoxCallback.h"  // IMessageBoxCallback


namespace RE
{
	namespace CraftingSubMenus
	{
		class SmithingMenu : public CraftingSubMenu
		{
		public:
			inline static const void* RTTI = RTTI_CraftingSubMenus__SmithingMenu;


			class SmithingConfirmCallback : public IMessageBoxCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__SmithingMenu__SmithingConfirmCallback;


				virtual ~SmithingConfirmCallback();			// 00

				// override (IMessageBoxCallback)
				virtual void Run(Message a_msg) override;	// 01


				// members
				SmithingMenu* subMenu;	// 10
			};
			STATIC_ASSERT(sizeof(SmithingConfirmCallback) == 0x18);


			virtual ~SmithingMenu();										// 00

			// override (CraftingSubMenu)
			virtual void	Accept(CallbackProcessor* a_cbReg) override;	// 01
			virtual void	Unk_02(void) override;							// 02
			virtual void	Unk_05(void) override;							// 05


			// members
			void*	unk100;	// 100
			UInt64	unk108;	// 108
			UInt64	unk110;	// 110
			UInt64	unk118;	// 118
			UInt64	unk120;	// 120
			UInt64	unk128;	// 128
			UInt64	unk130;	// 130
			UInt64	unk138;	// 138
			void*	unk140;	// 140
			void*	unk148;	// 148
			UInt64	unk150;	// 150
			UInt64	unk158;	// 158
			void*	unk160;	// 160
		};
		STATIC_ASSERT(sizeof(SmithingMenu) == 0x168);
	}
}
