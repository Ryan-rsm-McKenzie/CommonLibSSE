#pragma once

#include "RE/BSCore/BSTEvent.h"
#include "RE/FileIO/ICellAttachDetachEventSource/ICellAttachDetachEventSource.h"


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
		inline static constexpr auto RTTI = RTTI_TES;


		class SystemEventAdapter : public BSTEventSink<BSSystemEvent>
		{
		public:
			inline static constexpr auto RTTI = RTTI_TES;


			virtual ~SystemEventAdapter();	// 00

			// override (BSTEventSink<BSSystemEvent>)
			virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01


			// members
			std::uint64_t unk08;  // 08
		};
		static_assert(sizeof(SystemEventAdapter) == 0x10);


		virtual ~TES();	 // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSResource::ArchiveStreamOpenedEvent* a_event, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;	 // 01

		static TES* GetSingleton();


		// members
		std::uint64_t	   unk070;	// 070
		std::uint64_t	   unk078;	// 078
		std::uint64_t	   unk080;	// 080
		std::uint64_t	   unk088;	// 088
		std::uint64_t	   unk090;	// 090
		std::uint64_t	   unk098;	// 098
		std::uint64_t	   unk0A0;	// 0A0
		std::uint64_t	   unk0A8;	// 0A8
		std::uint64_t	   unk0B0;	// 0B0
		std::uint64_t	   unk0B8;	// 0B8
		std::uint64_t	   unk0C0;	// 0C0
		void*			   unk0C8;	// 0C8
		void*			   unk0D0;	// 0D0
		std::uint64_t	   unk0D8;	// 0D8
		std::uint64_t	   unk0E0;	// 0E0
		std::uint64_t	   unk0E8;	// 0E8
		std::uint64_t	   unk0F0;	// 0F0
		std::uint64_t	   unk0F8;	// 0F8
		std::uint64_t	   unk100;	// 100
		std::uint64_t	   unk108;	// 108
		std::uint64_t	   unk110;	// 110
		std::uint64_t	   unk118;	// 118
		std::uint64_t	   unk120;	// 120
		std::uint64_t	   unk128;	// 128
		std::uint64_t	   unk130;	// 130
		std::uint64_t	   unk138;	// 138
		std::uint64_t	   unk140;	// 140
		std::uint64_t	   unk148;	// 148
		void*			   unk150;	// 150 - smart ptr
		void*			   unk158;	// 158 - smart ptr
		void*			   unk160;	// 160 - smart ptr
		void*			   unk168;	// 168 - smart ptr
		void*			   unk170;	// 170 - smart ptr
		std::uint64_t	   unk178;	// 178
		std::uint64_t	   unk180;	// 180
		std::uint64_t	   unk188;	// 188
		std::uint64_t	   unk190;	// 190
		std::uint64_t	   unk198;	// 198
		std::uint64_t	   unk1A0;	// 1A0
		std::uint64_t	   unk1A8;	// 1A8
		std::uint64_t	   unk1B0;	// 1B0
		std::uint64_t	   unk1B8;	// 1B8
		std::uint64_t	   unk1C0;	// 1C0
		std::uint64_t	   unk1C8;	// 1C8
		std::uint64_t	   unk1D0;	// 1D0
		std::uint64_t	   unk1D8;	// 1D8
		std::uint64_t	   unk1E0;	// 1E0
		std::uint64_t	   unk1E8;	// 1E8
		std::uint64_t	   unk1F0;	// 1F0
		std::uint64_t	   unk1F8;	// 1F8
		std::uint64_t	   unk200;	// 200
		std::uint64_t	   unk208;	// 208
		std::uint64_t	   unk210;	// 210
		std::uint64_t	   unk218;	// 218
		std::uint64_t	   unk220;	// 220
		std::uint64_t	   unk228;	// 228
		std::uint64_t	   unk230;	// 230
		std::uint64_t	   unk238;	// 238
		std::uint64_t	   unk240;	// 240
		std::uint64_t	   unk248;	// 248
		std::uint64_t	   unk250;	// 250
		std::uint64_t	   unk258;	// 258
		std::uint64_t	   unk260;	// 260
		std::uint64_t	   unk268;	// 268
		std::uint64_t	   unk270;	// 270
		std::uint64_t	   unk278;	// 278
		std::uint64_t	   unk280;	// 280
		std::uint64_t	   unk288;	// 288
		SystemEventAdapter unk290;	// 290
		std::uint64_t	   unk2A0;	// 2A0
		std::uint64_t	   unk2A8;	// 2A8
		std::uint64_t	   unk2B0;	// 2B0
	};
	static_assert(sizeof(TES) == 0x2B8);
}
