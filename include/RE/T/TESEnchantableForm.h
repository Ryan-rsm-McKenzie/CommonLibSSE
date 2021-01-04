#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/M/MagicSystem.h"

namespace RE
{
	class EnchantmentItem;

	class TESEnchantableForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESEnchantableForm;

		virtual ~TESEnchantableForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual MagicSystem::CastingType GetCastingType() const;  // 04 - { return castingType; }

		// members
		EnchantmentItem*										  formEnchanting;		// 08 - EITM
		stl::enumeration<MagicSystem::CastingType, std::uint16_t> castingType;			// 10
		std::uint16_t											  amountofEnchantment;	// 12 - EAMT
		std::uint32_t											  pad14;				// 14
	};
	static_assert(sizeof(TESEnchantableForm) == 0x18);
}
