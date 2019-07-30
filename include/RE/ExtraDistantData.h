#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraDistantData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraDistantData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraDistantData;


		enum { kExtraTypeID = ExtraDataType::kDistantData };


		virtual ~ExtraDistantData();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kDistantData; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraDistantData) == 0x20);
}
