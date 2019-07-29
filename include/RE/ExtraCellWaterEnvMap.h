#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCellWaterEnvMap

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/TESIcon.h"  // TESIcon


namespace RE
{
	class ExtraCellWaterEnvMap : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCellWaterEnvMap;


		enum { kExtraTypeID = ExtraDataType::kCellWaterEnvMap };


		virtual ~ExtraCellWaterEnvMap();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCellWaterEnvMap; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		TESIcon	unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCellWaterEnvMap) == 0x20);
}
