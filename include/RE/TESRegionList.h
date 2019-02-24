#pragma once

#include "RE/BSTList.h"  // BSSimpleList


namespace RE
{
	class TESRegion;


	class TESRegionList : public BSSimpleList<TESRegion*>
	{
	public:
		virtual ~TESRegionList();	// 00


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(TESRegionList) == 0x20);
}
