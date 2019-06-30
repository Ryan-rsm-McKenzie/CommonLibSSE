#pragma once

#include <cstring>  // memmove


namespace RE
{
	template <class T>
	class GConstructorMov
	{
	public:
		static void Construct(void* a_ptr)
		{
			::new(a_ptr) T{};
		}


		static void Construct(void* a_ptr, const T& a_source)
		{
			::new(a_ptr) T{ a_source };
		}


		template <class S>
		static void ConstructAlt(void* a_ptr, const S& a_source)
		{
			::new(a_ptr) T{ a_source };
		}


		static void ConstructArray(void* a_ptr, UPInt a_count)
		{
			T* ptr = static_cast<T*>(a_ptr);
			for (UPInt i = 0; i < a_count; ++i) {
				Construct(ptr++);
			}
		}


		static void ConstructArray(void* a_ptr, UPInt count, const T& source)
		{
			T* ptr = (T*)a_ptr;
			for (UPInt i = 0; i < count; ++i) {
				Construct(ptr++, source);
			}
		}


		static void ConstructArray(void* a_ptr, UPInt a_count, const T* a_source)
		{
			T* ptr = (T*)a_ptr;
			for (UPInt i = 0; i < a_count; ++i) {
				Construct(ptr++, *(a_source++));
			}
		}


		static void Destruct(T* a_ptr)
		{
			a_ptr->~T();
		}


		static void DestructArray(T* a_ptr, UPInt a_count)
		{
			a_ptr += a_count - 1;
			for (UPInt i = 0; i < a_count; ++i) {
				(a_ptr--)->~T();
			}
		}


		static void CopyArrayForward(T* a_dst, const T* a_src, UPInt a_count)
		{
			std::memmove(a_dst, a_src, a_count * sizeof(T));
		}


		static void CopyArrayBackward(T* a_dst, const T* a_src, UPInt a_count)
		{
			std::memmove(a_dst, a_src, a_count * sizeof(T));
		}


		static bool IsMovable()
		{
			return true;
		}
	};
	STATIC_ASSERT(sizeof(GConstructorMov<void*>) == 0x1);
}
