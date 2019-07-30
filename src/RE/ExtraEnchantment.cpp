#include "RE/ExtraEnchantment.h"

#include "skse64/GameExtraData.h"  // s_ExtraEnchantmentVtbl


namespace RE
{
	ExtraEnchantment::ExtraEnchantment() :
		BSExtraData(),
		objectEffect(0),
		enchantmentAmount(0),
		unk0E(0),
		pad1B(0),
		pad1C(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraEnchantmentVtbl.GetUIntPtr();
	}


	ExtraEnchantment::ExtraEnchantment(EnchantmentItem* a_objectEffect, UInt16 a_enchantmentAmount) :
		BSExtraData(),
		objectEffect(a_objectEffect),
		enchantmentAmount(a_enchantmentAmount),
		unk0E(0),
		pad1B(0),
		pad1C(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraEnchantmentVtbl.GetUIntPtr();
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
