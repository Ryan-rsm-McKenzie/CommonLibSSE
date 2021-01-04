#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTArray.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraGuardedRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraGuardedRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kGuardedRefData;

		struct GuardInfo
		{
			FormID		  guard;  // 0
			std::uint32_t unk4;	  // 4
			std::uint32_t unk8;	  // 8
		};
		static_assert(sizeof(GuardInfo) == 0xC);

		virtual ~ExtraGuardedRefData();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kGuardedRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		BSTArray<GuardInfo> guards;	 // 10
	};
	static_assert(sizeof(ExtraGuardedRefData) == 0x28);
}
