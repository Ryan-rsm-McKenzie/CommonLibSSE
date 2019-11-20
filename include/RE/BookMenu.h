#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BookMenu

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/GPtr.h"  // GPtr
#include "RE/ImageData.h"  // ImageData
#include "RE/IMenu.h"  // IMenu
#include "RE/SimpleAnimationGraphManagerHolder.h"  // SimpleAnimationGraphManagerHolder


namespace RE
{
	struct BSAnimationGraphEvent;


	class BookMenu :
		public IMenu,								// 00
		public SimpleAnimationGraphManagerHolder,	// 30
		public BSTEventSink<BSAnimationGraphEvent>	// 48
	{
	public:
		inline static const void* RTTI = RTTI_BookMenu;


		virtual ~BookMenu();																												// 00

		// override (IMenu)
		virtual Result	ProcessMessage(UIMessage* a_message) override;																		// 04
		virtual void	NextFrame(float a_arg1, UInt32 a_currentTime) override;																// 05
		virtual void	Render() override;																									// 06
		virtual void	Unk_07(void) override;																								// 07

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual	EventResult	ReceiveEvent(BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;	// 01


		// members
		BSTArray<ImageData>	unk50;	// 50
		GPtr<GFxMovieView>	book;	// 68
		void*				unk70;	// 70 - smart ptr
		UInt32				unk78;	// 78
		UInt32				pad7C;	// 7C
		UInt64				unk80;	// 80
		void*				unk88;	// 88 - smart ptr
		UInt16				unk90;	// 90
		UInt16				unk92;	// 92
		UInt8				unk94;	// 94
		bool				isNote;	// 95
		UInt8				unk96;	// 96
		UInt8				pad97;	// 97
	};
	STATIC_ASSERT(sizeof(BookMenu) == 0x98);
}
