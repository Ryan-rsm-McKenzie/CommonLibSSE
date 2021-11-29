#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESForm;

	struct ItemCrafted
	{
	public:
		struct Event
		{
		public:
			// members
			TESForm*      item;   // 00
			bool          unk08;  // 08 - weapon smithing/alchemy = true
			bool          unk09;  // 09 - enchanting = true
			bool          unk0A;  // 0A - weapon smithing = true/false
			std::uint8_t  pad0B;  // 0B
			std::uint32_t pad0C;  // 0C
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<ItemCrafted::Event>* GetEventSource();
	};
}
