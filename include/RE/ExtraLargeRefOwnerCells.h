#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLargeRefOwnerCells

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraLargeRefOwnerCells : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLargeRefOwnerCells;


		enum { kExtraTypeID = ExtraDataType::kLargeRefOwnerCells };


		virtual ~ExtraLargeRefOwnerCells();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kLargeRefOwnerCells; }


		// members
		BSTArray<void*>	unk10;	// 10
		UInt64			unk28;	// 28
	};
	STATIC_ASSERT(sizeof(ExtraLargeRefOwnerCells) == 0x30);
}
