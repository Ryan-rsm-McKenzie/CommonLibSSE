#include "RE/BGSDefaultObjectManager.h"

#include "skse64/GameForms.h"  // BGSDefaultObjectManager


namespace RE
{
	BGSDefaultObjectManager* BGSDefaultObjectManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&BGSDefaultObjectManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(::BGSDefaultObjectManager::GetSingleton);
		return func();
	}
}
