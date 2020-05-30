#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"
#include "RE/BSTSmartPointer.h"


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
		public BSTEventSink<InputEvent*>,		  // 00
		public BSTSingletonSDM<MenuControls>,	  // 10
		public BSTEventSink<MenuModeChangeEvent>  // 08
	{
	public:
		struct QueuedReg
		{
		public:
			QueuedReg(MenuEventHandler* a_handler, bool a_add);
			~QueuedReg() = default;


			// members
			MenuEventHandler* handler;	// 00
			bool			  add;		// 08
			UInt8			  pad08;	// 09
			UInt16			  pad09;	// 0A
			UInt32			  pad0A;	// 0C
		};
		STATIC_ASSERT(sizeof(QueuedReg) == 0x10);


		virtual ~MenuControls();  // 00

		// override (BSTEventSink<InputEvent*>)
		virtual BSEventNotifyControl ProcessEvent(InputEvent* const* a_event, BSTEventSource<InputEvent*>* a_eventSource) override;	 // 01

		// override (BSTEventSink<MenuModeChangeEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuModeChangeEvent* a_event, BSTEventSource<MenuModeChangeEvent>* a_eventSource) override;	 // 01


		static MenuControls* GetSingleton();

		void AddHandler(MenuEventHandler* a_handler);
		void RegisterHandler(MenuEventHandler* a_handler);
		void RemoveHandler(MenuEventHandler* a_handler);
		void UnregisterHandler(MenuEventHandler* a_handler);


		// members
		UInt8								  pad11;				 // 11
		UInt16								  pad12;				 // 12
		UInt32								  pad14;				 // 14
		BSTArray<MenuEventHandler*>			  handlers;				 // 18
		BSTArray<QueuedReg>					  regBuffer;			 // 30
		BSTSmartPointer<ClickHandler>		  clickHandler;			 // 48
		BSTSmartPointer<DirectionHandler>	  directionHandler;		 // 50
		BSTSmartPointer<ConsoleOpenHandler>	  consoleOpenHandler;	 // 58
		BSTSmartPointer<QuickSaveLoadHandler> quickSaveLoadHandler;	 // 60
		BSTSmartPointer<MenuOpenHandler>	  menuOpenHandler;		 // 68
		BSTSmartPointer<FavoritesHandler>	  favoritesHandler;		 // 70
		BSTSmartPointer<ScreenshotHandler>	  screenshotHandler;	 // 78
		bool								  isProcessing;			 // 80
		bool								  beastForm;			 // 81
		bool								  remapMode;			 // 82
		UInt8								  unk83;				 // 83
		UInt32								  unk84;				 // 84
	};
	STATIC_ASSERT(offsetof(MenuControls, handlers) == 0x18);
	STATIC_ASSERT(offsetof(MenuControls, remapMode) == 0x82);
	STATIC_ASSERT(sizeof(MenuControls) == 0x88);
}
