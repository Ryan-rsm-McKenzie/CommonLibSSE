#pragma once

#include "skse64/GameRTTI.h"  // RTTI_CraftingSubMenus__CraftingSubMenu

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/FxDelegateHandler.h"  // FxDelegateHandler
#include "RE/GFxValue.h"  // GFxValue


namespace RE
{
	struct TESFurnitureEvent;


	namespace CraftingSubMenus
	{
		class CraftingSubMenu :
			public FxDelegateHandler,				// 00
			public BSTEventSink<TESFurnitureEvent>	// 10
		{
		public:
			inline static const void* RTTI = RTTI_CraftingSubMenus__CraftingSubMenu;


			virtual ~CraftingSubMenu();		// 00

			// add
			virtual void	Unk_02(void);	// 02 - { return; }
			virtual void	Unk_03(void);	// 03 - { return; }
			virtual void	Unk_04(void);	// 04 - { return 1; }
			virtual void	Unk_05(void);	// 05 - { return 0; }
			virtual void	Unk_06(void);	// 06 - { return; }
			virtual void	Unk_07(void);	// 07 - { return; }


			// members
			UInt64		unk018;	// 018
			UInt64		unk020;	// 020
			UInt64		unk028;	// 028
			GFxValue*	unk030;	// 030
			GFxValue	unk038;	// 038
			GFxValue	unk050;	// 050
			GFxValue	unk068;	// 068
			GFxValue	unk080;	// 080
			GFxValue	unk098;	// 098
			GFxValue	unk0B0;	// 0B0
			GFxValue	unk0C8;	// 0C8
			GFxValue	unk0E0;	// 0E0
			UInt64		unk0F8;	// 0F8
		};
		STATIC_ASSERT(sizeof(CraftingSubMenu) == 0x100);
	}
}
