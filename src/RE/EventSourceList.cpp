#include "RE/EventSourceList.h"

#include "skse64/GameEvents.h"  // GetEventDispatcherList()


namespace RE
{
	EventSourceList* EventSourceList::GetEventSourceList()
	{
		typedef EventSourceList* _GetEventSourceList_t();
		static _GetEventSourceList_t* _GetEventSourceList = reinterpret_cast<_GetEventSourceList_t*>(::GetEventDispatcherList.GetUIntPtr());
		return _GetEventSourceList();
	}
}
