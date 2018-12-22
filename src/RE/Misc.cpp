#include "RE/Misc.h"

#include "RE/Offsets.h"


namespace RE
{
	RelocAddr<_DebugNotification_t*> _DebugNotification(DEBUG_NOTIFICATION);
	RelocAddr<_SendItemsPickPocketedEvent_t*> _SendItemsPickPocketedEvent(SEND_ITEMS_PICK_POCKETED_EVENT);
	RelocAddr<_GetPickPocketChance_t*> _GetPickPocketChance(GET_PICK_POCKET_CHANCE);
	RelocAddr<_HeapAllocAbstraction_t*> _HeapAllocAbstraction(HEAP_ALLOC_ABSTRACTION);


	bool WorldPtToScreenPt3(float* a_worldToCamMatrix, NiRect<float>* a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance)
	{
		typedef bool _WorldPtToScreenPt3_t(float* a_worldToCamMatrix, NiRect<float>* a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);
		static RelocAddr<_WorldPtToScreenPt3_t*> _WorldPtToScreenPt3(WORLD_PT_TO_SCREEN_PT_3);
		return _WorldPtToScreenPt3(a_worldToCamMatrix, a_port, a_in, a_xOut, a_yOut, a_zOut, a_zeroTolerance);
	}
}
