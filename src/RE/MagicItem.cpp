#include "RE/MagicItem.h"

#include "skse64/GameObjects.h"  // MagicItem


namespace RE
{
	EffectItem* MagicItem::GetCostliestEffectItem(int a_arg1, bool a_arg2)
	{
		typedef EffectItem* _GetCostliestEffectItem_t(MagicItem* a_this, int a_arg1, bool a_arg2);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::MagicItem*>(this)->_GetCostliestEffectItem_GetPtr());
		_GetCostliestEffectItem_t* _GetCostliestEffectItem = reinterpret_cast<_GetCostliestEffectItem_t*>(*ptr);
		return _GetCostliestEffectItem(this, a_arg1, a_arg2);
	}


	float MagicItem::GetEffectiveMagickaCost(Character* a_caster)
	{
		typedef float _GetEffectiveMagickaCost_t(MagicItem* a_this, Character* a_caster);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::MagicItem*>(this)->_GetEffectiveMagickaCost_GetPtr());
		_GetEffectiveMagickaCost_t* _GetEffectiveMagickaCost = reinterpret_cast<_GetEffectiveMagickaCost_t*>(*ptr);
		return _GetEffectiveMagickaCost(this, a_caster);
	}
}
