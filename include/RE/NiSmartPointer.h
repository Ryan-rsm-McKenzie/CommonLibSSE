#pragma once

#include <cassert>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>

#include "RE/CRC.h"


namespace RE
{
	template <class T>
	class NiPointer
	{
	public:
		using element_type = T;


		constexpr NiPointer() noexcept :
			_ptr(nullptr)
		{}


		constexpr NiPointer([[maybe_unused]] std::nullptr_t) noexcept :
			_ptr(nullptr)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		explicit NiPointer(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}


		NiPointer(const NiPointer& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		NiPointer(const NiPointer<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}


		NiPointer(NiPointer&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		NiPointer(NiPointer<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}


		~NiPointer()
		{
			TryDetach();
		}


		NiPointer& operator=(const NiPointer& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		NiPointer& operator=(const NiPointer<Y>& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}


		NiPointer& operator=(NiPointer&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
				a_rhs._ptr = nullptr;
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, element_type*>::value, int> = 0>
		NiPointer& operator=(NiPointer<Y>&& a_rhs)
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
		friend class NiPointer;


		void TryAttach()
		{
			if (_ptr) {
				_ptr->IncRefCount();
			}
		}


		void TryDetach()
		{
			if (_ptr) {
				_ptr->DecRefCount();
				_ptr = nullptr;
			}
		}


		// members
		element_type* _ptr;	 // 0
	};
	STATIC_ASSERT(sizeof(NiPointer<void*>) == 0x8);


	template <class T1, class T2>
	constexpr bool operator==(const NiPointer<T1>& a_lhs, const NiPointer<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}


	template <class T1, class T2>
	constexpr bool operator!=(const NiPointer<T1>& a_lhs, const NiPointer<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
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


#define NiSmartPointer(className) \
	class className;              \
	using className##Ptr = RE::NiPointer<className>;
