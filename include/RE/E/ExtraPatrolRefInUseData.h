#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraPatrolRefInUseData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPatrolRefInUseData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPatrolRefInUseData;

		virtual ~ExtraPatrolRefInUseData();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { reutrn kPatrolRefInUseData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return user != a_rhs->user; }

		// members
		std::uint32_t user;	  // 10
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraPatrolRefInUseData) == 0x18);
}
