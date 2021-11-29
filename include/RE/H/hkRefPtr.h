#pragma once

namespace RE
{
	template <class T>
	class hkRefPtr
	{
	public:
		using element_type = T;

		// 1
		inline constexpr hkRefPtr() noexcept :
			_ptr(nullptr)
		{}

		// 2
		inline constexpr hkRefPtr(std::nullptr_t) noexcept :
			_ptr(nullptr)
		{}

		// 3
		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		inline explicit hkRefPtr(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}

		// 9a
		inline hkRefPtr(const hkRefPtr& a_rhs) :
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
		inline hkRefPtr(const hkRefPtr<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 10a
		inline hkRefPtr(hkRefPtr&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
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
		inline hkRefPtr(hkRefPtr<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}

		inline ~hkRefPtr()
		{
			TryDetach();
		}

		// 1a
		inline hkRefPtr& operator=(const hkRefPtr& a_rhs)
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
		inline hkRefPtr& operator=(const hkRefPtr<Y>& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			TryAttach();
			return *this;
		}

		// 2a
		inline hkRefPtr& operator=(hkRefPtr&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
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
		inline hkRefPtr& operator=(hkRefPtr<Y>&& a_rhs)
		{
			TryDetach();
			_ptr = std::move(a_rhs._ptr);
			a_rhs._ptr = nullptr;
			return *this;
		}

		inline void reset()
		{
			TryDetach();
		}

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					element_type*>,
				int> = 0>
		inline void reset(Y* a_ptr)
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
		element_type* _ptr;  // 0
	};
	static_assert(sizeof(hkRefPtr<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] inline hkRefPtr<T> make_hkref(Args&&... a_args)
	{
		return hkRefPtr<T>{ new T(std::forward<Args>(a_args)...) };
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator==(const hkRefPtr<T1>& a_lhs, const hkRefPtr<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator!=(const hkRefPtr<T1>& a_lhs, const hkRefPtr<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const hkRefPtr<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(std::nullptr_t, const hkRefPtr<T>& a_rhs) noexcept
	{
		return !a_rhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(const hkRefPtr<T>& a_lhs, std::nullptr_t) noexcept
	{
		return static_cast<bool>(a_lhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(std::nullptr_t, const hkRefPtr<T>& a_rhs) noexcept
	{
		return static_cast<bool>(a_rhs);
	}

	template <class T>
	hkRefPtr(T*) -> hkRefPtr<T>;
}
