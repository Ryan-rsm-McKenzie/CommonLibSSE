#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraGIDBuffer

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraGIDBuffer : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraGIDBuffer;


		enum { kExtraTypeID = ExtraDataType::kGIDBuffer };


		virtual ~ExtraGIDBuffer();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kGIDBuffer; }


		// members
		UInt8* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGIDBuffer) == 0x18);
}
