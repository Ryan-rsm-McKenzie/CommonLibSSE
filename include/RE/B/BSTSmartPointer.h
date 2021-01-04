#pragma once

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

		// 1
		inline constexpr BSTSmartPointer() noexcept :
			_ptr(nullptr)
		{}

		// 2
		inline constexpr BSTSmartPointer(std::nullptr_t) noexcept :
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
		inline explicit BSTSmartPointer(Y* a_rhs) :
			_ptr(a_rhs)
		{
			TryAttach();
		}

		// 9a
		inline BSTSmartPointer(const BSTSmartPointer& a_rhs) :
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
		inline BSTSmartPointer(const BSTSmartPointer<Y>& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		// 10a
		inline BSTSmartPointer(BSTSmartPointer&& a_rhs) noexcept :
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
		inline BSTSmartPointer(BSTSmartPointer<Y>&& a_rhs) noexcept :
			_ptr(std::move(a_rhs._ptr))
		{
			a_rhs._ptr = nullptr;
		}

		inline ~BSTSmartPointer()
		{
			TryDetach();
		}

		// 1a
		inline BSTSmartPointer& operator=(const BSTSmartPointer& a_rhs)
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
		inline BSTSmartPointer& operator=(const BSTSmartPointer<Y>& a_rhs)
		{
			TryDetach();
			_ptr = a_rhs._ptr;
			TryAttach();
			return *this;
		}

		// 2a
		inline BSTSmartPointer& operator=(BSTSmartPointer&& a_rhs)
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
		inline BSTSmartPointer& operator=(BSTSmartPointer<Y>&& a_rhs)
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
		template <class, template <class> class>
		friend class BSTSmartPointer;

		inline void TryAttach()
		{
			if (_ptr) {
				reference_manager::Acquire(_ptr);
			}
		}

		inline void TryDetach()
		{
			if (_ptr) {
				reference_manager::Release(_ptr);
				_ptr = nullptr;
			}
		}

		// members
		element_type* _ptr;	 // 0
	};
	static_assert(sizeof(BSTSmartPointer<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] inline BSTSmartPointer<T> make_smart(Args&&... a_args)
	{
		return BSTSmartPointer<T>{ new T(std::forward<Args>(a_args)...) };
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator==(const BSTSmartPointer<T1>& a_lhs, const BSTSmartPointer<T2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T1, class T2>
	[[nodiscard]] constexpr bool operator!=(const BSTSmartPointer<T1>& a_lhs, const BSTSmartPointer<T2>& a_rhs)
	{
		return !(a_lhs == a_rhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const BSTSmartPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(std::nullptr_t, const BSTSmartPointer<T>& a_rhs) noexcept
	{
		return !a_rhs;
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(const BSTSmartPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return static_cast<bool>(a_lhs);
	}

	template <class T>
	[[nodiscard]] constexpr bool operator!=(std::nullptr_t, const BSTSmartPointer<T>& a_rhs) noexcept
	{
		return static_cast<bool>(a_rhs);
	}

	template <class T>
	BSTSmartPointer(T*) -> BSTSmartPointer<T, BSTSmartPointerIntrusiveRefCount>;

	template <class T>
	using BSTAutoPointer = BSTSmartPointer<T, BSTSmartPointerAutoPtr>;
	static_assert(sizeof(BSTAutoPointer<void*>) == 0x8);
}

#define BSSmartPointer(className) \
	class className;              \
	using className##Ptr = RE::BSTSmartPointer<className>;
