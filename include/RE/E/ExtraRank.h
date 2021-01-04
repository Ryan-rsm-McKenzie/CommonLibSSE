#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraRank : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRank;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRank;

		ExtraRank();
		explicit ExtraRank(std::int32_t a_rank);
		virtual ~ExtraRank() = default;	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kRank; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return rank != a_rhs->rank; }

		// members
		std::int32_t  rank;	  // 10
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraRank) == 0x18);
}
