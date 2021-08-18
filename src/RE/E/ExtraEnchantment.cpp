#include "RE/E/ExtraEnchantment.h"

namespace RE
{
	ExtraEnchantment::ExtraEnchantment() :
		ExtraEnchantment(nullptr, 0)
	{}

	ExtraEnchantment::ExtraEnchantment(EnchantmentItem* a_enchantment, std::uint16_t a_charge, bool a_removeOnUnequip) :
		BSExtraData(),
		enchantment(a_enchantment),
		charge(a_charge),
		removeOnUnequip(a_removeOnUnequip),
		pad1B(0),
		pad1C(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ Offset::ExtraEnchantment::Vtbl };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}

	ExtraDataType ExtraEnchantment::GetType() const
	{
		return ExtraDataType::kEnchantment;
	}

	bool ExtraEnchantment::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraEnchantment*>(a_rhs);
		return enchantment != rhs->enchantment || charge != rhs->charge || removeOnUnequip != rhs->removeOnUnequip;
	}
}
