#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRaceData : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kRaceData };


		virtual ~ExtraRaceData();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRaceData; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRaceData) == 0x18);
}
