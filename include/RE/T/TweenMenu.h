#pragma once

#include "RE/B/BSTArray.h"
#include "RE/I/IMenu.h"

namespace RE
{
	namespace BSResource
	{
		struct ID;
	}

	// menuDepth = 0
	// flags = kPausesGame | kUpdateUsesCursor | kAllowSaving | kDontHideCursorWhenTopmost | kCustomRendering
	// context = kMenuMode
	class TweenMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_TweenMenu;
		constexpr static std::string_view MENU_NAME = "TweenMenu";

		struct PerkData
		{
		public:
			// members
			BSResource::ID* fileHash;  // 00
			const char*		fileName;  // 08
		};
		static_assert(sizeof(PerkData) == 0x10);

		virtual ~TweenMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06

		// members
		BSTArray<PerkData> perkData;  // 30
		float			   unk48;	  // 48
		float			   unk4C;	  // 4C
	};
	static_assert(sizeof(TweenMenu) == 0x50);
}
