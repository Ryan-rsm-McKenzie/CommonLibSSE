#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTList.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraDroppedItemList : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraDroppedItemList;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kDroppedItemList;


		virtual ~ExtraDroppedItemList();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 { return kDroppedItemList; }


		// members
		BSSimpleList<ObjectRefHandle> droppedItemList;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraDroppedItemList) == 0x20);
}
