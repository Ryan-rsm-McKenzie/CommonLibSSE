#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraProcessMiddleLow

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraProcessMiddleLow : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraProcessMiddleLow;


		enum { kExtraTypeID = ExtraDataType::kProcessMiddleLow };


		virtual ~ExtraProcessMiddleLow();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kProcessMiddleLow; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraProcessMiddleLow) == 0x18);
}
