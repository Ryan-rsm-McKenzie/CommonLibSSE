#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class TESRegion;

	class TESRegionList : public BSSimpleList<TESRegion*>
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegionList;
		inline static constexpr auto VTABLE = VTABLE_TESRegionList;

		virtual ~TESRegionList();  // 00

		// members
		bool          ownsRegionMemory;  // 18
		std::uint8_t  pad19;             // 19
		std::uint16_t pad1A;             // 1A
		std::uint32_t pad1C;             // 1C
	};
	static_assert(sizeof(TESRegionList) == 0x20);
}
