#include "RE/BGSDefaultObjectManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSDefaultObjectManager* BGSDefaultObjectManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&BGSDefaultObjectManager::GetSingleton)>;
		REL::Offset<func_t*> func(Offset::BGSDefaultObjectManager::GetSingleton);
		return func();
	}
}
