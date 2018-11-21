#include "RE/MagicItem.h"

#include "skse64/GameObjects.h"  // MagicItem


namespace RE
{
	MagicItem::EffectItem* MagicItem::GetCostliestEffectItem(int a_arg1, bool a_arg2)
	{
		typedef MagicItem::EffectItem* _GetCostliestEffectItem_t(MagicItem* a_this, int a_arg1, bool a_arg2);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::MagicItem*>(this)->_GetCostliestEffectItem_GetPtr());
		static _GetCostliestEffectItem_t* _GetCostliestEffectItem = reinterpret_cast<_GetCostliestEffectItem_t*>(*ptr);
		return _GetCostliestEffectItem(this, a_arg1, a_arg2);
	}


	float MagicItem::GetEffectiveMagickaCost(Character* a_caster)
	{
		typedef float _GetEffectiveMagickaCost_t(MagicItem* a_this, Character* a_caster);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::MagicItem*>(this)->_GetEffectiveMagickaCost_GetPtr());
		static _GetEffectiveMagickaCost_t* _GetEffectiveMagickaCost = reinterpret_cast<_GetEffectiveMagickaCost_t*>(*ptr);
		return _GetEffectiveMagickaCost(this, a_caster);
	}
}
