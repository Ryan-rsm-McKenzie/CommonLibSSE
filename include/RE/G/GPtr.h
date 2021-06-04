#pragma once

namespace RE
{
	template <class T>
	class GPtr
	{
	public:
		using element_type = T;

		// 1
		inline constexpr GPtr() noexcept :
			_ptr(nullptr)
		{}

		// 2
		inline constexpr GPtr(std::nullptr_t) noexcept :
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
		inline explicit GPtr(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}

		// 9a
		inline GPtr(const GPtr& a_rhs) :
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
		inline GPtr(const GPtr<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 10a
		inline GPtr(GPtr&& a_rhs) noexcept :
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
		inline GPtr(GPtr<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}

		inline ~GPtr()
		{
			TryDetach();
		}

		// 1a
		inline GPtr& operator=(const GPtr& a_rhs)
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
		inline GPtr& operator=(const GPtr<Y>& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			TryAttach();
			return *this;
		}

		// 2a
		inline GPtr& operator=(GPtr&& a_rhs)
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
		inline GPtr& operator=(GPtr<Y>&& a_rhs)
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
		friend class GPtr;

		inline void TryAttach()
		{
			if (_ptr) {
				_ptr->AddRef();
			}
		}

		inline void TryDetach()
		{
			if (_ptr) {
				_ptr->Release();
				_ptr = nullptr;
			}
		}

		// members
		element_type* _ptr;  // 0
	};
	//static_assert(sizeof(GPtr<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] inline GPtr<T> make_gptr(Args&&... a_args)
	{
		auto ptr = GPtr<T>{ new T(std::forward<Args>(a_args)...) };
		if (ptr) {
			ptr->Release();  // ensure lifetime ends with smart pointer
		}
		return ptr;
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator==(const GPtr<T1>& a_lhs, const GPtr<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator!=(const GPtr<T1>& a_lhs, const GPtr<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const GPtr<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(std::nullptr_t, const GPtr<T>& a_rhs) noexcept
	{
		return !a_rhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(const GPtr<T>& a_lhs, std::nullptr_t) noexcept
	{
		return static_cast<bool>(a_lhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(std::nullptr_t, const GPtr<T>& a_rhs) noexcept
	{
		return static_cast<bool>(a_rhs);
	}

	template <class T>
	GPtr(T*) -> GPtr<T>;
}
