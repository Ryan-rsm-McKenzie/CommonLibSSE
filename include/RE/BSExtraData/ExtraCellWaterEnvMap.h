#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/TESTexture.h"


namespace RE
{
	class ExtraCellWaterEnvMap : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellWaterEnvMap;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellWaterEnvMap;


		virtual ~ExtraCellWaterEnvMap();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCellWaterEnvMap; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		TESTexture waterEnvMap;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraCellWaterEnvMap) == 0x20);
}
