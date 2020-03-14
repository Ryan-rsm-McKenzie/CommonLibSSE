#include "RE/BGSDefaultObjectManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSDefaultObjectManager* BGSDefaultObjectManager::GetSingleton()
	{
		using func_t = decltype(&BGSDefaultObjectManager::GetSingleton);
		REL::Offset<func_t> func(Offset::BGSDefaultObjectManager::GetSingleton);
		return func();
	}


	TESForm* BGSDefaultObjectManager::GetObject(DefaultObject a_object)
	{
		return GetObject(to_underlying(a_object));
	}


	TESForm* BGSDefaultObjectManager::GetObject(std::size_t a_idx)
	{
		assert(a_idx < to_underlying(DefaultObject::kTotal));
		return objectInit[a_idx] ? objects[a_idx] : nullptr;
	}
}
