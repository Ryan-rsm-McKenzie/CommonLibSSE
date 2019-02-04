#include "RE/ChestsLooted.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	void ChestsLooted::SendEvent()
	{
		typedef void _SendEvent_t();
		RelocAddr<_SendEvent_t*> _SendEvent(CHESTS_LOOTED_SEND_EVENT);
		_SendEvent();
	}
}
