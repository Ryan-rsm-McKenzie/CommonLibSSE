#include "RE/TESMemoryManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TESMemoryManager* TESMemoryManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&TESMemoryManager::GetSingleton)>;
		REL::Offset<func_t*> func(Offset::TESMemoryManager::GetSingleton);
		return func();
	}


	void* TESMemoryManager::Malloc(std::size_t a_size, SInt32 a_alignment, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&TESMemoryManager::Malloc)>;
		REL::Offset<func_t*> func(Offset::TESMemoryManager::Malloc);
		return func(this, a_size, a_alignment, a_aligned);
	}


	void* TESMemoryManager::Realloc(void* a_ptr, std::size_t a_newSize, SInt32 a_alignment, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&TESMemoryManager::Realloc)>;
		REL::Offset<func_t*> func(Offset::TESMemoryManager::Realloc);
		return func(this, a_ptr, a_newSize, a_alignment, a_aligned);
	}


	void TESMemoryManager::Free(void* a_ptr, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&TESMemoryManager::Free)>;
		REL::Offset<func_t*> func(Offset::TESMemoryManager::Free);
		return func(this, a_ptr, a_aligned);
	}
}
