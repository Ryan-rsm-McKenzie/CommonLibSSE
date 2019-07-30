#pragma once

#include <cassert>  // assert
#include <cstddef>  // nullptr_t
#include <type_traits>  // enable_if_t, is_convertible


namespace RE
{
	template <class T>
	class GPtr
	{
	public:
		using element_type = T;


		constexpr GPtr() noexcept;
		constexpr GPtr(std::nullptr_t) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> explicit GPtr(Y* a_ptr);
		GPtr(const GPtr& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> GPtr(const GPtr<Y>& a_r) noexcept;
		GPtr(GPtr&& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> GPtr(GPtr<Y>&& a_r) noexcept;

		~GPtr();

		GPtr& operator=(const GPtr& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> GPtr& operator=(const GPtr<Y>& a_r) noexcept;
		GPtr& operator=(GPtr&& a_r) noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> GPtr& operator=(GPtr<Y>&& a_r) noexcept;

		void reset() noexcept;
		template<class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> void reset(Y* a_ptr);

		[[nodiscard]] constexpr element_type* get() const noexcept;

		[[nodiscard]] constexpr T& operator*() const noexcept;
		[[nodiscard]] constexpr T* operator->() const noexcept;

		[[nodiscard]] explicit constexpr operator bool() const noexcept;

	protected:
		void AddRef();
		void Release();


		// members
		T* _ptr;	// 0
	};
	STATIC_ASSERT(sizeof(GPtr<void*>) == 0x8);


	template <class T>
	constexpr GPtr<T>::GPtr() noexcept :
		_ptr(0)
	{}


	template <class T>
	constexpr GPtr<T>::GPtr(std::nullptr_t) noexcept :
		_ptr(0)
	{}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	GPtr<T>::GPtr(Y* a_ptr) :
		_ptr(a_ptr)
	{
		AddRef();
	}


	template <class T>
	GPtr<T>::GPtr(const GPtr& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		AddRef();
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	GPtr<T>::GPtr(const GPtr<Y>& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		AddRef();
	}


	template <class T>
	GPtr<T>::GPtr(GPtr&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	GPtr<T>::GPtr(GPtr<Y>&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T>
	GPtr<T>::~GPtr()
	{
		Release();
		_ptr = 0;
	}


	template <class T>
	auto GPtr<T>::operator=(const GPtr& a_r) noexcept
		-> GPtr &
	{
		reset(a_r._ptr);
		return *this;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto GPtr<T>::operator=(const GPtr<Y>& a_r) noexcept
		-> GPtr &
	{
		reset(a_r._ptr);
		return *this;
	}


	template <class T>
	auto GPtr<T>::operator=(GPtr&& a_r) noexcept
		-> GPtr &
	{
		Release();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto GPtr<T>::operator=(GPtr<Y>&& a_r) noexcept
		-> GPtr &
	{
		Release();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T>
	void GPtr<T>::reset() noexcept
	{
		if (_ptr) {
			_ptr->Release();
			_ptr = 0;
		}
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	void GPtr<T>::reset(Y* a_ptr)
	{
		_ptr = a_ptr;
		AddRef();
	}


	template <class T>
	[[nodiscard]] constexpr auto GPtr<T>::get() const noexcept
		-> element_type*
	{
		return _ptr;
	}


	template <class T>
	[[nodiscard]] constexpr T& GPtr<T>::operator*() const noexcept
	{
		assert(_ptr != 0);
		return *get();
	}


	template <class T>
	[[nodiscard]] constexpr T* GPtr<T>::operator->() const noexcept
	{
		return get();
	}


	template <class T>
	[[nodiscard]] constexpr GPtr<T>::operator bool() const noexcept
	{
		return _ptr != 0;
	}


	template <class T>
	void GPtr<T>::AddRef()
	{
		if (_ptr) {
			_ptr->AddRef();
		}
	}


	template <class T>
	void GPtr<T>::Release()
	{
		if (_ptr) {
			_ptr->Release();
		}
	}
}
