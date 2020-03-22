#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTMessageQueue.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSThread.h"
#include "RE/RaceSexMenuEvent.h"
#include "RE/bgs/saveload/Request.h"


namespace RE
{
	class BSSaveDataEvent;
	class BSSystemEvent;
	struct BGSSaveLoadManagerEvent;


	class BGSSaveLoadFileEntry
	{
	public:
		// members
		BSFixedString fileName;		// 00
		BSFixedString playerName;	// 08
		BSFixedString playerTitle;	// 10
		BSFixedString location;		// 18
		BSFixedString playTime;		// 20
		BSFixedString raceName;		// 28
		UInt32		  unk30;		// 30
		UInt32		  unk34;		// 34
		UInt32		  unk38;		// 38
		UInt32		  unk3C;		// 3C
		UInt32		  unk40;		// 40
		UInt32		  unk44;		// 44
		UInt64		  unk48;		// 48
		UInt64		  unk50;		// 50
		UInt64		  unk58;		// 58
		UInt64		  unk60;		// 60
		UInt64		  unk68;		// 68
		UInt64		  unk70;		// 70
	};
	STATIC_ASSERT(sizeof(BGSSaveLoadFileEntry) == 0x78);


	class BGSSaveLoadManager :
		public BSTEventSink<BSSaveDataEvent>,					  // 000
		public BSTEventSink<RaceSexMenuEvent::NameChangedEvent>,  // 008
		public BSTEventSource<BGSSaveLoadManagerEvent>,			  // 018
		public BSTEventSink<BSSystemEvent>						  // 010
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSaveLoadManager;


		class Thread : public BSThread
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSSaveLoadManager__Thread;


			virtual ~Thread();	// 00

			virtual void Unk_01(void) override;	 // 01
			virtual void Unk_02(void) override;	 // 02


			// members
			bool																	isRunnning;					  // 50
			bool																	isBusy;						  // 51
			UInt16																	pad52;						  // 52
			UInt32																	pad54;						  // 54
			BSEventFlag																haveTask;					  // 58
			BSTCommonStaticMessageQueue<BSTSmartPointer<bgs::saveload::Request>, 8> asyncSaveLoadOperationQueue;  // 60
		};
		STATIC_ASSERT(sizeof(Thread) == 0xC0);


		virtual ~BGSSaveLoadManager();	// 00

		// override (BSTEventSink<BSSaveDataEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<RaceSexMenuEvent::NameChangedEvent>)
		virtual BSEventNotifyControl ProcessEvent(const RaceSexMenuEvent::NameChangedEvent* a_event, BSTEventSource<RaceSexMenuEvent::NameChangedEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BSSystemEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01


		static BGSSaveLoadManager* GetSingleton();

		void Save(const char* a_fileName);
		void Load(const char* a_fileName);


		// members
		UInt64			unk070;	 // 070
		UInt32			unk078;	 // 078
		UInt32			unk07C;	 // 07C
		UInt32			unk080;	 // 080
		UInt32			unk084;	 // 084
		UInt64			unk088;	 // 088
		UInt64			unk090;	 // 090
		UInt64			unk098;	 // 098
		UInt64			unk0A0;	 // 0A0
		UInt32			unk0A8;	 // 0A8
		UInt32			unk0AC;	 // 0AC
		UInt32			unk0B0;	 // 0B0
		UInt32			unk0B4;	 // 0B4
		UInt64			unk0B8;	 // 0B8
		UInt64			unk0C0;	 // 0C0
		UInt64			unk0C8;	 // 0C8
		UInt64			unk0D0;	 // 0D0
		UInt32			unk0D8;	 // 0D8
		UInt32			unk0DC;	 // 0DC
		UInt32			unk0E0;	 // 0E0
		UInt32			unk0E4;	 // 0E4
		BSTArray<void*> unk0E8;	 // 0E8

		BSTArray<BGSSaveLoadFileEntry*> saveGameList;  // 100
		UInt8							unk118;		   // 118
		UInt8							unk119;		   // 119
		UInt16							unk11A;		   // 11A
		UInt32							unk11C;		   // 11C
		UInt16							unk120;		   // 120
		UInt16							unk122;		   // 122
		UInt32							unk124;		   // 124
		UInt32							tickCount;	   // 128
		UInt32							unk12C;		   // 12C
		UInt8							unk130;		   // 130
		UInt8							unk131;		   // 131
		UInt16							unk132;		   // 132
		UInt32							unk134;		   // 134
		UInt64							unk138;		   // 138
		UInt64							unk140;		   // 140
		UInt64							unk148;		   // 148
		UInt64							unk150;		   // 150
		UInt64							unk158;		   // 158
		UInt64							unk160;		   // 160
		UInt64							unk168;		   // 168
		UInt64							unk170;		   // 170
		UInt64							unk178;		   // 178
		UInt64							unk180;		   // 180
		UInt64							unk188;		   // 188
		UInt64							unk190;		   // 190
		UInt64							unk198;		   // 198
		UInt64							unk1A0;		   // 1A0
		UInt64							unk1A8;		   // 1A8
		UInt64							unk1B0;		   // 1B0
		UInt64							unk1B8;		   // 1B8
		UInt64							unk1C0;		   // 1C0
		UInt64							unk1C8;		   // 1C8
		UInt64							unk1D0;		   // 1D0
		UInt64							unk1D8;		   // 1D8
		UInt64							unk1E0;		   // 1E0
		UInt64							unk1E8;		   // 1E8
		UInt64							unk1F0;		   // 1F0
		UInt64							unk1F8;		   // 1F8

		UInt64 unk200;	// 200
		UInt64 unk208;	// 208
		UInt64 unk210;	// 210
		UInt64 unk218;	// 218
		UInt64 unk220;	// 220
		UInt64 unk228;	// 228
		UInt64 unk230;	// 230
		UInt64 unk238;	// 238
		UInt64 unk240;	// 240
		UInt64 unk248;	// 248
		UInt32 unk250;	// 250
		UInt32 unk254;	// 254
		UInt64 unk258;	// 258
		UInt16 unk260;	// 260
		UInt16 unk262;	// 262
		UInt32 unk264;	// 264
		UInt64 unk268;	// 268
		UInt32 unk270;	// 270
		UInt32 unk274;	// 274
		UInt64 unk278;	// 278
		UInt64 unk280;	// 280
		UInt32 unk288;	// 288
		UInt32 unk28C;	// 28C
		UInt64 unk290;	// 290
		UInt64 unk298;	// 298
		UInt32 unk2A0;	// 2A0
		UInt32 unk2A4;	// 2A4
		UInt64 unk2A8;	// 2A8
		Thread unk2B0;	// 2B0

		BSTCommonStaticMessageQueue<BSTSmartPointer<bgs::saveload::Request>, 8> unk370;	 // 370

	protected:
		bool Save_Impl(SInt32 a_deviceID, UInt32 a_outputStats, const char* a_fileName);
		bool Load_Impl(const char* a_fileName, SInt32 a_deviceID, UInt32 a_outputStats, bool a_checkForMods);
	};
	STATIC_ASSERT(sizeof(BGSSaveLoadManager) == 0x3D0);
}
