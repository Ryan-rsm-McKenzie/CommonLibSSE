#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/G/GPtr.h"
#include "RE/I/IMenu.h"
#include "RE/I/ImageData.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	struct BSAnimationGraphEvent;

	class TESObjectREFR;

	// menuDepth = 1
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kRequiresUpdate | kTopmostRenderedMenu | kRendersOffscreenTargets
	// context = kBook
	class BookMenu :
		public IMenu,								// 00
		public SimpleAnimationGraphManagerHolder,	// 30
		public BSTEventSink<BSAnimationGraphEvent>	// 48
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_BookMenu;
		constexpr static std::string_view MENU_NAME = "Book Menu";

		virtual ~BookMenu();  // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		virtual void			   PostDisplay() override;												  // 06
		virtual void			   PreDisplay() override;												  // 07

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	 // 01

		[[nodiscard]] TESObjectREFR* GetTargetReference();	// returns null if opened from inventory

		// members
		BSTArray<ImageData> unk50;		// 50
		GPtr<GFxMovieView>	book;		// 68
		void*				unk70;		// 70 - smart ptr
		std::uint32_t		unk78;		// 78
		std::uint32_t		pad7C;		// 7C
		std::uint64_t		unk80;		// 80
		void*				unk88;		// 88 - smart ptr
		std::uint16_t		unk90;		// 90
		std::uint16_t		unk92;		// 92
		bool				closeMenu;	// 94
		bool				isNote;		// 95
		std::uint8_t		unk96;		// 96
		std::uint8_t		pad97;		// 97
	};
	static_assert(sizeof(BookMenu) == 0x98);
}
