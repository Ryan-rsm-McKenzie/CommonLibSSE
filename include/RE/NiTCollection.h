#pragma once


namespace RE
{
	void* NiMalloc(std::size_t a_count);
	void NiFree(void* a_ptr);


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
