#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraModelSwap

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraModelSwap : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraModelSwap;


		enum { kExtraTypeID = ExtraDataType::kModelSwap };


		virtual ~ExtraModelSwap();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kModelSwap; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraModelSwap) == 0x20);
}
