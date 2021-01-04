#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMapCameraCallbacks.h"
#include "RE/I/IMenu.h"
#include "RE/L/LocalMapMenu.h"
#include "RE/M/MapCamera.h"

namespace RE
{
	class BSAudioManager;
	class MapLookHandler;
	class MapMoveHandler;
	class MapZoomHandler;
	class MenuOpenCloseEvent;
	class TESWorldSpace;

	// menuDepth = 3
	// flags = kPausesGame | kUsesCursor | kRendersOffscreenTargets | kCustomRendering
	// context = kMap
	class MapMenu :
		public IMenu,							  // 00000
		public BSTEventSink<MenuOpenCloseEvent>,  // 00030
		public IMapCameraCallbacks				  // 00038
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_MapMenu;
		constexpr static std::string_view MENU_NAME = "MapMenu";

		virtual ~MapMenu();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;						  // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		virtual void			   RefreshPlatform() override;											  // 08

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		// members
		BSTSmartPointer<MapMoveHandler> moveHandler;   // 00040
		BSTSmartPointer<MapLookHandler> lookHandler;   // 00048
		BSTSmartPointer<MapZoomHandler> zoomHandler;   // 00050
		std::uint64_t					unk00058;	   // 00058
		LocalMapMenu					localMapMenu;  // 00060
		RefHandle						unk30460;	   // 30460
		std::uint32_t					unk30464;	   // 30464
		std::uint32_t					unk30468;	   // 30468
		std::uint32_t					unk3046C;	   // 3046C
		BSTArray<void*>					unk30470;	   // 30470
		BSTArray<void*>					unk30488;	   // 30488
		MapCamera						camera;		   // 304A0
		std::uint64_t					unk30530;	   // 30530
		TESWorldSpace*					worldSpace;	   // 30538
		GFxValue						unk30540;	   // 30540
		std::uint64_t					unk30558;	   // 30558
		std::uint64_t					unk30560;	   // 30560
		std::uint64_t					unk30568;	   // 30568
		std::uint32_t					unk30570;	   // 30570
		BSSoundHandle					unk30574;	   // 30574
		std::uint64_t					unk30580;	   // 30580
		std::uint64_t					unk30588;	   // 30588
		std::uint64_t					unk30590;	   // 30590
	};
	static_assert(sizeof(MapMenu) == 0x30598);
}
