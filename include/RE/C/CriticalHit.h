#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectREFR;
	class TESObjectWEAP;

	struct CriticalHit
	{
	public:
		struct Event
		{
		public:
			// members
			TESObjectREFR* aggressor;   // 00
			TESObjectWEAP* weapon;      // 08
			bool           sneakHit;    // 10
			std::uint8_t   pad11{ 0 };  // 11
			std::uint16_t  pad12{ 0 };  // 12
			std::uint32_t  pad14{ 0 };  // 14
		};
		static_assert(sizeof(Event) == 0x18);

		static BSTEventSource<CriticalHit::Event>* GetEventSource();
	};
}
