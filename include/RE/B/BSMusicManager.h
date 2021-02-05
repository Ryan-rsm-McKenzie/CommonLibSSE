#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BSIMusicType;
	struct BSMusicEvent;

	class BSMusicManager :
		public BSTSingletonSDM<BSMusicManager>,	 // 00
		public BSTEventSink<BSMusicEvent>		 // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMusicManager;

		virtual ~BSMusicManager();	// 00

		// override (BSTEventSink<BSMusicEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSMusicEvent* a_event, BSTEventSource<BSMusicEvent>* a_eventSource);  // 01

		static BSMusicManager* GetSingleton()
		{
			REL::Relocation<BSMusicManager**> singleton{ REL::ID(514738) };
			return *singleton;
		}

		// members
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
		BSIMusicType* unk28;  // 28
		std::uint32_t unk30;  // 30
		std::uint32_t unk34;  // 34
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
	};
	static_assert(sizeof(BSMusicManager) == 0x48);
}
