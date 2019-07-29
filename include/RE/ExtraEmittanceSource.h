#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEmittanceSource

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraEmittanceSource : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEmittanceSource;


		enum { kExtraTypeID = ExtraDataType::kEmittanceSource };


		virtual ~ExtraEmittanceSource();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEmittanceSource; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraEmittanceSource) == 0x18);
}
