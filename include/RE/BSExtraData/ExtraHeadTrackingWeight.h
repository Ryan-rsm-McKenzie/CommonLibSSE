#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


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
		float  weight;	// 10
		UInt32 pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraHeadTrackingWeight) == 0x18);
}
