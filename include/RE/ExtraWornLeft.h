#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWornLeft

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraWornLeft : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWornLeft;


		enum { kExtraTypeID = ExtraDataType::kWornLeft };


		virtual ~ExtraWornLeft();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kWorn; }
	};
	STATIC_ASSERT(sizeof(ExtraWornLeft) == 0x10);
}
