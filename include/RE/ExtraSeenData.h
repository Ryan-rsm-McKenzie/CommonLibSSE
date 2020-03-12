#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class SeenData;


	class ExtraSeenData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSeenData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSeenData;


		virtual ~ExtraSeenData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kSeenData; }


		// members
		SeenData* seenData;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraSeenData) == 0x18);
}
