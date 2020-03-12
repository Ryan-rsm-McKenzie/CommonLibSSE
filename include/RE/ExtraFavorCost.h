#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraFavorCost : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFavorCost;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFavorCost;


		virtual ~ExtraFavorCost();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kFavorCost; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return cost != a_rhs->cost; }


		// members
		float  cost;   // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraFavorCost) == 0x18);
}
