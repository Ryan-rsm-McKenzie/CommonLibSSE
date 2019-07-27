#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TES

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/ICellAttachDetachEventSource.h"  // ICellAttachDetachEventSource


namespace RE
{
	namespace BSResource
	{
		struct ArchiveStreamOpenedEvent;
	}


	class BSSystemEvent;
	struct PositionPlayerEvent;


	class TES :
		public ICellAttachDetachEventSource,						// 000
		public BSTEventSink<BSResource::ArchiveStreamOpenedEvent>,	// 060
		public BSTEventSink<PositionPlayerEvent>					// 068
	{
	public:
		inline static const void* RTTI = RTTI_TES;


		class SystemEventAdapter : public BSTEventSink<BSSystemEvent>
		{
		public:
			inline static const void* RTTI = RTTI_TES;


			virtual ~SystemEventAdapter();																						// 00

			// override (BSTEventSink<BSSystemEvent>)
			virtual	EventResult	ReceiveEvent(BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	// 01


			// members
			UInt64	unk08;	// 08
		};
		STATIC_ASSERT(sizeof(SystemEventAdapter) == 0x10);


		virtual ~TES();																																					// 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		virtual	EventResult	ReceiveEvent(BSResource::ArchiveStreamOpenedEvent* a_event, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* a_eventSource) override;	// 01 - { return kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual	EventResult	ReceiveEvent(PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;									// 01

		static TES* GetSingleton();


		// members
		UInt64				unk070;	// 070
		UInt64				unk078;	// 078
		UInt64				unk080;	// 080
		UInt64				unk088;	// 088
		UInt64				unk090;	// 090
		UInt64				unk098;	// 098
		UInt64				unk0A0;	// 0A0
		UInt64				unk0A8;	// 0A8
		UInt64				unk0B0;	// 0B0
		UInt64				unk0B8;	// 0B8
		UInt64				unk0C0;	// 0C0
		UInt64				unk0C8;	// 0C8
		UInt64				unk0D0;	// 0D0
		UInt64				unk0D8;	// 0D8
		UInt64				unk0E0;	// 0E0
		UInt64				unk0E8;	// 0E8
		UInt64				unk0F0;	// 0F0
		UInt64				unk0F8;	// 0F8
		UInt64				unk100;	// 100
		UInt64				unk108;	// 108
		UInt64				unk110;	// 110
		UInt64				unk118;	// 118
		UInt64				unk120;	// 120
		UInt64				unk128;	// 128
		UInt64				unk130;	// 130
		UInt64				unk138;	// 138
		UInt64				unk140;	// 140
		UInt64				unk148;	// 148
		UInt64				unk150;	// 150
		UInt64				unk158;	// 158
		UInt64				unk160;	// 160
		UInt64				unk168;	// 168
		UInt64				unk170;	// 170
		UInt64				unk178;	// 178
		UInt64				unk180;	// 180
		UInt64				unk188;	// 188
		UInt64				unk190;	// 190
		UInt64				unk198;	// 198
		UInt64				unk1A0;	// 1A0
		UInt64				unk1A8;	// 1A8
		UInt64				unk1B0;	// 1B0
		UInt64				unk1B8;	// 1B8
		UInt64				unk1C0;	// 1C0
		UInt64				unk1C8;	// 1C8
		UInt64				unk1D0;	// 1D0
		UInt64				unk1D8;	// 1D8
		UInt64				unk1E0;	// 1E0
		UInt64				unk1E8;	// 1E8
		UInt64				unk1F0;	// 1F0
		UInt64				unk1F8;	// 1F8
		UInt64				unk200;	// 200
		UInt64				unk208;	// 208
		UInt64				unk210;	// 210
		UInt64				unk218;	// 218
		UInt64				unk220;	// 220
		UInt64				unk228;	// 228
		UInt64				unk230;	// 230
		UInt64				unk238;	// 238
		UInt64				unk240;	// 240
		UInt64				unk248;	// 248
		UInt64				unk250;	// 250
		UInt64				unk258;	// 258
		UInt64				unk260;	// 260
		UInt64				unk268;	// 268
		UInt64				unk270;	// 270
		UInt64				unk278;	// 278
		UInt64				unk280;	// 280
		UInt64				unk288;	// 288
		SystemEventAdapter	unk290;	// 290
		UInt64				unk2A0;	// 2A0
		UInt64				unk2A8;	// 2A8
		UInt64				unk2B0;	// 2B0
	};
	STATIC_ASSERT(sizeof(TES) == 0x2B8);
}
