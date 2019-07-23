#pragma once

#include <cassert>  // assert
#include <cstddef>  // nullptr_t
#include <type_traits>  // enable_if_t, is_convertible


namespace RE
{
	template <class T>
	struct BSTSmartPointerIntrusiveRefCount
	{
		static void Attach(T* a_ptr);
		static void Detach(T* a_ptr);
	};


	template <class T>
	void BSTSmartPointerIntrusiveRefCount<T>::Attach(T* a_ptr)
	{
		a_ptr->IncRefCount();
	}


	template <class T>
	void BSTSmartPointerIntrusiveRefCount<T>::Detach(T* a_ptr)
	{
		if (a_ptr->DecRefCount() == 0) {
			delete a_ptr;
		}
	}


	template <class T, class RefManager = BSTSmartPointerIntrusiveRefCount<T>>
	class BSTSmartPointer
	{
	public:
		using element_type = T;
		using reference_manager = RefManager;


		constexpr BSTSmartPointer() noexcept;
		constexpr BSTSmartPointer(std::nullptr_t) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> explicit BSTSmartPointer(Y* a_ptr);
		BSTSmartPointer(const BSTSmartPointer& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> BSTSmartPointer(const BSTSmartPointer<Y>& a_r) noexcept;
		BSTSmartPointer(BSTSmartPointer&& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> BSTSmartPointer(BSTSmartPointer<Y>&& a_r) noexcept;

		~BSTSmartPointer();

		BSTSmartPointer& operator=(const BSTSmartPointer& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> BSTSmartPointer& operator=(const BSTSmartPointer<Y>& a_r) noexcept;
		BSTSmartPointer& operator=(BSTSmartPointer&& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> BSTSmartPointer& operator=(BSTSmartPointer<Y>&& a_r) noexcept;

		void reset() noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> void reset(Y* a_ptr);

		[[nodiscard]] constexpr element_type* get() const noexcept;

		[[nodiscard]] constexpr T& operator*() const noexcept;
		[[nodiscard]] constexpr T* operator->() const noexcept;

		[[nodiscard]] explicit constexpr operator bool() const noexcept;

	protected:
		void Attach();
		void Detach();

		// members
		T* _ptr;	// 0
	};
	STATIC_ASSERT(sizeof(BSTSmartPointer<void*>) == 0x8);


	template <class T, class RefManager>
	constexpr BSTSmartPointer<T, RefManager>::BSTSmartPointer() noexcept :
		_ptr(0)
	{}


	template <class T, class RefManager>
	constexpr BSTSmartPointer<T, RefManager>::BSTSmartPointer(std::nullptr_t) noexcept :
		_ptr(0)
	{}


	template <class T, class RefManager>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	BSTSmartPointer<T, RefManager>::BSTSmartPointer(Y* a_ptr) :
		_ptr(a_ptr)
	{
		Attach();
	}


	template <class T, class RefManager>
	BSTSmartPointer<T, RefManager>::BSTSmartPointer(const BSTSmartPointer& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		Attach();
	}


	template <class T, class RefManager>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	BSTSmartPointer<T, RefManager>::BSTSmartPointer(const BSTSmartPointer<Y>& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		Attach();
	}


	template <class T, class RefManager>
	BSTSmartPointer<T, RefManager>::BSTSmartPointer(BSTSmartPointer&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T, class RefManager>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	BSTSmartPointer<T, RefManager>::BSTSmartPointer(BSTSmartPointer<Y>&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T, class RefManager>
	BSTSmartPointer<T, RefManager>::~BSTSmartPointer()
	{
		Detach();
		memzero(this);
	}


	template <class T, class RefManager>
	auto BSTSmartPointer<T, RefManager>::operator=(const BSTSmartPointer& a_r) noexcept
		-> BSTSmartPointer&
	{
		if (this == &a_r) {
			return *this;
		}

		reset(a_r._ptr);
		return *this;
	}


	template <class T, class RefManager>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto BSTSmartPointer<T, RefManager>::operator=(const BSTSmartPointer<Y>& a_r) noexcept
		-> BSTSmartPointer&
	{
		reset(a_r._ptr);
		return *this;
	}


	template <class T, class RefManager>
	auto BSTSmartPointer<T, RefManager>::operator=(BSTSmartPointer&& a_r) noexcept
		-> BSTSmartPointer&
	{
		if (this == &a_r) {
			return *this;
		}

		Detach();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T, class RefManager>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto BSTSmartPointer<T, RefManager>::operator=(BSTSmartPointer<Y>&& a_r) noexcept
		-> BSTSmartPointer&
	{
		Detach();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T, class RefManager>
	void BSTSmartPointer<T, RefManager>::reset() noexcept
	{
		if (_ptr) {
			reference_manager::Detach(_ptr);
			_ptr = 0;
		}
	}


	template <class T, class RefManager>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	void BSTSmartPointer<T, RefManager>::reset(Y* a_ptr)
	{
		_ptr = a_ptr;
		Attach();
	}


	template <class T, class RefManager>
	[[nodiscard]] constexpr auto BSTSmartPointer<T, RefManager>::get() const noexcept
		-> element_type*
	{
		return _ptr;
	}


	template <class T, class RefManager>
	[[nodiscard]] constexpr T& BSTSmartPointer<T, RefManager>::operator*() const noexcept
	{
		assert(_ptr != 0);
		return *get();
	}


	template <class T, class RefManager>
	[[nodiscard]] constexpr T* BSTSmartPointer<T, RefManager>::operator->() const noexcept
	{
		return get();
	}


	template <class T, class RefManager>
	[[nodiscard]] constexpr BSTSmartPointer<T, RefManager>::operator bool() const noexcept
	{
		return _ptr != 0;
	}


	template <class T, class RefManager>
	void BSTSmartPointer<T, RefManager>::Attach()
	{
		if (_ptr) {
			reference_manager::Attach(_ptr);
		}
	}


	template <class T, class RefManager>
	void BSTSmartPointer<T, RefManager>::Detach()
	{
		if (_ptr) {
			reference_manager::Detach(_ptr);
		}
	}


#define BSSmartPointer(className)						\
	class className;									\
	using className##Ptr = BSTSmartPointer<className>;
}
