#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraReservedMarkers

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraReservedMarkers : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraReservedMarkers;


		enum { kExtraTypeID = ExtraDataType::kReservedMarkers };


		virtual ~ExtraReservedMarkers();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kReservedMarkers; }


		// members
		BSTArray<void*> unk10;	// 10
		UInt64			unk28;	// 28
	};
	STATIC_ASSERT(sizeof(ExtraReservedMarkers) == 0x30);
}
