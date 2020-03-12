#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/MarkerUsedData.h"


namespace RE
{
	class ExtraReservedMarkers : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraReservedMarkers;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kReservedMarkers;


		virtual ~ExtraReservedMarkers();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kReservedMarkers; }


		// members
		BSTArray<MarkerUsedData> reservedMarkerArray;  // 10
		UInt64					 unk28;				   // 28
	};
	STATIC_ASSERT(sizeof(ExtraReservedMarkers) == 0x30);
}
