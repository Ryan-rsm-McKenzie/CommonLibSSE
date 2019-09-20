#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Main

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTMessageQueue.h"  // BSTCommonScrapHeapMessageQueue
#include "RE/ScrapHeap.h"  // ScrapHeap


namespace RE
{
	class ScrapHeap;
	struct BSGamerProfileEvent;
	struct BSPackedTask;
	struct PositionPlayerEvent;


	class Main :
		public BSTEventSink<PositionPlayerEvent>,	// 00
		public BSTEventSink<BSGamerProfileEvent>	// 08
	{
	public:
		inline static const void* RTTI = RTTI_Main;


		struct Semaphore
		{
			HANDLE	handle;		// 00
			UInt32	size;		// 08
			UInt32	capacity;	// 0C
		};
		STATIC_ASSERT(sizeof(Semaphore) == 0x10);


		struct Data
		{
			UInt64	unk00;	// 00
			UInt32	unk08;	// 08
			UInt32	pad0C;	// 0C
			UInt64	unk10;	// 10
		};
		STATIC_ASSERT(sizeof(Data) == 0x18);


		virtual ~Main();																												// 00

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual	EventResult	ReceiveEvent(PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;	// 01 - { return EventResult::kContinue; }

		// override (BSTEventSink<BSGamerProfileEvent>)
		virtual	EventResult	ReceiveEvent(BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;	// 01


		// members
		bool											quitGame;	// 010
		UInt8											unk011;		// 011
		UInt16											unk012;		// 012
		UInt16											unk014;		// 014
		UInt8											unk016;		// 016
		UInt8											unk017;		// 017
		UInt64											unk018;		// 018
		UInt64											unk020;		// 020
		UInt32											threadID;	// 028
		UInt32											unk02C;		// 02C
		UInt64											unk030;		// 030
		ScrapHeap										unk038;		// 038
		BSTCommonScrapHeapMessageQueue<BSPackedTask>	unk0C8;		// 0C8
		mutable Semaphore								unk0F0;		// 0F0
		void*											unk100;		// 100 - functor
		ScrapHeap										unk108;		// 108
		BSTCommonScrapHeapMessageQueue<BSPackedTask>	unk198;		// 198
		mutable Semaphore								unk1C0;		// 1C0
		void*											unk1D0;		// 1D0 - functor
		UInt8											unk1D8;		// 1D8
		UInt8											unk1D9;		// 1D9
		UInt16											unk1DA;		// 1DA
		UInt32											unk1DC;		// 1DC
		Data											unk1E0[3];	// 1E0
		Data											unk228[3];	// 228
	};
	STATIC_ASSERT(sizeof(Main) == 0x270);
}
