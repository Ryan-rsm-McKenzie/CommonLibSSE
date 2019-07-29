#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRefractionProperty

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRefractionProperty : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRefractionProperty;


		enum { kExtraTypeID = ExtraDataType::kRefractionProperty };


		virtual ~ExtraRefractionProperty();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRefractionProperty; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRefractionProperty) == 0x18);
}
