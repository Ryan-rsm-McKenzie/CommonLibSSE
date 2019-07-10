#include "RE/TESMemoryManager.h"

#include "skse64/GameAPI.h"  // Heap


namespace RE
{
	TESMemoryManager* TESMemoryManager::GetSingleton()
	{
		return unrestricted_cast<TESMemoryManager*>(g_mainHeap.GetUIntPtr());
	}


	void* TESMemoryManager::Malloc(std::size_t a_size, std::size_t a_alignment, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&TESMemoryManager::Malloc)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(Heap, Allocate, func_t*);
		return func(this, a_size, a_alignment, a_aligned);
	}


	void TESMemoryManager::Free(void* a_ptr, bool a_aligned)
	{
		using func_t = function_type_t<decltype(&TESMemoryManager::Free)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(Heap, Free, func_t*);
		return func(this, a_ptr, a_aligned);
	}
}
