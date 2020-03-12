#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraLeveledItem : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLeveledItem;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLeveledItem;


		virtual ~ExtraLeveledItem();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kLeveledItem; }


		// members
		FormID levItem;	 // 10
		UInt32 pad14;	 // 14
	};
	STATIC_ASSERT(sizeof(ExtraLeveledItem) == 0x18);
}
