#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraNorthRotation

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraNorthRotation : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraNorthRotation;


		enum { kExtraTypeID = ExtraDataType::kNorthRotation };


		virtual ~ExtraNorthRotation();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kNorthRotation; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraNorthRotation) == 0x18);
}
