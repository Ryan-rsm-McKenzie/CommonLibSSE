#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/F/FxDelegateHandler.h"
#include "RE/G/GFxValue.h"

namespace RE
{
	class TESFurniture;
	struct TESFurnitureEvent;

	namespace CraftingSubMenus
	{
		class CraftingSubMenu :
			public FxDelegateHandler,               // 00
			public BSTEventSink<TESFurnitureEvent>  // 10
		{
		public:
			inline static constexpr auto RTTI = RTTI_CraftingSubMenus__CraftingSubMenu;

			~CraftingSubMenu() override;  // 00

			// add
			virtual void Unk_02(void);  // 02 - { return; }
			virtual void Unk_03(void);  // 03 - { return; }
			virtual void Unk_04(void);  // 04 - { return 1; }
			virtual void Unk_05(void);  // 05 - { return 0; }
			virtual void Unk_06(void);  // 06 - { return; }
			virtual void Unk_07(void);  // 07 - { return; }

			// members
			std::uint64_t unk018;     // 018
			TESFurniture* furniture;  // 020
			std::uint64_t unk028;     // 028
			GFxValue*     unk030;     // 030
			GFxValue      unk038;     // 038
			GFxValue      unk050;     // 050
			GFxValue      unk068;     // 068
			GFxValue      unk080;     // 080
			GFxValue      unk098;     // 098
			GFxValue      unk0B0;     // 0B0
			GFxValue      unk0C8;     // 0C8
			GFxValue      unk0E0;     // 0E0
			std::uint64_t unk0F8;     // 0F8
		};
		static_assert(sizeof(CraftingSubMenu) == 0x100);
	}
}
