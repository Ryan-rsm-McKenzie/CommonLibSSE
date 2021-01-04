#include "RE/M/MagicItem.h"

namespace RE
{
	float MagicItem::CalculateMagickaCost(Actor* a_caster) const
	{
		return CalculateCost(a_caster);
	}

	float MagicItem::CalculateTotalGoldValue(Actor* a_caster) const
	{
		return CalculateCost(a_caster);
	}

	Effect* MagicItem::GetCostliestEffectItem(std::uint32_t a_arg1, bool a_arg2)
	{
		using func_t = decltype(&MagicItem::GetCostliestEffectItem);
		REL::Relocation<func_t> func{ Offset::MagicItem::GetCostliestEffectItem };
		return func(this, a_arg1, a_arg2);
	}

	float MagicItem::CalculateCost(Actor* a_caster) const
	{
		using func_t = decltype(&MagicItem::CalculateTotalGoldValue);
		REL::Relocation<func_t> func{ Offset::MagicItem::CalculateCost };
		return func(this, a_caster);
	}

	auto MagicItem::GetData()
		-> Data*
	{
		return GetData2();
	}

	auto MagicItem::GetData() const
		-> const Data*
	{
		return GetData1();
	}
}
