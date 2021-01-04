#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class ExtraEnchantment : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEnchantment;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEnchantment;

		ExtraEnchantment();
		ExtraEnchantment(EnchantmentItem* a_enchantment, std::uint16_t a_charge, bool a_removeOnUnequip = false);
		virtual ~ExtraEnchantment() = default;	// 00

		// override(BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kEnchantment; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return enchantment != a_rhs->enchantment || charge != a_rhs->charge || removeOnUnequip != a_rhs->removeOnUnequip; }

		// members
		EnchantmentItem* enchantment;	   // 10
		std::uint16_t	 charge;		   // 18
		bool			 removeOnUnequip;  // 1A
		std::uint8_t	 pad1B;			   // 1B
		std::uint32_t	 pad1C;			   // 1C
	};
	static_assert(sizeof(ExtraEnchantment) == 0x20);
}
