#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCharge

#include "RE/BSExtraData.h"


namespace RE
{
	class ExtraCharge : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCharge;


		enum { kExtraTypeID = ExtraDataType::kCharge };


		ExtraCharge();
		virtual ~ExtraCharge() = default;												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCharge; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return charge != a_rhs->charge; }


		// members
		float	charge;	// 10
		UInt32	unk14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraCharge) == 0x18);
}
