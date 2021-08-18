#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraScale : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraScale;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kScale;

		~ExtraScale() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kScale; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return scale != a_rhs->scale; }

		// members
		float         scale;  // 10
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraScale) == 0x18);
}
