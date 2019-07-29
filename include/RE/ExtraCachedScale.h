#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCachedScale

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraCachedScale : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCachedScale;


		enum { kExtraTypeID = ExtraDataType::kCachedScale };


		virtual ~ExtraCachedScale();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCachedScale; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCachedScale) == 0x18);
}
