#include "RE/UIStringHolder.h"

#include "skse64/GameMenus.h"  // UIStringHolder


namespace RE
{
	UIStringHolder* UIStringHolder::GetSingleton()
	{
		typedef UIStringHolder* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::UIStringHolder::GetSingleton));
		return _GetSingleton();
	}
}
