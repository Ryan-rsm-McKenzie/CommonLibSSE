#pragma once

#include "skse64/GameRTTI.h"  // RTTI_CraftingSubMenus__EnchantConstructMenu, RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuCallback, RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuDisenchantCallback, RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuCraftCallback, RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuExitCallback

#include "RE/BSString.h"  // BSString
#include "RE/CraftingSubMenu.h"  // CraftingSubMenu
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMessageBoxCallback.h"  // IMessageBoxCallback


namespace RE
{
	namespace CraftingSubMenus
	{
		class EnchantConstructMenu : public CraftingSubMenu
		{
		public:
			inline static const void* RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu;


			class EnchantMenuCallback : public IMessageBoxCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuCallback;


				virtual ~EnchantMenuCallback();	// 00


				// members
				EnchantConstructMenu* subMenu;	// 10
			};
			STATIC_ASSERT(sizeof(EnchantMenuCallback) == 0x18);


			class EnchantMenuDisenchantCallback : public EnchantMenuCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuDisenchantCallback;


				virtual ~EnchantMenuDisenchantCallback();	// 00

				// override (EnchantMenuCallback)
				virtual void Run(Message a_msg) override;	// 01
			};
			STATIC_ASSERT(sizeof(EnchantMenuDisenchantCallback) == 0x18);


			class EnchantMenuCraftCallback : public EnchantMenuCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuCraftCallback;


				virtual ~EnchantMenuCraftCallback();		// 00

				// override (EnchantMenuCallback)
				virtual void Run(Message a_msg) override;	// 01
			};
			STATIC_ASSERT(sizeof(EnchantMenuCraftCallback) == 0x18);


			class EnchantMenuExitCallback : public EnchantMenuCallback
			{
			public:
				inline static const void* RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuExitCallback;


				virtual ~EnchantMenuExitCallback();			// 00

				// override (EnchantMenuCallback)
				virtual void Run(Message a_msg) override;	// 01
			};
			STATIC_ASSERT(sizeof(EnchantMenuExitCallback) == 0x18);


			virtual ~EnchantConstructMenu();								// 00

			// override (CraftingSubMenu)
			virtual void	Accept(CallbackProcessor* a_cbReg) override;	// 01
			virtual void	Unk_04(void) override;							// 04 - { return unk20C != 3 || unk1A0; }
			virtual void	Unk_05(void) override;							// 05
			virtual void	Unk_07(void) override;							// 07


			// members
			UInt64		unk100;	// 100
			UInt64		unk108;	// 108
			UInt64		unk110;	// 110
			UInt64		unk118;	// 118
			UInt64		unk120;	// 120
			UInt64		unk128;	// 128
			BSString	unk130;	// 130
			GFxValue	unk140;	// 140
			GFxValue	unk158;	// 158
			UInt64		unk170;	// 170
			UInt64		unk178;	// 178
			UInt64		unk180;	// 180
			UInt64		unk188;	// 188
			UInt64		unk190;	// 190
			UInt64		unk198;	// 198
			UInt64		unk1A0;	// 1A0
			UInt64		unk1A8;	// 1A8
			UInt64		unk1B0;	// 1B0
			UInt64		unk1B8;	// 1B8
			UInt64		unk1C0;	// 1C0
			UInt64		unk1C8;	// 1C8
			UInt64		unk1D0;	// 1D0
			UInt64		unk1D8;	// 1D8
			UInt64		unk1E0;	// 1E0
			UInt64		unk1E8;	// 1E8
			UInt64		unk1F0;	// 1F0
			UInt64		unk1F8;	// 1F8
			UInt64		unk200;	// 200
			UInt32		unk208;	// 208
			UInt32		unk20C;	// 20C
			UInt64		unk210;	// 210
			UInt64		unk218;	// 218
		};
		STATIC_ASSERT(sizeof(EnchantConstructMenu) == 0x220);
	}
}
