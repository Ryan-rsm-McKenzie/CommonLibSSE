#include "RE/UIStringHolder.h"

#include "skse64/GameMenus.h"  // UIStringHolder


namespace RE
{
	UIStringHolder* UIStringHolder::GetSingleton()
	{
		using func_t = function_type_t<decltype(&UIStringHolder::GetSingleton)>;
		func_t* func = function_cast<func_t*>(&::UIStringHolder::GetSingleton);
		return func();
	}
}
