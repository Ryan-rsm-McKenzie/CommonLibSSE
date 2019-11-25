#pragma once

#include "RE/BSTList.h"


namespace RE
{
	class TESRegion;


	class TESRegionList : public BSSimpleList<TESRegion*>
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionList;


		virtual ~TESRegionList();	// 00


		// members
		UInt64 unk18;	// 18
	};
	STATIC_ASSERT(sizeof(TESRegionList) == 0x20);
}
