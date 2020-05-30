#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESCombatStyle;


	class ExtraCombatStyle : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCombatStyle;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCombatStyle;


		virtual ~ExtraCombatStyle();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kCombatStyle; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return combatStyle != a_rhs->combatStyle; }


		// members
		TESCombatStyle* combatStyle;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraCombatStyle) == 0x18);
}
