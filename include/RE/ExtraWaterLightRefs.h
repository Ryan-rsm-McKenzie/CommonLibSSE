#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWaterLightRefs

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraWaterLightRefs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWaterLightRefs;


		enum { kExtraTypeID = ExtraDataType::kWaterLightRefs };


		virtual ~ExtraWaterLightRefs();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kWaterLightRefs; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		BSSimpleList<UInt64> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraWaterLightRefs) == 0x20);
}
