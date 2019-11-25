#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


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
