#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWaterCurrentZoneData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraWaterCurrentZoneData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWaterCurrentZoneData;


		enum { kExtraTypeID = ExtraDataType::kWaterCurrentZoneData };


		virtual ~ExtraWaterCurrentZoneData();											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kWaterCurrentZoneData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		float	unk50;	// 50
		float	unk54;	// 54
		float	unk58;	// 58
		float	unk5C;	// 5C
		float	unk60;	// 60
		float	unk64;	// 64
	};
	STATIC_ASSERT(sizeof(ExtraWaterCurrentZoneData) == 0x68);
}
