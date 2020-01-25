#pragma once

#include <cassert>
#include <type_traits>


namespace RE
{
	template <class T>
	struct BSTSmartPointerIntrusiveRefCount
	{
		static void Acquire(T* a_ptr)
		{
			a_ptr->IncRef();
		}


		static void Release(T* a_ptr)
		{
			if (a_ptr->DecRef() == 0) {
				delete a_ptr;
			}
		}
	};


	template <class T>
	struct BSTSmartPointerAutoPtr
	{
		template <class T>
		static void Acquire(T* a_ptr)
		{
			return;
		}


		template <class T>
		static void Release(T* a_ptr)
		{
			delete a_ptr;
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
			_ptr(a_ptr)
		{
			Acquire();
		}


		BSTSmartPointer(const BSTSmartPointer& a_r) noexcept :
			_ptr(a_r._ptr)
		{
			Acquire();
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer(const BSTSmartPointer<Y>& a_r) noexcept :
			_ptr(a_r._ptr)
		{
			Acquire();
		}


		BSTSmartPointer(BSTSmartPointer&& a_r) noexcept :
			_ptr(std::move(a_r._ptr))
		{
			a_r._ptr = 0;
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer(BSTSmartPointer<Y>&& a_r) noexcept :
			_ptr(std::move(a_r._ptr))
		{
			a_r._ptr = 0;
		}


		~BSTSmartPointer()
		{
			Release();
			_ptr = 0;
		}


		BSTSmartPointer& operator=(const BSTSmartPointer& a_r) noexcept
		{
			if (this == &a_r) {
				return *this;
			}

			reset(a_r._ptr);
			return *this;
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer& operator=(const BSTSmartPointer<Y>& a_r) noexcept
		{
			reset(a_r._ptr);
			return *this;
		}


		BSTSmartPointer& operator=(BSTSmartPointer&& a_r) noexcept
		{
			if (this == &a_r) {
				return *this;
			}

			Release();
			_ptr = std::move(a_r._ptr);
			a_r._ptr = 0;
			return *this;
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSTSmartPointer& operator=(BSTSmartPointer<Y>&& a_r) noexcept
		{
			Release();
			_ptr = std::move(a_r._ptr);
			a_r._ptr = 0;
			return *this;
		}


		void reset() noexcept
		{
			if (_ptr) {
				reference_manager::Release(_ptr);
				_ptr = 0;
			}
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		void reset(Y* a_ptr)
		{
			_ptr = a_ptr;
			Acquire();
		}


		[[nodiscard]] constexpr element_type* get() const noexcept
		{
			return _ptr;
		}


		[[nodiscard]] constexpr T& operator*() const noexcept
		{
			assert(_ptr != 0);
			return *get();
		}


		[[nodiscard]] constexpr T* operator->() const noexcept
		{
			return get();
		}


		[[nodiscard]] explicit constexpr operator bool() const noexcept
		{
			return _ptr != 0;
		}

	protected:
		template <class, template <class> class> friend class BSTSmartPointer;


		void Acquire()
		{
			if (_ptr) {
				reference_manager::Acquire(_ptr);
			}
		}


		void Release()
		{
			if (_ptr) {
				reference_manager::Release(_ptr);
			}
		}


		// members
		T* _ptr;	// 0
	};
	STATIC_ASSERT(sizeof(BSTSmartPointer<void*>) == 0x8);


	template <class T> using BSTAutoPointer = BSTSmartPointer<T, BSTSmartPointerAutoPtr>;
	STATIC_ASSERT(sizeof(BSTAutoPointer<void*>) == 0x8);
}


#define BSSmartPointer(className)							\
	class className;										\
	using className##Ptr = RE::BSTSmartPointer<className>;
