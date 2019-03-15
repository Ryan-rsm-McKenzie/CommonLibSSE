#pragma once

#include <cstddef>  // nullptr_t
#include <type_traits>  // remove_extent_t, enable_if_t, is_convertible
#include <utility>  // swap


namespace RE
{
#define NiSmartPointer(className)					\
	class className;								\
	typedef NiPointer<className> className##Ptr;


	template <class T>
	class NiPointer
	{
	public:
		using element_type = std::remove_extent_t<T>;


		constexpr NiPointer() noexcept :
			_object(0)
		{}


		constexpr NiPointer(std::nullptr_t) noexcept :
			_object(0)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		explicit NiPointer(Y* a_ptr) :
			_object(a_ptr)
		{
			IncRefCount();
		}


		NiPointer(const NiPointer& a_r) noexcept :
			_object(a_r._object)
		{
			IncRefCount();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		NiPointer(const NiPointer<Y>& a_r) noexcept :
			_object(a_r._object)
		{
			IncRefCount();
		}


		NiPointer(NiPointer&& a_r) noexcept :
			_object(a_r._object)
		{
			a_r._object = 0;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		NiPointer(NiPointer<Y>&& a_r) noexcept :
			_object(a_r._object)
		{
			a_r._object = 0;
		}


		~NiPointer()
		{
			DecRefCount();
		}


		NiPointer& operator=(const NiPointer& a_r) noexcept
		{
			DecRefCount();
			_object = a_r._object;
			IncRefCount();
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		NiPointer& operator=(const NiPointer<Y>& a_r) noexcept
		{
			DecRefCount();
			_object = a_r._object;
			IncRefCount();
			return *this;
		}


		NiPointer& operator=(NiPointer&& a_r) noexcept
		{
			DecRefCount();
			_object = a_r._object;
			if (_object) {
				a_r._object = 0;
				_object->IncRefCount();
			}
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		NiPointer& operator=(NiPointer<Y>&& a_r) noexcept
		{
			DecRefCount();
			_object = a_r._object;
			if (_object) {
				a_r._object = 0;
				_object->IncRefCount();
			}
		}


		void reset() noexcept
		{
			if (_object) {
				_object->DecRefCount();
				_object = 0;
			}
		}


		template<class Y, typename std::enable_if_t<std::is_convertible<Y, T>::value, int> = 0>
		void reset(Y* a_ptr)
		{
			reset();
			_object = a_ptr;
			IncRefCount();
		}


		void swap(NiPointer& a_r) noexcept
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
		void IncRefCount()
		{
			if (_object) {
				_object->IncRefCount();
			}
		}


		void DecRefCount()
		{
			if (_object) {
				_object->DecRefCount();
			}
		}


		T* _object;	// 0
	};
	using TestNiPointer = NiPointer<std::size_t>;
	STATIC_ASSERT(sizeof(TestNiPointer) == 0x8);
}
