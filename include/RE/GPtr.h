#pragma once

#include <type_traits>  // remove_extent_t, enable_if_t, is_convertible


namespace RE
{
	template <class T>
	class GPtr
	{
	public:
		using element_type = std::remove_extent_t<T>;


		constexpr GPtr() noexcept :
			_object(0)
		{}


		constexpr GPtr(std::nullptr_t) noexcept :
			_object(0)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		explicit GPtr(Y* a_ptr) :
			_object(a_ptr)
		{
			AddRef();
		}


		GPtr(const GPtr& a_r) noexcept :
			_object(a_r._object)
		{
			AddRef();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		GPtr(const GPtr<Y>& a_r) noexcept :
			_object(a_r._object)
		{
			AddRef();
		}


		GPtr(GPtr&& a_r) noexcept :
			_object(a_r._object)
		{
			a_r._object = 0;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		GPtr(GPtr<Y>&& a_r) noexcept :
			_object(a_r._object)
		{
			a_r._object = 0;
		}


		~GPtr()
		{
			Release();
		}


		GPtr& operator=(const GPtr& a_r) noexcept
		{
			Release();
			_object = a_r._object;
			AddRef();
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		GPtr& operator=(const GPtr<Y>& a_r) noexcept
		{
			Release();
			_object = a_r._object;
			AddRef();
			return *this;
		}


		GPtr& operator=(GPtr&& a_r) noexcept
		{
			Release();
			_object = a_r._object;
			if (_object) {
				a_r._object = 0;
				_object->AddRef();
			}
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		GPtr& operator=(GPtr<Y>&& a_r) noexcept
		{
			Release();
			_object = a_r._object;
			if (_object) {
				a_r._object = 0;
				_object->AddRef();
			}
		}


		void reset() noexcept
		{
			if (_object) {
				_object->Release();
				_object = 0;
			}
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		void reset(Y* a_ptr)
		{
			reset();
			_object = a_ptr;
			AddRef();
		}


		void swap(GPtr& a_r) noexcept
		{
			std::swap(_object, a_r._object);
		}


		element_type* get() const noexcept
		{
			return _object;
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
			return get() != 0;
		}

	protected:
		void AddRef()
		{
			if (_object) {
				_object->AddRef();
			}
		}


		void Release()
		{
			if (_object) {
				_object->Release();
			}
		}


		// members
		T* _object;	// 0
	};
	STATIC_ASSERT(sizeof(GPtr<void*>) == 0x8);
}
