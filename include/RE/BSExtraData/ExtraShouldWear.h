#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraShouldWear : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraShouldWear;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kShouldWear;


		virtual ~ExtraShouldWear();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kShouldWear; }


		// members
		UInt64 unk10;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraShouldWear) == 0x18);
}
