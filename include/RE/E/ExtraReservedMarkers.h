#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTArray.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/M/MarkerUsedData.h"

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
		std::uint64_t			 unk28;				   // 28
	};
	static_assert(sizeof(ExtraReservedMarkers) == 0x30);
}
