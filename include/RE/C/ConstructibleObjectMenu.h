#pragma once

#include "RE/B/BSTArray.h"
#include "RE/C/CraftingSubMenu.h"
#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class ConstructibleObjectMenu : public CraftingSubMenu
		{
		public:
			inline static constexpr auto RTTI = RTTI_CraftingSubMenus__ConstructibleObjectMenu;

			class CreationConfirmCallback : public IMessageBoxCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__ConstructibleObjectMenu__CreationConfirmCallback;

				~CreationConfirmCallback() override;  // 00

				// override (IMessageBoxCallback)
				void Run(Message a_msg) override;  // 01

				// members
				ConstructibleObjectMenu* menu;  // 10
			};
			static_assert(sizeof(CreationConfirmCallback) == 0x18);

			~ConstructibleObjectMenu() override;  // 00

			// override (CraftingSubMenu)
			void Accept(CallbackProcessor* a_cbReg) override;  // 01
			void Unk_06(void) override;                        // 06
			void Unk_07(void) override;                        // 07

			// members
			BSTArray<void*> unk100;  // 100
			std::uint64_t   unk118;  // 118
			std::uint64_t   unk120;  // 120
			std::uint64_t   unk128;  // 128
			std::uint64_t   unk130;  // 130
			std::uint64_t   unk138;  // 138
			std::uint64_t   unk140;  // 140
			std::uint64_t   unk148;  // 148
			std::uint64_t   unk150;  // 150
			std::uint64_t   unk158;  // 158
		};
		static_assert(sizeof(ConstructibleObjectMenu) == 0x160);
	}
}
