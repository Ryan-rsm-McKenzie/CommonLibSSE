#include "RE/MemoryManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MemoryManager* MemoryManager::GetSingleton()
	{
		using func_t = decltype(&MemoryManager::GetSingleton);
		REL::Offset<func_t> func(Offset::MemoryManager::GetSingleton);
		return func();
	}


	void* MemoryManager::Allocate(std::size_t a_size, SInt32 a_alignment, bool a_aligned)
	{
		using func_t = decltype(&MemoryManager::Allocate);
		REL::Offset<func_t> func(Offset::MemoryManager::Allocate);
		return func(this, a_size, a_alignment, a_aligned);
	}


	void MemoryManager::Deallocate(void* a_ptr, bool a_aligned)
	{
		using func_t = decltype(&MemoryManager::Deallocate);
		REL::Offset<func_t> func(Offset::MemoryManager::Deallocate);
		return func(this, a_ptr, a_aligned);
	}


	ScrapHeap* MemoryManager::GetThreadScrapHeap()
	{
		using func_t = decltype(&MemoryManager::GetThreadScrapHeap);
		REL::Offset<func_t> func(Offset::MemoryManager::GetThreadScrapHeap);
		return func(this);
	}


	void* MemoryManager::Reallocate(void* a_ptr, std::size_t a_newSize, SInt32 a_alignment, bool a_aligned)
	{
		using func_t = decltype(&MemoryManager::Reallocate);
		REL::Offset<func_t> func(Offset::MemoryManager::Reallocate);
		return func(this, a_ptr, a_newSize, a_alignment, a_aligned);
	}
}
