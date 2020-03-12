#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESWaterForm;


	class ExtraCellWaterType : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellWaterType;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellWaterType;


		virtual ~ExtraCellWaterType();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCellWaterType; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return water != a_rhs->water; }


		// members
		TESWaterForm* water;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraCellWaterType) == 0x18);
}
