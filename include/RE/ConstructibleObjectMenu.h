#pragma once

#include "skse64/GameRTTI.h"  // RTTI_CraftingSubMenus__ConstructibleObjectMenu, RTTI_CraftingSubMenus__ConstructibleObjectMenu__CreationConfirmCallback

#include "RE/BSTArray.h"  // BSTArray
#include "RE/CraftingSubMenu.h"  // CraftingSubMenu
#include "RE/IMessageBoxCallback.h"  // IMessageBoxCallback


namespace RE
{
	namespace CraftingSubMenus
	{
		class ConstructibleObjectMenu : public CraftingSubMenu
		{
		public:
			inline static const void* RTTI = RTTI_CraftingSubMenus__ConstructibleObjectMenu;


			class CreationConfirmCallback : public IMessageBoxCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__ConstructibleObjectMenu__CreationConfirmCallback;


				virtual ~CreationConfirmCallback();			// 00

				// override (IMessageBoxCallback)
				virtual void Run(Message a_msg) override;	// 01


				// members
				ConstructibleObjectMenu* menu;	// 10
			};
			STATIC_ASSERT(sizeof(CreationConfirmCallback) == 0x18);


			virtual ~ConstructibleObjectMenu();								// 00

			// override (CraftingSubMenu)
			virtual void	Accept(CallbackProcessor* a_cbReg) override;	// 01
			virtual void	Unk_06(void) override;							// 06
			virtual void	Unk_07(void) override;							// 07


			// members
			BSTArray<void*>	unk100;	// 100
			UInt64			unk118;	// 118
			UInt64			unk120;	// 120
			UInt64			unk128;	// 128
			UInt64			unk130;	// 130
			UInt64			unk138;	// 138
			UInt64			unk140;	// 140
			UInt64			unk148;	// 148
			UInt64			unk150;	// 150
			UInt64			unk158;	// 158
		};
		STATIC_ASSERT(sizeof(ConstructibleObjectMenu) == 0x160);
	}
}
