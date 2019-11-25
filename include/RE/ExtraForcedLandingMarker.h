#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraForcedLandingMarker : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraForcedLandingMarker;


		enum { kExtraTypeID = ExtraDataType::kForcedLandingMarker };


		virtual ~ExtraForcedLandingMarker();											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kForcedLandingMarker; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt32	unk10;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraForcedLandingMarker) == 0x18);
}
