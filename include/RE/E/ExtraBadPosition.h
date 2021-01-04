#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraBadPosition : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraBadPosition;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kBadPosition;

		virtual ~ExtraBadPosition();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kBadPosition; }
	};
	static_assert(sizeof(ExtraBadPosition) == 0x10);
}
