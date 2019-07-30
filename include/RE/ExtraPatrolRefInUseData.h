#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPatrolRefInUseData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPatrolRefInUseData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPatrolRefInUseData;


		enum { kExtraTypeID = ExtraDataType::kPatrolRefInUseData };


		virtual ~ExtraPatrolRefInUseData();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { reutrn kPatrolRefInUseData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt32	unk10;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraPatrolRefInUseData) == 0x18);
}
