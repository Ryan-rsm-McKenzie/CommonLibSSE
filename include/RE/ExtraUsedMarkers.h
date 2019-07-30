#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraUsedMarkers

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraUsedMarkers : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraUsedMarkers;


		enum { kExtraTypeID = ExtraDataType::kUsedMarkers };


		virtual ~ExtraUsedMarkers();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kUsedMarkers; }


		// members
		BSTArray<void*> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraUsedMarkers) == 0x28);
}
