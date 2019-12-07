#include "RE/ExtraEnchantment.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraEnchantment::ExtraEnchantment() :
		ExtraEnchantment(0, 0)
	{}


	ExtraEnchantment::ExtraEnchantment(EnchantmentItem* a_objectEffect, UInt16 a_enchantmentAmount) :
		BSExtraData(),
		objectEffect(a_objectEffect),
		enchantmentAmount(a_enchantmentAmount),
		unk0E(0),
		pad1B(0),
		pad1C(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraEnchantment::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraEnchantment::GetType() const
	{
		return ExtraDataType::kEnchantment;
	}


	bool ExtraEnchantment::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraEnchantment*>(a_rhs);
		return objectEffect != rhs->objectEffect || enchantmentAmount != rhs->enchantmentAmount || unk0E != rhs->unk0E;
	}
}
