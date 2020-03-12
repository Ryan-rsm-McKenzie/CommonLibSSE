#pragma once

#include <string_view>

#include "RE/BSTEvent.h"
#include "RE/GPtr.h"
#include "RE/IMenu.h"
#include "RE/ImageData.h"
#include "RE/SimpleAnimationGraphManagerHolder.h"


namespace RE
{
	struct BSAnimationGraphEvent;


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
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05
		virtual void			   PostDisplay() override;										   // 06
		virtual void			   PreDisplay() override;										   // 07

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	 // 01


		// members
		BSTArray<ImageData> unk50;	 // 50
		GPtr<GFxMovieView>	book;	 // 68
		void*				unk70;	 // 70 - smart ptr
		UInt32				unk78;	 // 78
		UInt32				pad7C;	 // 7C
		UInt64				unk80;	 // 80
		void*				unk88;	 // 88 - smart ptr
		UInt16				unk90;	 // 90
		UInt16				unk92;	 // 92
		UInt8				unk94;	 // 94
		bool				isNote;	 // 95
		UInt8				unk96;	 // 96
		UInt8				pad97;	 // 97
	};
	STATIC_ASSERT(sizeof(BookMenu) == 0x98);
}
