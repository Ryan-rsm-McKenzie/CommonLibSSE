#pragma once

#include "RE/C/CRC.h"

namespace RE
{
	template <class T>
	class NiPointer
	{
	public:
		using element_type = T;

		// 1
		constexpr NiPointer() noexcept = default;

		// 2
		constexpr NiPointer(std::nullptr_t) noexcept {}

		// 3
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		explicit NiPointer(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}

		// 9a
		NiPointer(const NiPointer& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 9b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		NiPointer(const NiPointer<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 10a
		NiPointer(NiPointer&& a_rhs) noexcept :
			_ptr(a_rhs._ptr)
		{
			a_rhs._ptr = nullptr;
		}

		// 10b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		NiPointer(NiPointer<Y>&& a_rhs) noexcept :
			_ptr(a_rhs._ptr)
		{
			a_rhs._ptr = nullptr;
		}

		~NiPointer() { TryDetach(); }

		// 1a
		NiPointer& operator=(const NiPointer& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}

		// 1b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		NiPointer& operator=(const NiPointer<Y>& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			TryAttach();
			return *this;
		}

		// 2a
		NiPointer& operator=(NiPointer&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				a_rhs._ptr = nullptr;
			}
			return *this;
		}

		// 2b
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		NiPointer& operator=(NiPointer<Y>&& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			a_rhs._ptr = nullptr;
			return *this;
		}

		void reset() { TryDetach(); }

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
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
		element_type* _ptr{ nullptr };  // 0
	};
	//static_assert(sizeof(NiPointer<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] NiPointer<T> make_nismart(Args&&... a_args)
	{
		return NiPointer<T>{ new T(std::forward<Args>(a_args)...) };
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator==(const NiPointer<T1>& a_lhs, const NiPointer<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator!=(const NiPointer<T1>& a_lhs, const NiPointer<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const NiPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(std::nullptr_t, const NiPointer<T>& a_rhs) noexcept
	{
		return !a_rhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(const NiPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return static_cast<bool>(a_lhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(std::nullptr_t, const NiPointer<T>& a_rhs) noexcept
	{
		return static_cast<bool>(a_rhs);
	}

	template <class T>
	NiPointer(T*) -> NiPointer<T>;

	template <class T>
	struct BSCRC32_<NiPointer<T>>
	{
	public:
		[[nodiscard]] inline std::uint32_t operator()(const NiPointer<T>& a_key) const noexcept
		{
			return BSCRC32_<T*>()(a_key.get());
		}
	};
}

#define NiSmartPointer(className) \
	class className;              \
	using className##Ptr = RE::NiPointer<className>
