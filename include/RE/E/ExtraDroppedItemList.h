#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataTypes.h"

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
	static_assert(sizeof(ExtraDroppedItemList) == 0x20);
}
