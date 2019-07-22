#include "RE/BGSSaveLoadManager.h"

#include "skse64/GameData.h"  // BGSSaveLoadManager


namespace RE
{
	BGSSaveLoadManager* BGSSaveLoadManager::GetSingleton()
	{
		return reinterpret_cast<BGSSaveLoadManager*>(::BGSSaveLoadManager::GetSingleton());
	}


	void BGSSaveLoadManager::Save(const char* a_name)
	{
		using func_t = function_type_t<decltype(&BGSSaveLoadManager::Save)>;
		func_t* func = unrestricted_cast<func_t*>(&::BGSSaveLoadManager::Save);
		func(this, a_name);
	}


	void BGSSaveLoadManager::Load(const char* a_name)
	{
		using func_t = function_type_t<decltype(&BGSSaveLoadManager::Load)>;
		func_t* func = unrestricted_cast<func_t*>(&::BGSSaveLoadManager::Load);
		func(this, a_name);
	}
}
