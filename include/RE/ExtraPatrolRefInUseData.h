#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


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
		UInt32 user;   // 10
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraPatrolRefInUseData) == 0x18);
}
