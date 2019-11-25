#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


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
