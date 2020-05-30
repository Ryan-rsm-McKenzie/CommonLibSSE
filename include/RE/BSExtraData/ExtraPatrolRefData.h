#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct PatrolRefData
	{
		UInt64 unk00;  // 00
		UInt64 unk08;  // 08
		UInt64 unk10;  // 10
		UInt64 unk18;  // 18
		UInt64 unk20;  // 20
	};
	STATIC_ASSERT(sizeof(PatrolRefData) == 0x28);


	class ExtraPatrolRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPatrolRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPatrolRefData;


		virtual ~ExtraPatrolRefData();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kPatrolRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		PatrolRefData* patrolData;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPatrolRefData) == 0x18);
}
