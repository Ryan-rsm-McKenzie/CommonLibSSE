#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraItemDropper

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraItemDropper : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraItemDropper;


		enum { kExtraTypeID = ExtraDataType::kItemDropper };


		virtual ~ExtraItemDropper();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kItemDropper; }


		// members
		RefHandle	refHandle;	// 10
		UInt32		pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraItemDropper) == 0x18);
}
