#pragma once


namespace RE
{
	void* NiMalloc(std::size_t a_size);
	void NiFree(void* a_ptr);


	template <class T>
	class NiTMallocInterface
	{
	public:
		static T* Allocate(UInt32 a_numElements)
		{
			return NiMalloc(sizeof(T)* a_numElements);
		};


		static void Deallocate(T* a_array)
		{
			NiFree(a_array);
		};
	};


	template <class T>
	class NiTNewInterface
	{
	public:
		static T* Allocate(UInt32 a_numElements)
		{
			return new T[a_numElements];
		};
		static void Deallocate(T* a_array)
		{
			delete[] a_array;
		};
	};
}
