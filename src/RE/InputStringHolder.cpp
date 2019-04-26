#include "RE/InputStringHolder.h"

#include "skse64/GameInput.h"  // InputStringHolder


namespace RE
{
	InputStringHolder* InputStringHolder::GetSingleton()
	{
		using func_t = function_type_t<decltype(&InputStringHolder::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::InputStringHolder::GetSingleton);
		return func();
	}
}
