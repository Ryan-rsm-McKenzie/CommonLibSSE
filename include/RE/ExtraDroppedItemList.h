#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList


namespace RE
{
	class ExtraDroppedItemList : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kDroppedItemList };


		virtual ~ExtraDroppedItemList();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 { return kDroppedItemList; }


		// members
		BSSimpleList<UInt32> handles;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraDroppedItemList) == 0x20);
}
