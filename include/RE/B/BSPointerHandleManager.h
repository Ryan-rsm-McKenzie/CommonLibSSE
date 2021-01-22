#pragma once

#include "RE/B/BSHandleRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	template <class T>
	class BSPointerHandleManager
	{
	public:
		struct Entry
		{
		public:
			enum EntryBitfieldConstants : std::uint32_t
			{
				//kAgeInc = (1 << T::kFreeListBits),	// 0x100000
				//kFreeListMask = kAgeInc - 1,	// 0xFFFFF
				//kInUseBit = kAgeInc << kAgeShift	// 0x4000000
			};

			// members
			std::uint32_t				 handleEntryBits;  // 00
			std::uint32_t				 pad04;			   // 04
			NiPointer<BSHandleRefObject> pointer;		   // 08
		};

		[[nodiscard]] static auto GetHandleEntries()
		{
			REL::Relocation<Entry(*)[0x100000]> entries{ REL::ID(514478) };
			return std::span<Entry, 0x100000>{ *entries };
		}
	};
}
