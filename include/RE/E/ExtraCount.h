#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraCount : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCount;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCount;

		ExtraCount();
		explicit ExtraCount(std::int16_t a_count);
		virtual ~ExtraCount() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCount; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return return count != a_rhs->count; }

		// members
		std::int16_t  count;  // 10
		std::uint16_t pad12;  // 12
		std::int32_t  pad14;  // 14
	};
	static_assert(sizeof(ExtraCount) == 0x18);
}
