#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Components/MarkerUsedData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


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
