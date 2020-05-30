#pragma once

#include "RE/BSTList.h"


namespace RE
{
	class TESRegion;


	class TESRegionList : public BSSimpleList<TESRegion*>
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESRegionList;


		virtual ~TESRegionList();  // 00


		// members
		bool   ownsRegionMemory;  // 18
		UInt8  pad19;			  // 19
		UInt16 pad1A;			  // 1A
		UInt32 pad1C;			  // 1C
	};
	STATIC_ASSERT(sizeof(TESRegionList) == 0x20);
}
