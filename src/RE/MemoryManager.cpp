#include "RE/MemoryManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MemoryManager* MemoryManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&MemoryManager::GetSingleton)>;
		REL::Offset<func_t*> func(Offset::MemoryManager::GetSingleton);
		return func();
	}


	void* MemoryManager::Malloc(std::size_t a_size, SInt32 a_alignment, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&MemoryManager::Malloc)>;
		REL::Offset<func_t*> func(Offset::MemoryManager::Malloc);
		return func(this, a_size, a_alignment, a_aligned);
	}


	void* MemoryManager::Realloc(void* a_ptr, std::size_t a_newSize, SInt32 a_alignment, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&MemoryManager::Realloc)>;
		REL::Offset<func_t*> func(Offset::MemoryManager::Realloc);
		return func(this, a_ptr, a_newSize, a_alignment, a_aligned);
	}


	void MemoryManager::Free(void* a_ptr, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&MemoryManager::Free)>;
		REL::Offset<func_t*> func(Offset::MemoryManager::Free);
		return func(this, a_ptr, a_aligned);
	}
}
