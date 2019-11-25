#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


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
