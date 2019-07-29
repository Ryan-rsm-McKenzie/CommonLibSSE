#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWorn

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraWorn : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWorn;


		enum { kExtraTypeID = ExtraDataType::kWorn };


		virtual ~ExtraWorn();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kWorn; }
	};
	STATIC_ASSERT(sizeof(ExtraWorn) == 0x10);
}
