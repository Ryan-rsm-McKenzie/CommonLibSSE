#pragma once

#include "skse64/ScaleformValue.h"  // GFxValue


namespace RE
{
	class InventoryEntryData;


	class StandardItemData
	{
	public:
		virtual ~StandardItemData();

		virtual const char*	GetName();
		virtual UInt32		GetCount();
		virtual UInt32		GetEquipState();
		virtual UInt32		GetFilterFlag();
		virtual UInt32		GetFavorite();
		virtual bool		GetEnabled();


		// members
		InventoryEntryData*	objDesc;	// 08
		UInt32				refHandle;	// 10
		UInt32				pad14;		// 14
	};
	STATIC_ASSERT(sizeof(StandardItemData) == 0x18);
}
