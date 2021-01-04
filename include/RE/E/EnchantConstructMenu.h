#pragma once

#include "RE/B/BSString.h"
#include "RE/C/CraftingSubMenu.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class EnchantConstructMenu : public CraftingSubMenu
		{
		public:
			inline static constexpr auto RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu;

			class EnchantMenuCallback : public IMessageBoxCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuCallback;

				virtual ~EnchantMenuCallback();	 // 00

				// members
				EnchantConstructMenu* subMenu;	// 10
			};
			static_assert(sizeof(EnchantMenuCallback) == 0x18);

			class EnchantMenuDisenchantCallback : public EnchantMenuCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuDisenchantCallback;

				virtual ~EnchantMenuDisenchantCallback();  // 00

				// override (EnchantMenuCallback)
				virtual void Run(Message a_msg) override;  // 01
			};
			static_assert(sizeof(EnchantMenuDisenchantCallback) == 0x18);

			class EnchantMenuCraftCallback : public EnchantMenuCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuCraftCallback;

				virtual ~EnchantMenuCraftCallback();  // 00

				// override (EnchantMenuCallback)
				virtual void Run(Message a_msg) override;  // 01
			};
			static_assert(sizeof(EnchantMenuCraftCallback) == 0x18);

			class EnchantMenuExitCallback : public EnchantMenuCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__EnchantConstructMenu__EnchantMenuExitCallback;

				virtual ~EnchantMenuExitCallback();	 // 00

				// override (EnchantMenuCallback)
				virtual void Run(Message a_msg) override;  // 01
			};
			static_assert(sizeof(EnchantMenuExitCallback) == 0x18);

			virtual ~EnchantConstructMenu();  // 00

			// override (CraftingSubMenu)
			virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01
			virtual void Unk_04(void) override;						   // 04 - { return unk20C != 3 || unk1A0; }
			virtual void Unk_05(void) override;						   // 05
			virtual void Unk_07(void) override;						   // 07

			// members
			std::uint64_t unk100;  // 100
			std::uint64_t unk108;  // 108
			std::uint64_t unk110;  // 110
			std::uint64_t unk118;  // 118
			std::uint64_t unk120;  // 120
			std::uint64_t unk128;  // 128
			BSString	  unk130;  // 130
			GFxValue	  unk140;  // 140
			GFxValue	  unk158;  // 158
			std::uint64_t unk170;  // 170
			std::uint64_t unk178;  // 178
			std::uint64_t unk180;  // 180
			std::uint64_t unk188;  // 188
			std::uint64_t unk190;  // 190
			std::uint64_t unk198;  // 198
			std::uint64_t unk1A0;  // 1A0
			std::uint64_t unk1A8;  // 1A8
			std::uint64_t unk1B0;  // 1B0
			std::uint64_t unk1B8;  // 1B8
			std::uint64_t unk1C0;  // 1C0
			std::uint64_t unk1C8;  // 1C8
			std::uint64_t unk1D0;  // 1D0
			std::uint64_t unk1D8;  // 1D8
			std::uint64_t unk1E0;  // 1E0
			std::uint64_t unk1E8;  // 1E8
			std::uint64_t unk1F0;  // 1F0
			std::uint64_t unk1F8;  // 1F8
			std::uint64_t unk200;  // 200
			std::uint32_t unk208;  // 208
			std::uint32_t unk20C;  // 20C
			std::uint64_t unk210;  // 210
			std::uint64_t unk218;  // 218
		};
		static_assert(sizeof(EnchantConstructMenu) == 0x220);
	}
}
