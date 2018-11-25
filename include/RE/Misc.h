#pragma once

#include "skse64_common/Relocation.h"  // RelocPtr, RelocAddr

class TESForm;


namespace RE
{
	class Actor;


	typedef void _SendItemsPickPocketedEvent_t(UInt32 a_numItems);
	extern RelocAddr<_SendItemsPickPocketedEvent_t*> _SendItemsPickPocketedEvent;

	typedef UInt32 _GetPickPocketChance_t(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_totalWeight, RE::Actor* a_player, RE::Actor* a_target, bool a_isDetected, TESForm* a_item);
	extern RelocAddr<_GetPickPocketChance_t*> _GetPickPocketChance;

	typedef void* _HeapAllocAbstraction_t(std::size_t a_allocSize);
	extern RelocAddr<_HeapAllocAbstraction_t*> _HeapAllocAbstraction;
}
