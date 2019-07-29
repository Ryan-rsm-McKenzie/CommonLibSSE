#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLightData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraLightData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLightData;


		enum { kExtraTypeID = ExtraDataType::kLightData };


		virtual ~ExtraLightData();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLightData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt32	unk20;	// 20
		UInt32	pad24;	// 24
	};
	STATIC_ASSERT(sizeof(ExtraLightData) == 0x28);
}
