#include "RE/ItemsPickpocketed.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	void ItemsPickpocketed::SendEvent(UInt32 a_numItems)
	{
		typedef void _SendEvent_t(UInt32 a_numItems);
		static RelocAddr<_SendEvent_t*> _SendEvent(ITEMS_PICKPOCKETED_SEND_EVENT);
		_SendEvent(a_numItems);
	}
}
