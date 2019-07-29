#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRegionList

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRegionList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRegionList;


		enum { kExtraTypeID = ExtraDataType::kRegionList };


		virtual ~ExtraRegionList();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRegionList; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRegionList) == 0x18);
}
