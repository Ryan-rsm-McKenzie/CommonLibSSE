#pragma once

#include <cstddef>  // nullptr_t
#include <type_traits>  // enable_if_t, is_convertible

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	template <class T>
	struct BSTSmartPointerIntrusiveRefCount
	{
		static void Attach(T* a_ptr)
		{
			a_ptr->IncRefCount();
		}


		static void Detach(T* a_ptr)
		{
			if (a_ptr->DecRefCount() == 0) {
				delete a_ptr;
			}
		}
	};


	template <class T, template <class> class RefManager = BSTSmartPointerIntrusiveRefCount>
	class BSTSmartPointer
	{
	public:
		using element_type = T;
		using reference_manager = RefManager<T>;


		constexpr BSTSmartPointer() noexcept :
			_ptr(0)
		{}


		constexpr BSTSmartPointer(std::nullptr_t) noexcept :
			_ptr(0)
		{}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		explicit BSTSmartPointer(Y* a_ptr) :
			_ptr(a_ptr._ptr)
		{
			reference_manager::Attach(_ptr);
		}


		BSTSmartPointer(const BSTSmartPointer& a_r) noexcept :
			_ptr(a_r._ptr)
		{
			reference_manager::Attach(_ptr);
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer(const BSTSmartPointer<Y>& a_r) noexcept :
			_ptr(a_r._ptr)
		{
			reference_manager::Attach(_ptr);
		}


		BSTSmartPointer(BSTSmartPointer&& a_r) noexcept :
			_ptr(a_r._ptr)
		{
			a_r._ptr = 0;
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer(BSTSmartPointer<Y>&& a_r) noexcept :
			_ptr(a_r._ptr)
		{
			a_r._ptr = 0;
		}


		~BSTSmartPointer()
		{
			if (_ptr) {
				reference_manager::Detach(_ptr);
			}
		}


		BSTSmartPointer& operator=(const BSTSmartPointer& a_r) noexcept
		{
			reset(a_r._ptr);
			reference_manager::Attach(_ptr);
			return *this;
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer& operator=(const BSTSmartPointer<Y>& a_r) noexcept
		{
			reset(a_r._ptr);
			reference_manager::Attach(_ptr);
			return *this;
		}


		BSTSmartPointer& operator=(BSTSmartPointer&& a_r) noexcept
		{
			_ptr = a_r._ptr;
			a_r._ptr = 0;
			return *this;
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer& operator=(BSTSmartPointer<Y>&& a_r) noexcept
		{
			_ptr = a_r._ptr;
			a_r._ptr = 0;
			return *this;
		}


		void reset() noexcept
		{
			if (_ptr) {
				reference_manager::Detach(_ptr);
				_ptr = 0;
			}
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		void reset(Y* a_ptr)
		{
			if (_ptr) {
				reference_manager::Detach(_ptr);
			}
			_ptr = a_ptr;
		}


		element_type* get() const noexcept
		{
			return _ptr;
		}


		T& operator*() const noexcept
		{
			return *get();
		}


		T* operator->() const noexcept
		{
			return get();
		}


		explicit operator bool() const noexcept
		{
			return _ptr != 0;
		}

	protected:
		// members
		T* _ptr;	// 0
	};
	STATIC_ASSERT(sizeof(BSTSmartPointer<void*>) == 0x8);


#define BSSmartPointer(className)						\
	class className;									\
	typedef BSTSmartPointer<className> className##Ptr;
}
