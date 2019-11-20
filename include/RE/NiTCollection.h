#pragma once


namespace RE
{
	void* NiMalloc(std::size_t a_sizeInBytes);
	void* NiAlignedMalloc(std::size_t a_sizeInBytes, std::size_t a_alignment);
	void* NiRealloc(void* a_mem, std::size_t a_sizeInBytes);
	void* NiAlignedRealloc(void* a_mem, std::size_t a_sizeInBytes, std::size_t a_alignment);
	void NiFree(void* a_mem);
	void NiAlignedFree(void* a_mem);
	constexpr bool NiTrackAlloc(void* a_mem, std::size_t a_sizeInBytes) { return false; }
	constexpr bool NiTrackFree(void* a_mem) { return false; }


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
			return NiMalloc(sizeof(T) * a_numElements);
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
			return new T[a_numElements];
		};


		inline static void Deallocate(T* a_array)
		{
			delete[] a_array;
		};
	};
}
