#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"

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
		public BSTEventSink<InputEvent*>,         // 00
		public BSTSingletonSDM<MenuControls>,     // 10
		public BSTEventSink<MenuModeChangeEvent>  // 08
	{
	public:
		struct QueuedReg
		{
		public:
			QueuedReg(MenuEventHandler* a_handler, bool a_add);
			~QueuedReg() = default;

			// members
			MenuEventHandler* handler;  // 00
			bool              add;      // 08
			std::uint8_t      pad08;    // 09
			std::uint16_t     pad09;    // 0A
			std::uint32_t     pad0A;    // 0C
		};
		static_assert(sizeof(QueuedReg) == 0x10);

		~MenuControls() override;  // 00

		// override (BSTEventSink<InputEvent*>)
		BSEventNotifyControl ProcessEvent(InputEvent* const* a_event, BSTEventSource<InputEvent*>* a_eventSource) override;  // 01

		// override (BSTEventSink<MenuModeChangeEvent>)
		BSEventNotifyControl ProcessEvent(const MenuModeChangeEvent* a_event, BSTEventSource<MenuModeChangeEvent>* a_eventSource) override;  // 01

		static MenuControls* GetSingleton();

		void                         AddHandler(MenuEventHandler* a_handler);
		[[nodiscard]] constexpr bool InBeastForm() const noexcept { return beastForm; }
		void                         RegisterHandler(MenuEventHandler* a_handler);
		void                         RemoveHandler(MenuEventHandler* a_handler);
		void                         UnregisterHandler(MenuEventHandler* a_handler);

		// members
		std::uint8_t                          pad11;                 // 11
		std::uint16_t                         pad12;                 // 12
		std::uint32_t                         pad14;                 // 14
		BSTArray<MenuEventHandler*>           handlers;              // 18
		BSTArray<QueuedReg>                   regBuffer;             // 30
		BSTSmartPointer<ClickHandler>         clickHandler;          // 48
		BSTSmartPointer<DirectionHandler>     directionHandler;      // 50
		BSTSmartPointer<ConsoleOpenHandler>   consoleOpenHandler;    // 58
		BSTSmartPointer<QuickSaveLoadHandler> quickSaveLoadHandler;  // 60
		BSTSmartPointer<MenuOpenHandler>      menuOpenHandler;       // 68
		BSTSmartPointer<FavoritesHandler>     favoritesHandler;      // 70
		BSTSmartPointer<ScreenshotHandler>    screenshotHandler;     // 78
		bool                                  isProcessing;          // 80
		bool                                  beastForm;             // 81
		bool                                  remapMode;             // 82
		std::uint8_t                          unk83;                 // 83
		std::uint32_t                         unk84;                 // 84
	};
	static_assert(offsetof(MenuControls, handlers) == 0x18);
	static_assert(offsetof(MenuControls, remapMode) == 0x82);
	static_assert(sizeof(MenuControls) == 0x88);
}
