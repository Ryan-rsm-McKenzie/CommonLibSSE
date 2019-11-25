#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraDroppedItemList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraDroppedItemList;


		enum { kExtraTypeID = ExtraDataType::kDroppedItemList };


		virtual ~ExtraDroppedItemList();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 { return kDroppedItemList; }


		// members
		BSSimpleList<RefHandle> handles;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraDroppedItemList) == 0x20);
}
