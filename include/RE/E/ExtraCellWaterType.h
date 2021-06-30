#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESWaterForm;

	class ExtraCellWaterType : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellWaterType;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellWaterType;

		~ExtraCellWaterType() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kCellWaterType; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return water != a_rhs->water; }

		// members
		TESWaterForm* water;  // 10
	};
	static_assert(sizeof(ExtraCellWaterType) == 0x18);
}
