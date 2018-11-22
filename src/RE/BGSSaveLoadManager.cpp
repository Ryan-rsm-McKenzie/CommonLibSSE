#include "RE/BGSSaveLoadManager.h"

#include "skse64/GameData.h"  // BGSSaveLoadManager


namespace RE
{
	BGSSaveLoadManager*	BGSSaveLoadManager::GetSingleton()
	{
		typedef BGSSaveLoadManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::BGSSaveLoadManager::GetSingleton));
		return _GetSingleton();
	}
}
