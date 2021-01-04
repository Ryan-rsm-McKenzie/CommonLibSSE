#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class ExtraCannotWear : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCannotWear;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCannotWear;

		ExtraCannotWear();
		virtual ~ExtraCannotWear() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kCannotWear; }
	};
	static_assert(sizeof(ExtraCannotWear) == 0x10);
}
