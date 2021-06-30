#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESCombatStyle;

	class ExtraCombatStyle : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCombatStyle;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCombatStyle;

		~ExtraCombatStyle() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kCombatStyle; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return combatStyle != a_rhs->combatStyle; }

		// members
		TESCombatStyle* combatStyle;  // 10
	};
	static_assert(sizeof(ExtraCombatStyle) == 0x18);
}
