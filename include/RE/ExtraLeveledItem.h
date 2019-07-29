#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLeveledItem

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraLeveledItem : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLeveledItem;


		enum { kExtraTypeID = ExtraDataType::kLeveledItem };


		virtual ~ExtraLeveledItem();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kLeveledItem; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLeveledItem) == 0x18);
}
