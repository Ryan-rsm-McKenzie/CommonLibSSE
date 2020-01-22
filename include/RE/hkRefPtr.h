#pragma once

#include <cassert>
#include <type_traits>


namespace RE
{
	template <class T>
	class hkRefPtr
	{
	public:
		//static_assert(std::is_base_of<hkReferencedObject, T>::value);


		using element_type = T;


		constexpr hkRefPtr() noexcept;
		constexpr hkRefPtr(std::nullptr_t) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> explicit hkRefPtr(Y* a_ptr);
		hkRefPtr(const hkRefPtr& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> hkRefPtr(const hkRefPtr<Y>& a_r) noexcept;
		hkRefPtr(hkRefPtr&& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> hkRefPtr(hkRefPtr<Y>&& a_r) noexcept;

		~hkRefPtr();

		hkRefPtr& operator=(const hkRefPtr& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> hkRefPtr& operator=(const hkRefPtr<Y>& a_r) noexcept;
		hkRefPtr& operator=(hkRefPtr&& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> hkRefPtr& operator=(hkRefPtr<Y>&& a_r) noexcept;

		void reset() noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> void reset(Y* a_ptr);

		[[nodiscard]] constexpr element_type* get() const noexcept;

		[[nodiscard]] constexpr T& operator*() const noexcept;
		[[nodiscard]] constexpr T* operator->() const noexcept;

		[[nodiscard]] explicit constexpr operator bool() const noexcept;

	protected:
		template <class Y> friend class hkRefPtr;


		void AddReference();
		void RemoveReference();


		// members
		T* _ptr;	// 00
	};
	STATIC_ASSERT(sizeof(hkRefPtr<void*>) == 0x8);


	template <class T>
	constexpr hkRefPtr<T>::hkRefPtr() noexcept :
		_ptr(0)
	{}


	template <class T>
	constexpr hkRefPtr<T>::hkRefPtr(std::nullptr_t) noexcept :
		_ptr(0)
	{}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	hkRefPtr<T>::hkRefPtr(Y* a_ptr) :
		_ptr(a_ptr)
	{
		AddReference();
	}


	template <class T>
	hkRefPtr<T>::hkRefPtr(const hkRefPtr& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		AddReference();
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	hkRefPtr<T>::hkRefPtr(const hkRefPtr<Y>& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		AddReference();
	}


	template <class T>
	hkRefPtr<T>::hkRefPtr(hkRefPtr&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	hkRefPtr<T>::hkRefPtr(hkRefPtr<Y>&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T>
	hkRefPtr<T>::~hkRefPtr()
	{
		RemoveReference();
		_ptr = 0;
	}


	template <class T>
	auto hkRefPtr<T>::operator=(const hkRefPtr& a_r) noexcept
		-> hkRefPtr&
	{
		if (this == &a_r) {
			return *this;
		}

		reset(a_r._ptr);
		return *this;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto hkRefPtr<T>::operator=(const hkRefPtr<Y>& a_r) noexcept
		-> hkRefPtr&
	{
		reset(a_r._ptr);
		return *this;
	}


	template <class T>
	auto hkRefPtr<T>::operator=(hkRefPtr&& a_r) noexcept
		-> hkRefPtr&
	{
		if (this == &a_r) {
			return *this;
		}

		RemoveReference();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto hkRefPtr<T>::operator=(hkRefPtr<Y>&& a_r) noexcept
		-> hkRefPtr&
	{
		RemoveReference();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T>
	void hkRefPtr<T>::reset() noexcept
	{
		if (_ptr) {
			_ptr->RemoveReference();
			_ptr = 0;
		}
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	void hkRefPtr<T>::reset(Y* a_ptr)
	{
		_ptr = a_ptr;
		AddReference();
	}


	template <class T>
	[[nodiscard]] constexpr auto hkRefPtr<T>::get() const noexcept
		-> element_type*
	{
		return _ptr;
	}


	template <class T>
	[[nodiscard]] constexpr T& hkRefPtr<T>::operator*() const noexcept
	{
		assert(_ptr != 0);
		return *get();
	}


	template <class T>
	[[nodiscard]] constexpr T* hkRefPtr<T>::operator->() const noexcept
	{
		return get();
	}


	template <class T>
	[[nodiscard]] constexpr hkRefPtr<T>::operator bool() const noexcept
	{
		return _ptr != 0;
	}


	template <class T>
	void hkRefPtr<T>::AddReference()
	{
		if (_ptr) {
			_ptr->AddReference();
		}
	}


	template <class T>
	void hkRefPtr<T>::RemoveReference()
	{
		if (_ptr) {
			_ptr->RemoveReference();
		}
	}
}
