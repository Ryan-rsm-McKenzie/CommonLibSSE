#pragma once

#include "skse64/GameEvents.h"  // BSTEventSink
#include "skse64/GameTypes.h"  // UnkArray


namespace RE
{
	class BGSSaveLoadManager
	{
	public:
		enum Event
		{
			kEvent_Autosave = 1 << 0,
			kEvent_Save = 1 << 1,
			kEvent_Unk02 = 1 << 2,
			kEvent_Unk03 = 1 << 3,
			kEvent_Unk04 = 1 << 4,

			kEvent_Unk07 = 1 << 7,
		};


		struct Data018
		{
			UnkArray	unk00;		// 00
			UnkArray	unk18;		// 18
			UnkArray	unk30;		// 30
			UInt64		unk48;		// 48
			UInt8		unk50;		// 50
			UInt8		pad51[7];	// 51
		};
		STATIC_ASSERT(sizeof(Data018) == 0x58);


		struct Data138
		{
			char		latestSaveFileName[0x104];	// 000
			UInt32		pad104;						// 104
			Data138*	unk108;						// 108 - Init'd as self ptr. Might has been intended as a ptr to the char[] instead
			UInt8		unk110;						// 110 - init'd to 0
			UInt8		unk111;						// 111 - init'd to 0
			UInt8		unk112;						// 112 - init'd to 4
			UInt8		unk113;						// 113 - init'd to 1
			UInt32		pad114;						// 114
		};
		STATIC_ASSERT(sizeof(Data138) == 0x118);


		class Thread
		{
		public:
			virtual ~Thread();

			virtual	UInt32	Unk01();
			virtual	void	SetEvent();	// Just calls Windows SetEvent on hEvent

			CRITICAL_SECTION	criticalSection;	// 08
			HANDLE				hThread;			// 30
			HANDLE				currentThread;		// 38
			DWORD				threadId;			// 40
			DWORD				currentThreadId;	// 44
			UInt8				unk48;				// 48
			UInt8				pad49[3];			// 49
			UInt8				unk50;				// 50 - init'd to 1
			UInt8				unk51;				// 51
			UInt16				pad52;				// 52
			UInt32				unk54;				// 54 - init'd to 1
			HANDLE				hEvent;				// 58
			UInt8				unk60[0x60];		// 60 - TODO:  .?AV?$BSTCommonStaticMessageQueue@V?$BSTSmartPointer@VRequest@saveload@bgs@@UBSTSmartPointerIntrusiveRefCount@@@@$07@@
		};
		STATIC_ASSERT(offsetof(Thread, hThread) == 0x30);
		STATIC_ASSERT(sizeof(Thread) == 0xC0);


		static BGSSaveLoadManager*	GetSingleton();


		// members
		BSTEventSink<void*>	unk000;					// 000 - .?AV?$BSTEventSink@VBSSaveDataEvent@@@@
		BSTEventSink<void*>	unk008;					// 008 - .?AV?$BSTEventSink@UNameChangedEvent@RaceSexMenuEvent@@@@
		void*				unk010;					// 010
		Data018				unk018;					// 018
		UInt32				unk070;					// 070
		UInt32				unk074;					// 074
		UInt32				unk078;					// 078
		UInt32				unk07C;					// 07C
		UInt32				unk080;					// 080
		UInt32				unk084;					// 084
		void*				unk088;					// 088
		UInt32				unk090;					// 090
		UInt32				unk094;					// 094
		void*				unk098;					// 098
		UInt32				unk0A0;					// 0A0
		UInt32				unk0A4;					// 0A4
		UInt32				unk0A8;					// 0A8
		UInt32				unk0AC;					// 0AC
		UInt32				unk0B0;					// 0B0
		UInt32				unk0B4;					// 0B4
		void*				unk0B8;					// 0B8
		UInt32				unk0C0;					// 0C0
		UInt32				unk0C4;					// 0C4
		UInt32				unk0C8;					// 0C8
		UInt32				unk0CC;					// 0CC
		UInt32				unk0D0;					// 0D0
		UInt32				unk0D4;					// 0D4
		UInt32				unk0D8;					// 0D8 - init'd to 0xFFFFFFFF
		UInt32				unk0DC;					// 0DC
		UInt32				unk0E0;					// 0E0
		UInt32				unk0E4;					// 0E4
		UnkArray			unk0E8;					// 0E8 - TODO: it is really a tArray of a structure of 0x48 bytes
		UnkArray			unk100;					// 100
		UInt8				unk118;					// 118
		UInt8				pad119[3];				// 119
		UInt32				unk11C;					// 11C
		UInt16				unk120;					// 120
		UInt16				pad122;					// 122
		UInt32				unk124;					// 124
		UInt64				startTickCount;			// 128 - GetTickCount when constructed, casted to 64 bits
		UInt8				unk130;					// 130 - init'd to 1
		UInt8				pad131[7];				// 131
		Data138				unk138;					// 138
		UInt32				unk250;					// 250 - init'd to FFFFFFFF   (unk28 in Skyrim32)
		bool				unk254;					// 254	(unk2C in Skyrim32)
		UInt8				pad255[3];				// 255
		void*				unk258;					// 258  (unk30 in Skyrim32)
		UInt8				unk260;					// 260 - init'd to 1  (unk34 in Skyrim32)
		UInt8				unk261;					// 261  (unk35 in Skyrim32)
		UInt8				pad262[2];				// 262
		UInt32				unk264;					// 264
		UInt32				unk268;					// 268
		UInt32				unk26C;					// 26C
		UInt8				unk270[0x2B0 - 0x270];	// 270
		Thread				thread;					// 2B0
		UInt8				unk370[0x60];			// 370 - TODO:  .?AV?$BSTCommonStaticMessageQueue@V?$BSTSmartPointer@VRequest@saveload@bgs@@UBSTSmartPointerIntrusiveRefCount@@@@$07@@
	};
	STATIC_ASSERT(offsetof(BGSSaveLoadManager, thread) == 0x2B0);
	STATIC_ASSERT(sizeof(BGSSaveLoadManager) == 0x3D0);
}
