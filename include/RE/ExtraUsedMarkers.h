#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/MarkerUsedData.h"


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
	STATIC_ASSERT(sizeof(ExtraUsedMarkers) == 0x28);
}
