#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CraftingSubMenu.h"
#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class AlchemyMenu : public CraftingSubMenu
		{
		public:
			inline static constexpr auto RTTI = RTTI_CraftingSubMenus__AlchemyMenu;

			class QuitMenuCallback : public IMessageBoxCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__AlchemyMenu__QuitMenuCallback;

				virtual ~QuitMenuCallback();  // 00

				// override (IMessageBoxCallback)
				virtual void Run(Message a_msg) override;  // 01

				// members
				AlchemyMenu* subMenu;  // 10
			};
			static_assert(sizeof(QuitMenuCallback) == 0x18);

			virtual ~AlchemyMenu();	 // 00

			// override (CraftingSubMenu)
			virtual void Accept(CallbackProcessor* a_cbReg) override;  // 01
			virtual void Unk_05(void) override;						   // 05

			// members
			BSTArray<void*> unk100;	 // 100
			BSTArray<void*> unk118;	 // 118
			std::uint64_t	unk130;	 // 130
			BSTArray<void*> unk138;	 // 138
			std::uint64_t	unk150;	 // 150
			GFxValue		unk158;	 // 158
			std::uint64_t	unk170;	 // 170
			TESForm*		unk178;	 // 178
			TESForm*		unk180;	 // 180
			std::uint64_t	unk188;	 // 188
			BSFixedString	unk190;	 // 190
			std::uint64_t	unk198;	 // 198
		};
		static_assert(sizeof(AlchemyMenu) == 0x1A0);
	}
}
