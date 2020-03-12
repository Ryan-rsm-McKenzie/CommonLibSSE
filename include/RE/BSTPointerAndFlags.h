#pragma once


namespace RE
{
	// 0x8
	template <class T, UInt32 MASK = 1>
	class BSTPointerAndFlags
	{
	public:
		using value_type = T;
		using element_type = typename T::element_type;


		constexpr BSTPointerAndFlags() noexcept :
			_storage()
		{}


		BSTPointerAndFlags(const BSTPointerAndFlags& a_rhs) noexcept :
			_storage()
		{
			_storage.ptr = a_rhs.get();
		}


		BSTPointerAndFlags(BSTPointerAndFlags&& a_rhs) noexcept :
			_storage()
		{
			_storage.address = std::move(a_rhs._storage.address);
			a_rhs._storage.address = 0;
		}


		constexpr BSTPointerAndFlags(std::nullptr_t) noexcept :
			_storage()
		{}


		~BSTPointerAndFlags()
		{
			clear_flags();
			_storage.ptr.~value_type();
		}


		BSTPointerAndFlags& operator=(const BSTPointerAndFlags& a_rhs) noexcept
		{
			if (this == &a_rhs) {
				return *this;
			}

			clear_flags();
			_storage.ptr = a_rhs.get();
			return *this;
		}


		BSTPointerAndFlags& operator=(BSTPointerAndFlags&& a_rhs) noexcept
		{
			if (this == &a_rhs) {
				return *this;
			}

			clear_flags();
			a_rhs.clear_flags();
			_storage.ptr = std::move(a_rhs._storage.ptr);
			return *this;
		}


		void reset() noexcept
		{
			clear_flags();
			_storage.ptr.reset();
		}


		[[nodiscard]] constexpr element_type* get() const noexcept
		{
			auto ptr = _storage.address;
			return reinterpret_cast<element_type*>(ptr & ~FLAG_MASK);
		}


		[[nodiscard]] constexpr element_type& operator*() const noexcept
		{
			assert(get() != 0);
			return *get();
		}


		[[nodiscard]] constexpr element_type* operator->() const noexcept
		{
			return get();
		}


		[[nodiscard]] explicit constexpr operator bool() const noexcept
		{
			return get() != 0;
		}

	protected:
		union Storage
		{
			Storage() :
				address(0) {}
			~Storage() {}


			value_type	   ptr;
			std::uintptr_t address;
		};


		void clear_flags()
		{
			_storage.address &= ~FLAG_MASK;
		}


		static constexpr std::uintptr_t FLAG_MASK = MASK;

		// members
		Storage _storage;  // 0
	};
}
