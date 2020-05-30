#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraGuardedRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraGuardedRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kGuardedRefData;


		struct GuardInfo
		{
			FormID guard;  // 0
			UInt32 unk4;   // 4
			UInt32 unk8;   // 8
		};
		STATIC_ASSERT(sizeof(GuardInfo) == 0xC);


		virtual ~ExtraGuardedRefData();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kGuardedRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<GuardInfo> guards;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraGuardedRefData) == 0x28);
}
