#pragma once

#include <cassert>
#include <cstddef>
#include <type_traits>

#include "RE/CRC.h"


namespace RE
{
#define NiSmartPointer(className)					\
	class className;								\
	using className##Ptr = NiPointer<className>;


	template <class T>
	class NiPointer
	{
	public:
		using element_type = T;


		constexpr NiPointer() noexcept;
		constexpr NiPointer(std::nullptr_t) noexcept;
		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> explicit NiPointer(Y* a_ptr);
		NiPointer(const NiPointer& a_r) noexcept;
		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> NiPointer(const NiPointer<Y>& a_r) noexcept;
		NiPointer(NiPointer&& a_r) noexcept;
		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> NiPointer(NiPointer<Y>&& a_r) noexcept;

		~NiPointer();

		NiPointer& operator=(const NiPointer& a_r) noexcept;
		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> NiPointer& operator=(const NiPointer<Y>& a_r) noexcept;
		NiPointer& operator=(NiPointer&& a_r) noexcept;
		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> NiPointer& operator=(NiPointer<Y>&& a_r) noexcept;

		void reset() noexcept;
		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0> void reset(Y* a_ptr);

		[[nodiscard]] constexpr element_type* get() const noexcept;

		[[nodiscard]] explicit constexpr operator bool() const noexcept;

		[[nodiscard]] constexpr T& operator*() const noexcept;
		[[nodiscard]] constexpr T* operator->() const noexcept;

		template <class T1, class T2> friend bool operator==(const NiPointer<T1>& a_lhs, const NiPointer<T2>& a_rhs);

	protected:
		template <class Y> friend class NiPointer;


		void IncRefCount();
		void DecRefCount();


		// members
		T* _ptr;	// 0
	};
	STATIC_ASSERT(sizeof(NiPointer<void*>) == 0x8);


	template <class T>
	constexpr NiPointer<T>::NiPointer() noexcept :
		_ptr(0)
	{}


	template <class T>
	constexpr NiPointer<T>::NiPointer(std::nullptr_t) noexcept :
		_ptr(0)
	{}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	NiPointer<T>::NiPointer(Y* a_ptr) :
		_ptr(a_ptr)
	{
		IncRefCount();
	}


	template <class T>
	NiPointer<T>::NiPointer(const NiPointer& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		IncRefCount();
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	NiPointer<T>::NiPointer(const NiPointer<Y>& a_r) noexcept :
		_ptr(a_r._ptr)
	{
		IncRefCount();
	}


	template <class T>
	NiPointer<T>::NiPointer(NiPointer&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	NiPointer<T>::NiPointer(NiPointer<Y>&& a_r) noexcept :
		_ptr(std::move(a_r._ptr))
	{
		a_r._ptr = 0;
	}


	template <class T>
	NiPointer<T>::~NiPointer()
	{
		DecRefCount();
		_ptr = 0;
	}


	template <class T>
	auto NiPointer<T>::operator=(const NiPointer& a_r) noexcept
		-> NiPointer &
	{
		reset(a_r._ptr);
		return *this;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto NiPointer<T>::operator=(const NiPointer<Y>& a_r) noexcept
		-> NiPointer &
	{
		reset(a_r._ptr);
		return *this;
	}


	template <class T>
	auto NiPointer<T>::operator=(NiPointer&& a_r) noexcept
		-> NiPointer &
	{
		DecRefCount();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	auto NiPointer<T>::operator=(NiPointer<Y>&& a_r) noexcept
		-> NiPointer &
	{
		DecRefCount();
		_ptr = std::move(a_r._ptr);
		a_r._ptr = 0;
		return *this;
	}


	template <class T>
	void NiPointer<T>::reset() noexcept
	{
		if (_ptr) {
			_ptr->DecRefCount();
			_ptr = 0;
		}
	}


	template <class T>
	template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int>>
	void NiPointer<T>::reset(Y* a_ptr)
	{
		_ptr = a_ptr;
		IncRefCount();
	}


	template <class T>
	[[nodiscard]] constexpr auto NiPointer<T>::get() const noexcept
		-> element_type*
	{
		return _ptr;
	}


	template <class T>
	[[nodiscard]] constexpr NiPointer<T>::operator bool() const noexcept
	{
		return _ptr != 0;
	}


	template <class T>
	[[nodiscard]] constexpr T& NiPointer<T>::operator*() const noexcept
	{
		assert(_ptr != 0);
		return *get();
	}


	template <class T>
	[[nodiscard]] constexpr T* NiPointer<T>::operator->() const noexcept
	{
		return get();
	}


	template <class T1, class T2>
	bool operator==(const NiPointer<T1>& a_lhs, const NiPointer<T2>& a_rhs)
	{
		return a_lhs._ptr == a_rhs._ptr;
	}


	template <class T>
	void NiPointer<T>::IncRefCount()
	{
		if (_ptr) {
			_ptr->IncRefCount();
		}
	}


	template <class T>
	void NiPointer<T>::DecRefCount()
	{
		if (_ptr) {
			_ptr->DecRefCount();
		}
	}


	template <class T>
	struct CRC32Hash<NiPointer<T>>
	{
	public:
		UInt32 operator()(const NiPointer<T>& a_key) const
		{
			return CRC32Hash<std::uintptr_t>()((std::uintptr_t)a_key.get());
		}
	};
}
