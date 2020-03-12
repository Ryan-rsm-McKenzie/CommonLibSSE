#pragma once

#include <cassert>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>


namespace RE
{
	template <class T>
	class hkRefPtr
	{
	public:
		//static_assert(std::is_base_of<hkReferencedObject, T>::value);


		using element_type = T;


		constexpr hkRefPtr() noexcept :
			_ptr(nullptr)
		{}


		constexpr hkRefPtr([[maybe_unused]] std::nullptr_t) noexcept :
			_ptr(nullptr)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		explicit hkRefPtr(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}


		hkRefPtr(const hkRefPtr& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		hkRefPtr(const hkRefPtr<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		hkRefPtr(hkRefPtr&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		hkRefPtr(hkRefPtr<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		~hkRefPtr()
		{
			TryDetach();
		}


		hkRefPtr& operator=(const hkRefPtr& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		hkRefPtr& operator=(const hkRefPtr<Y>& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		hkRefPtr& operator=(hkRefPtr&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
				a_rhs._ptr = nullptr;
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		hkRefPtr& operator=(hkRefPtr<Y>&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
				a_rhs._ptr = nullptr;
			}
			return *this;
		}


		void reset()
		{
			TryDetach();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		void reset(Y* a_ptr)
		{
			if (_ptr != a_ptr) {
				TryDetach();
				_ptr = a_ptr;
				TryAttach();
			}
		}


		[[nodiscard]] constexpr element_type* get() const noexcept
		{
			return _ptr;
		}


		[[nodiscard]] explicit constexpr operator bool() const noexcept
		{
			return static_cast<bool>(_ptr);
		}


		[[nodiscard]] constexpr element_type& operator*() const noexcept
		{
			assert(static_cast<bool>(*this));
			return *_ptr;
		}


		[[nodiscard]] constexpr element_type* operator->() const noexcept
		{
			assert(static_cast<bool>(*this));
			return _ptr;
		}

	protected:
		template <class>
		friend class hkRefPtr;


		void TryAttach()
		{
			if (_ptr) {
				_ptr->AddReference();
			}
		}


		void TryDetach()
		{
			if (_ptr) {
				_ptr->RemoveReference();
				_ptr = nullptr;
			}
		}


		// members
		element_type* _ptr;	 // 00
	};
	STATIC_ASSERT(sizeof(hkRefPtr<void*>) == 0x8);


	template <class T1, class T2>
	constexpr bool operator==(const hkRefPtr<T1>& a_lhs, const hkRefPtr<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}


	template <class T1, class T2>
	constexpr bool operator!=(const hkRefPtr<T1>& a_lhs, const hkRefPtr<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}
}
