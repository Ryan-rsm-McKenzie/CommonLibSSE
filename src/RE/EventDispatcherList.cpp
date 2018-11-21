#include "RE/EventDispatcherList.h"

#include "skse64/GameEvents.h"  // GetEventDispatcherList()


namespace RE
{
	EventDispatcherList* EventDispatcherList::GetEventDispatcherList()
	{
		typedef EventDispatcherList* _GetEventDispatcherList_t();
		static _GetEventDispatcherList_t* _GetEventDispatcherList = reinterpret_cast<_GetEventDispatcherList_t*>(::GetEventDispatcherList.GetUIntPtr());
		return _GetEventDispatcherList();
	}
}
