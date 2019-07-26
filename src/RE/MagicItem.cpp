#include "RE/MagicItem.h"

#include "skse64/GameObjects.h"  // MagicItem

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Effect* MagicItem::GetCostliestEffectItem(UInt32 a_arg1, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&MagicItem::GetCostliestEffectItem)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::MagicItem, GetCostliestEffectItem, func_t*);
		return func(this, a_arg1, a_arg2);
	}


	float MagicItem::GetEffectiveMagickaCost(Character* a_caster)
	{
		using func_t = function_type_t<decltype(&MagicItem::GetEffectiveMagickaCost)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::MagicItem, GetEffectiveMagickaCost, func_t*);
		return func(this, a_caster);
	}


	float MagicItem::CalculateTotalGoldValue(Actor* a_caster) const
	{
		using func_t = function_type_t<decltype(&MagicItem::CalculateTotalGoldValue)>;
		REL::Offset<func_t*> func(Offset::MagicItem::CalculateTotalGoldValue);
		return func(this, a_caster);
	}
}
