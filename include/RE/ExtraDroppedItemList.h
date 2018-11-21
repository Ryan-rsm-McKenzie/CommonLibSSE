#pragma once

#include "skse64/GameBSExtraData.h"  // BSExtraData

#include "BSTList.h"


namespace RE
{
	class ExtraDroppedItemList : public BSExtraData
	{
	public:
		enum { kExtraTypeID = kExtraData_DroppedItemList };

		virtual ~ExtraDroppedItemList();		// 0

		// override (BSExtraData)
		virtual UInt32	GetType(void) override;	// 1 { return kExtraTypeID; }

		// members
		BSSimpleList<UInt32> handles;	// 10
	};
}
