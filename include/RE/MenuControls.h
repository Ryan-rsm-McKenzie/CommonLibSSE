#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	class InputEvent;
	class MenuEventHandler;
	class MenuModeChangeEvent;
	struct ClickHandler;
	struct ConsoleOpenHandler;
	struct DirectionHandler;
	struct FavoritesHandler;
	struct MenuOpenHandler;
	struct QuickSaveLoadHandler;
	struct ScreenshotHandler;


	class MenuControls :
		public BSTEventSink<InputEvent*>,			// 00
		public BSTSingletonSDM<MenuControls>,		// 10
		public BSTEventSink<MenuModeChangeEvent>	// 08
	{
	public:
		struct QueuedReg
		{
			MenuEventHandler*	handler;	// 00
			bool				add;		// 08
			UInt8				pad08;		// 09
			UInt16				pad09;		// 0A
			UInt32				pad0A;		// 0C
		};
		STATIC_ASSERT(sizeof(QueuedReg) == 0x10);


		virtual ~MenuControls();																										// 00

		// override (BSTEventSink<InputEvent*>)
		virtual	EventResult	ReceiveEvent(InputEvent** a_event, BSTEventSource<InputEvent*>* a_eventSource) override;					// 01

		// override (BSTEventSink<MenuModeChangeEvent>)
		virtual	EventResult	ReceiveEvent(MenuModeChangeEvent* a_event, BSTEventSource<MenuModeChangeEvent>* a_eventSource) override;	// 01


		static MenuControls* GetSingleton();

		void	RegisterHandler(MenuEventHandler* a_handler);
		void	RemoveHandler(MenuEventHandler* a_handler);


		// members
		BSTArray<MenuEventHandler*>				handlers;				// 18
		BSTArray<QueuedReg>						regBuffer;				// 30
		BSTSmartPointer<ClickHandler>			clickHandler;			// 48
		BSTSmartPointer<DirectionHandler>		directionHandler;		// 50
		BSTSmartPointer<ConsoleOpenHandler>		consoleOpenHandler;		// 58
		BSTSmartPointer<QuickSaveLoadHandler>	quickSaveLoadHandler;	// 60
		BSTSmartPointer<MenuOpenHandler>		menuOpenHandler;		// 68
		BSTSmartPointer<FavoritesHandler>		favoritesHandler;		// 70
		BSTSmartPointer<ScreenshotHandler>		screenshotHandler;		// 78
		bool									nowProcessing;			// 80
		UInt8									unk81;					// 81
		bool									remapMode;				// 82
		UInt8									unk83;					// 83
		UInt32									unk84;					// 84
	};
	STATIC_ASSERT(offsetof(MenuControls, handlers) == 0x18);
	STATIC_ASSERT(offsetof(MenuControls, remapMode) == 0x82);
	STATIC_ASSERT(sizeof(MenuControls) == 0x88);
}
