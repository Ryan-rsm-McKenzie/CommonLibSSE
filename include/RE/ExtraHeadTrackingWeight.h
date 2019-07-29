#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHeadTrackingWeight

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHeadTrackingWeight : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHeadTrackingWeight;


		enum { kExtraTypeID = ExtraDataType::kHeadTrackingWeight };


		virtual ~ExtraHeadTrackingWeight();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kHeadTrackingWeight; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		float	unk10;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraHeadTrackingWeight) == 0x18);
}
