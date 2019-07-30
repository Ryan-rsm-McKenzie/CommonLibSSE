#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraShouldWear

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraShouldWear : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraShouldWear;


		enum { kExtraTypeID = ExtraDataType::kShouldWear };


		virtual ~ExtraShouldWear();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kShouldWear; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraShouldWear) == 0x18);
}
