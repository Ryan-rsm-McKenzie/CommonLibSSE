#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraHeadTrackingWeight : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHeadTrackingWeight;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHeadTrackingWeight;

		virtual ~ExtraHeadTrackingWeight();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kHeadTrackingWeight; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return weight != a_rhs->weight; }

		// members
		float		  weight;  // 10
		std::uint32_t pad14;   // 14
	};
	static_assert(sizeof(ExtraHeadTrackingWeight) == 0x18);
}
