#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTMessageQueue.h"
#include "RE/ScrapHeap.h"


namespace RE
{
	class ScrapHeap;
	struct BSGamerProfileEvent;
	struct BSPackedTask;
	struct PositionPlayerEvent;


	struct BSPackedTaskQueue
	{
	public:
		using UnpackFunc_t = void(const BSPackedTask*);


		struct Semaphore
		{
		public:
			// members
			HANDLE handle;	  // 00
			UInt32 size;	  // 08
			UInt32 capacity;  // 0C
		};
		STATIC_ASSERT(sizeof(Semaphore) == 0x10);


		// members
		BSTCommonScrapHeapMessageQueue<BSPackedTask> queue;		  // 00
		mutable Semaphore							 semaphore;	  // 28
		UnpackFunc_t*								 unpackFunc;  // 38
	};
	STATIC_ASSERT(sizeof(BSPackedTaskQueue) == 0x40);


	struct BSSaveDataSystemUtilityImage
	{
	public:
		// members
		UInt32 size;	// 00
		UInt32 width;	// 04
		UInt32 height;	// 08
		UInt32 pad0C;	// 0C
		char*  buffer;	// 10
	};
	STATIC_ASSERT(sizeof(BSSaveDataSystemUtilityImage) == 0x18);


	class Main :
		public BSTEventSink<PositionPlayerEvent>,  // 00
		public BSTEventSink<BSGamerProfileEvent>   // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_Main;


		virtual ~Main();  // 00

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;	 // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<BSGamerProfileEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;	 // 01

		static Main* GetSingleton();


		// members
		bool						 quitGame;					   // 010
		bool						 resetGame;					   // 011
		bool						 fullReset;					   // 012
		bool						 gameActive;				   // 013
		bool						 onIdle;					   // 014
		bool						 reloadContent;				   // 015
		bool						 freezeTime;				   // 016
		bool						 freezeNextFrame;			   // 017
		HWND						 wnd;						   // 018
		HINSTANCE					 instance;					   // 020
		UInt32						 threadID;					   // 028
		UInt32						 unk02C;					   // 02C
		UInt64						 unk030;					   // 030
		ScrapHeap					 packedTaskHeap;			   // 038
		BSPackedTaskQueue			 taskQueue;					   // 0C8
		ScrapHeap					 secondaryPackedTaskHeap;	   // 108
		BSPackedTaskQueue			 secondaryTaskQueue;		   // 198
		UInt8						 unk1D8;					   // 1D8
		UInt8						 unk1D9;					   // 1D9
		UInt16						 unk1DA;					   // 1DA
		UInt32						 unk1DC;					   // 1DC
		BSSaveDataSystemUtilityImage saveDataBackgroundImages[3];  // 1E0
		BSSaveDataSystemUtilityImage saveDataIconImages[3];		   // 228
	};
	STATIC_ASSERT(sizeof(Main) == 0x270);
}
