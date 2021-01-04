#pragma once

#include "RE/C/CraftingSubMenu.h"
#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class SmithingMenu : public CraftingSubMenu
		{
		public:
			inline static constexpr auto RTTI = RTTI_CraftingSubMenus__SmithingMenu;

			class SmithingConfirmCallback : public IMessageBoxCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__SmithingMenu__SmithingConfirmCallback;

				virtual ~SmithingConfirmCallback();	 // 00

				// override (IMessageBoxCallback)
				virtual void Run(Message a_msg) override;  // 01

				// members
				SmithingMenu* subMenu;	// 10
			};
			static_assert(sizeof(SmithingConfirmCallback) == 0x18);

			virtual ~SmithingMenu();  // 00

			// override (CraftingSubMenu)
			virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01
			virtual void Unk_02(void) override;						   // 02
			virtual void Unk_05(void) override;						   // 05

			// members
			void*		  unk100;  // 100
			std::uint64_t unk108;  // 108
			std::uint64_t unk110;  // 110
			std::uint64_t unk118;  // 118
			std::uint64_t unk120;  // 120
			std::uint64_t unk128;  // 128
			std::uint64_t unk130;  // 130
			std::uint64_t unk138;  // 138
			void*		  unk140;  // 140
			void*		  unk148;  // 148
			std::uint64_t unk150;  // 150
			std::uint64_t unk158;  // 158
			void*		  unk160;  // 160
		};
		static_assert(sizeof(SmithingMenu) == 0x168);
	}
}
