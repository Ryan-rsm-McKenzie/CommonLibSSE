#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

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
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(ExtraShouldWear) == 0x18);
}
