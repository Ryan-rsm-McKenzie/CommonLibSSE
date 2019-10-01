#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MapMenu

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMapCameraCallbacks.h"  // IMapCameraCallbacks
#include "RE/IMenu.h"  // IMenu
#include "RE/LocalMapMenu.h"  // LocalMapMenu
#include "RE/MapCamera.h"  // MapCamera
#include "RE/SoundData.h"  // SoundData


namespace RE
{
	class BSAudioManager;
	class MapLookHandler;
	class MapMoveHandler;
	class MapZoomHandler;
	class MenuOpenCloseEvent;
	class TESWorldSpace;


	class MapMenu :
		public IMenu,								// 00000
		public BSTEventSink<MenuOpenCloseEvent>,	// 00030
		public IMapCameraCallbacks					// 00038
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
		BSTSmartPointer<MapMoveHandler>	moveHandler;	// 00040
		BSTSmartPointer<MapLookHandler>	lookHandler;	// 00048
		BSTSmartPointer<MapZoomHandler>	zoomHandler;	// 00050
		UInt64							unk00058;		// 00058
		LocalMapMenu					localMapMenu;	// 00060
		RefHandle						unk30460;		// 30460
		UInt32							unk30464;		// 30464
		UInt32							unk30468;		// 30468
		UInt32							unk3046C;		// 3046C
		BSTArray<void*>					unk30470;		// 30470
		BSTArray<void*>					unk30488;		// 30488
		MapCamera						camera;			// 304A0
		UInt64							unk30530;		// 30530
		TESWorldSpace*					worldSpace;		// 30538
		GFxValue						unk30540;		// 30540
		UInt64							unk30558;		// 30558
		UInt64							unk30560;		// 30560
		UInt64							unk30568;		// 30568
		UInt32							unk30570;		// 30570
		SoundData						unk30574;		// 30574
		UInt64							unk30580;		// 30580
		UInt64							unk30588;		// 30588
		UInt64							unk30590;		// 30590
	};
	STATIC_ASSERT(sizeof(MapMenu) == 0x30598);
}
