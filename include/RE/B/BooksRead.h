#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectBOOK;

	struct BooksRead
	{
	public:
		struct Event
		{
		public:
			// members
			TESObjectBOOK* book;        // 00
			bool           unk08;       // 08
			std::uint8_t   pad11{ 0 };  // 09
			std::uint16_t  pad12{ 0 };  // 10
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<BooksRead::Event>* GetEventSource();
	};
}
