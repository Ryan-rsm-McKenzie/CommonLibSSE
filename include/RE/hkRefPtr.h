#pragma once

#include <cstddef>  // nullptr_t
#include <type_traits>  // is_base_of

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	template <class T>
	class hkRefPtr
	{
		//static_assert(std::is_convertible<T*, hkReferencedObject*>::value);
	public:
		constexpr hkRefPtr() noexcept :
			ptr(0)
		{}


		constexpr hkRefPtr(std::nullptr_t) noexcept :
			ptr(0)
		{}


		hkRefPtr(const hkRefPtr& a_r) noexcept
		{
			if (a_r.ptr) {
				a_r.ptr->AddReference();
			}
			ptr = a_r.ptr;
		}


		explicit hkRefPtr(T* a_ptr)
		{
			if (a_ptr) {
				a_ptr->AddReference();
			}
			ptr = a_ptr;
		}


		~hkRefPtr()
		{
			if (ptr) {
				ptr->RemoveReference();
			}
			ptr = 0;
		}


		hkRefPtr& operator=(const hkRefPtr& a_r) noexcept
		{
			if (a_r.ptr) {
				a_r.ptr->AddReference();
			}
			if (ptr) {
				ptr->RemoveReference();
			}
			ptr = a_r.ptr;
		}


		T* get() const noexcept
		{
			return ptr;
		}


		T& operator*() const noexcept
		{
			return *get();
		}


		T* operator->() const noexcept
		{
			return get();
		}

	protected:
		// members
		T* ptr;	// 00
	};
	STATIC_ASSERT(sizeof(hkRefPtr<void*>) == 0x8);
}
