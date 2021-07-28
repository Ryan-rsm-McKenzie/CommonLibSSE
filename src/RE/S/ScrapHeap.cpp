#include "RE/S/ScrapHeap.h"

namespace RE
{
	void* ScrapHeap::Allocate(std::size_t a_size, std::size_t a_alignment)
	{
		using func_t = decltype(&ScrapHeap::Allocate);
		REL::Relocation<func_t> func{ REL::ID(66884) };
		return func(this, a_size, a_alignment);
	}

	void ScrapHeap::Deallocate(void* a_mem)
	{
		using func_t = decltype(&ScrapHeap::Deallocate);
		REL::Relocation<func_t> func{ REL::ID(66885) };
		return func(this, a_mem);
	}
}
