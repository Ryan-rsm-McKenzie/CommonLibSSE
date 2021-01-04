#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

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
		float		  cost;	  // 10
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraFavorCost) == 0x18);
}
