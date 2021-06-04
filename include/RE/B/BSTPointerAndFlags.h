#pragma once

namespace RE
{
	// 0x8
	template <class T, std::uintptr_t MASK = 1>
	class BSTPointerAndFlags
	{
	public:
		using value_type = T;
		using element_type = typename T::element_type;

		constexpr BSTPointerAndFlags() noexcept = default;

		BSTPointerAndFlags(const BSTPointerAndFlags& a_rhs) { _storage.ptr = a_rhs.get(); }

		constexpr BSTPointerAndFlags(BSTPointerAndFlags&& a_rhs) noexcept
		{
			_storage.address = a_rhs._storage.address;
			a_rhs._storage.address = 0;
		}

		constexpr BSTPointerAndFlags(std::nullptr_t) noexcept {}

		~BSTPointerAndFlags()
		{
			clear_flags();
			_storage.ptr.~value_type();
			_storage.address = 0;
		}

		BSTPointerAndFlags& operator=(const BSTPointerAndFlags& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				clear_flags();
				_storage.ptr = a_rhs.get();
			}
			return *this;
		}

		BSTPointerAndFlags& operator=(BSTPointerAndFlags&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				clear_flags();
				a_rhs.clear_flags();
				_storage.address = a_rhs._storage.address;
				a_rhs.storage.address = 0;
			}
			return *this;
		}

		void reset() noexcept
		{
			clear_flags();
			_storage.ptr.reset();
		}

		[[nodiscard]] element_type* get() const noexcept
		{
			auto ptr = _storage.address;
			return reinterpret_cast<element_type*>(ptr & ~FLAG_MASK);
		}

		[[nodiscard]] element_type& operator*() const noexcept
		{
			assert(get() != nullptr);
			return *get();
		}

		[[nodiscard]] element_type* operator->() const noexcept { return get(); }

		[[nodiscard]] explicit operator bool() const noexcept { return get() != nullptr; }

	protected:
		union Storage
		{
			~Storage() noexcept {}

			value_type     ptr;
			std::uintptr_t address{ 0 };
		};

		constexpr void clear_flags() noexcept { _storage.address &= ~FLAG_MASK; }

		static constexpr std::uintptr_t FLAG_MASK = MASK;

		// members
		Storage _storage;  // 0
	};
}
