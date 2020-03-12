#pragma once

#include <cassert>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>


namespace RE
{
	template <class T>
	class GPtr
	{
	public:
		using element_type = T;


		constexpr GPtr() noexcept :
			_ptr(nullptr)
		{}


		constexpr GPtr([[maybe_unused]] std::nullptr_t) noexcept :
			_ptr(nullptr)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		explicit GPtr(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}


		GPtr(const GPtr& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		GPtr(const GPtr<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		GPtr(GPtr&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		GPtr(GPtr<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		~GPtr()
		{
			TryDetach();
		}


		GPtr& operator=(const GPtr& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		GPtr& operator=(const GPtr<Y>& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		GPtr& operator=(GPtr&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
				a_rhs._ptr = nullptr;
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		GPtr& operator=(GPtr<Y>&& a_rhs)
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
		friend class GPtr;


		void TryAttach()
		{
			if (_ptr) {
				_ptr->AddRef();
			}
		}


		void TryDetach()
		{
			if (_ptr) {
				_ptr->Release();
				_ptr = nullptr;
			}
		}


		// members
		element_type* _ptr;	 // 0
	};
	STATIC_ASSERT(sizeof(GPtr<void*>) == 0x8);


	template <class T1, class T2>
	constexpr bool operator==(const GPtr<T1>& a_lhs, const GPtr<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}


	template <class T1, class T2>
	constexpr bool operator!=(const GPtr<T1>& a_lhs, const GPtr<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}
}
