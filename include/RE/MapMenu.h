#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MapMenu

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/IMapCameraCallbacks.h"  // IMapCameraCallbacks
#include "RE/IMenu.h"  // IMenu
#include "RE/LocalMapMenu.h"  // LocalMapMenu
#include "RE/MapCamera.h"  // MapCamera


namespace RE
{
	class MapLookHandler;
	class MapMoveHandler;
	class MapZoomHandler;
	class TESWorldSpace;


	class MapMenu :
		public IMenu,									// 00000
		public BSTEventSink<class MenuOpenCloseEvent>,	// 00030
		public IMapCameraCallbacks						// 00038
	{
	public:
		inline static const void* RTTI = RTTI_MapMenu;


		virtual ~MapMenu();																											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;															// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;																// 04
		virtual void	NextFrame(float a_arg1, UInt32 a_currentTime) override;														// 05
		virtual void	InitMovie() override;																						// 08

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual	EventResult	ReceiveEvent(MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;	// 01


		// members
		MapMoveHandler*	moveHandler;	// 00040
		MapLookHandler*	lookHandler;	// 00048
		MapZoomHandler*	zoomHandler;	// 00050
		UInt64			unk00058;		// 00058
		LocalMapMenu	localMapMenu;	// 00060
		UInt64			unk30460;		// 30460
		UInt64			unk30468;		// 30468
		UInt64			unk30470;		// 30470
		UInt64			unk30478;		// 30478
		UInt64			unk30480;		// 30480
		UInt64			unk30488;		// 30488
		UInt64			unk30490;		// 30490
		UInt64			unk30498;		// 30498
		MapCamera		camera;			// 304A0
		UInt64			unk30530;		// 30530
		TESWorldSpace*	worldSpace;		// 30538
		UInt64			unk30540;		// 30540
		UInt64			unk30548;		// 30548
		UInt64			unk30550;		// 30550
		UInt64			unk30558;		// 30558
		UInt64			unk30560;		// 30560
		UInt64			unk30568;		// 30568
		UInt64			unk30570;		// 30570
		UInt64			unk30578;		// 30578
		UInt64			unk30580;		// 30580
		UInt64			unk30588;		// 30588
		UInt64			unk30590;		// 30590
	};
	STATIC_ASSERT(sizeof(MapMenu) == 0x30598);
}
