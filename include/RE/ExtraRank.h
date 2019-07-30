#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRank

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRank : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRank;


		enum { kExtraTypeID = ExtraDataType::kRank };


		ExtraRank();
		ExtraRank(UInt32 a_rank);
		virtual ~ExtraRank() = default;													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kRank; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return rank != a_rhs->rank; }


		// members
		UInt32	rank;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraRank) == 0x18);
}
