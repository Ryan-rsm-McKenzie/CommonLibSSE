#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraRank : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRank;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRank;


		ExtraRank();
		explicit ExtraRank(SInt32 a_rank);
		virtual ~ExtraRank() = default;	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kRank; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return rank != a_rhs->rank; }


		// members
		SInt32 rank;   // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraRank) == 0x18);
}
