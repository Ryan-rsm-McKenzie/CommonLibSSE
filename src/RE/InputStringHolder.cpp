#include "RE/InputStringHolder.h"

#include "skse64/GameInput.h"  // InputStringHolder


namespace RE
{
	InputStringHolder* InputStringHolder::GetSingleton()
	{
		typedef InputStringHolder* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::InputStringHolder::GetSingleton));
		return _GetSingleton();
	}
}
