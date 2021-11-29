#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	void*          NiMalloc(std::size_t a_sizeInBytes);
	void*          NiAlignedMalloc(std::size_t a_sizeInBytes, std::size_t a_alignment);
	void*          NiRealloc(void* a_mem, std::size_t a_sizeInBytes);
	void*          NiAlignedRealloc(void* a_mem, std::size_t a_sizeInBytes, std::size_t a_alignment);
	void           NiFree(void* a_mem);
	void           NiAlignedFree(void* a_mem);
	constexpr bool NiTrackAlloc([[maybe_unused]] void* a_mem, [[maybe_unused]] std::size_t a_sizeInBytes) { return false; }
	constexpr bool NiTrackFree([[maybe_unused]] void* a_mem) { return false; }

	// calloc
	template <class T>
	T* NiAlloc(std::size_t a_count)
	{
		return static_cast<T*>(NiMalloc(sizeof(T) * a_count));
	}

	// aligned calloc
	template <class T>
	T* NiAlignedAlloc(std::size_t a_count, std::size_t a_alignment)
	{
		return static_cast<T*>(NiAlignedMalloc(sizeof(T) * a_count, a_alignment));
	}

	template <class T>
	class NiTMallocInterface
	{
	public:
		inline static T* Allocate(std::size_t a_numElements)
		{
			return static_cast<T*>(NiMalloc(sizeof(T) * a_numElements));
		};

		inline static void Deallocate(T* a_array)
		{
			NiFree(a_array);
		};
	};

	template <class T>
	class NiTNewInterface
	{
	public:
		inline static T* Allocate(std::size_t a_numElements)
		{
			auto mem = malloc(sizeof(std::size_t) + sizeof(T) * a_numElements);
			auto head = static_cast<std::size_t*>(mem);
			*head = a_numElements;
			mem = head + 1;
			return static_cast<T*>(mem);
		};

		inline static void Deallocate(T* a_array)
		{
			if (a_array) {
				auto head = stl::adjust_pointer<std::size_t>(a_array, -stl::ssizeof_v<std::uintptr_t>);
				for (std::size_t i = 0; i < *head; ++i) {
					a_array[i].~T();
				}
				free(head);
			}
		};
	};
}
