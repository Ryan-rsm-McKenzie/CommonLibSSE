#pragma once

#include "skse64_common/Relocation.h"  // RelocPtr, RelocAddr


namespace RE
{
	class Actor;
	class TESForm;


	typedef void _DebugNotification_t(const char* a_notification, void* a_unk2, bool a_unk3);  // a_unk2 = 0, a_unk3 = true, for normal notification
	extern RelocAddr<_DebugNotification_t*> _DebugNotification;

	typedef void _SendItemsPickPocketedEvent_t(UInt32 a_numItems);
	extern RelocAddr<_SendItemsPickPocketedEvent_t*> _SendItemsPickPocketedEvent;

	typedef UInt32 _GetPickPocketChance_t(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_totalWeight, RE::Actor* a_player, RE::Actor* a_target, bool a_isDetected, RE::TESForm* a_item);
	extern RelocAddr<_GetPickPocketChance_t*> _GetPickPocketChance;

	typedef void* _HeapAllocAbstraction_t(std::size_t a_allocSize);
	extern RelocAddr<_HeapAllocAbstraction_t*> _HeapAllocAbstraction;
}
