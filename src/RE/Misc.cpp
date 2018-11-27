#include "RE/Misc.h"

#include "RE/Offsets.h"


namespace RE
{
	RelocAddr<_DebugNotification_t*> _DebugNotification(DEBUG_NOTIFICATION);
	RelocAddr<_SendItemsPickPocketedEvent_t*> _SendItemsPickPocketedEvent(SEND_ITEMS_PICK_POCKETED_EVENT);
	RelocAddr<_GetPickPocketChance_t*> _GetPickPocketChance(GET_PICK_POCKET_CHANCE);
	RelocAddr<_HeapAllocAbstraction_t*> _HeapAllocAbstraction(HEAP_ALLOC_ABSTRACTION);
}
