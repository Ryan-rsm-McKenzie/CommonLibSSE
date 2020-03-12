#pragma once

#include <cassert>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>


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
		constexpr static void Acquire(T* a_ptr)
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
			_ptr(nullptr)
		{}


		constexpr BSTSmartPointer([[maybe_unused]] std::nullptr_t) noexcept :
			_ptr(nullptr)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		explicit BSTSmartPointer(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}


		BSTSmartPointer(const BSTSmartPointer& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		BSTSmartPointer(const BSTSmartPointer<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		BSTSmartPointer(BSTSmartPointer&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		BSTSmartPointer(BSTSmartPointer<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		~BSTSmartPointer()
		{
			TryDetach();
		}


		BSTSmartPointer& operator=(const BSTSmartPointer& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		BSTSmartPointer& operator=(const BSTSmartPointer<Y>& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		BSTSmartPointer& operator=(BSTSmartPointer&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
				a_rhs._ptr = nullptr;
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		BSTSmartPointer& operator=(BSTSmartPointer<Y>&& a_rhs)
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
		template <class, template <class> class>
		friend class BSTSmartPointer;


		void TryAttach()
		{
			if (_ptr) {
				reference_manager::Acquire(_ptr);
			}
		}


		void TryDetach()
		{
			if (_ptr) {
				reference_manager::Release(_ptr);
				_ptr = nullptr;
			}
		}


		// members
		element_type* _ptr;	 // 0
	};
	STATIC_ASSERT(sizeof(BSTSmartPointer<void*>) == 0x8);


	template <class T1, class T2>
	constexpr bool operator==(const BSTSmartPointer<T1>& a_lhs, const BSTSmartPointer<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}


	template <class T1, class T2>
	constexpr bool operator!=(const BSTSmartPointer<T1>& a_lhs, const BSTSmartPointer<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}


	template <class T>
	using BSTAutoPointer = BSTSmartPointer<T, BSTSmartPointerAutoPtr>;
	STATIC_ASSERT(sizeof(BSTAutoPointer<void*>) == 0x8);
}


#define BSSmartPointer(className) \
	class className;              \
	using className##Ptr = RE::BSTSmartPointer<className>;
