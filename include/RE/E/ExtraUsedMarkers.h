#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Components/MarkerUsedData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraUsedMarkers : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraUsedMarkers;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kUsedMarkers;


		virtual ~ExtraUsedMarkers();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kUsedMarkers; }


		// members
		BSTArray<MarkerUsedData> usedMarkers;  // 10
	};
	static_assert(sizeof(ExtraUsedMarkers) == 0x28);
}
