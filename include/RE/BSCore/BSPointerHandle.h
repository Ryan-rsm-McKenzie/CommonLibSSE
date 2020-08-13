#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class HandleManager;
	class Projectile;
	class TESObjectREFR;

	template <std::uint32_t = 21, std::uint32_t = 5>
	class BSUntypedPointerHandle;

	template <class, class = BSUntypedPointerHandle<>>
	class BSPointerHandle;

	template <class, class = HandleManager>
	class BSPointerHandleManagerInterface;

	template <std::uint32_t FREE_LIST_BITS, std::uint32_t AGE_SHIFT>
	class BSUntypedPointerHandle
	{
	public:
		using value_type = std::uint32_t;

		enum : std::uint32_t
		{
			kFreeListBits = FREE_LIST_BITS,
			kAgeShift = AGE_SHIFT,
		};

		constexpr BSUntypedPointerHandle() noexcept = default;
		constexpr BSUntypedPointerHandle(const BSUntypedPointerHandle&) noexcept = default;

		constexpr BSUntypedPointerHandle(BSUntypedPointerHandle&& a_rhs) noexcept :
			_handle(a_rhs._handle)
		{
			a_rhs.reset();
		}

		constexpr BSUntypedPointerHandle(value_type a_handle) noexcept :
			_handle(a_handle)
		{}

		~BSUntypedPointerHandle() noexcept { reset(); }

		constexpr BSUntypedPointerHandle& operator=(const BSUntypedPointerHandle&) noexcept = default;

		constexpr BSUntypedPointerHandle& operator=(BSUntypedPointerHandle&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_handle = a_rhs._handle;
				a_rhs.reset();
			}
			return *this;
		}

		constexpr BSUntypedPointerHandle& operator=(value_type a_rhs) noexcept
		{
			_handle = a_rhs;
			return *this;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept { return has_value(); }
		[[nodiscard]] constexpr bool	 has_value() const noexcept { return _handle != 0; }

		[[nodiscard]] constexpr value_type value() const noexcept { return _handle; }

		constexpr void reset() noexcept { _handle = 0; }

		[[nodiscard]] friend constexpr bool operator==(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs) noexcept
		{
			return a_lhs.value() == a_rhs.value();
		}

		[[nodiscard]] friend constexpr bool operator!=(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs) noexcept
		{
			return !(a_lhs == a_rhs);
		}

	private:
		// members
		value_type _handle{ 0 };  // 0
	};

	extern template class BSUntypedPointerHandle<>;

	template <class T, class Handle>
	class BSPointerHandle :
		protected Handle  // 00
	{
	public:
		using native_handle_type = typename Handle::value_type;

		constexpr BSPointerHandle() noexcept = default;
		constexpr BSPointerHandle(const BSPointerHandle&) noexcept = default;
		constexpr BSPointerHandle(BSPointerHandle&&) noexcept = default;

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					T*>,
				int> = 0>
		explicit BSPointerHandle(Y* a_rhs)
		{
			get_handle(a_rhs);
		}

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					T*>,
				int> = 0>
		constexpr BSPointerHandle(const BSPointerHandle<Y, Handle>& a_rhs) noexcept :
			Handle(a_rhs)
		{}

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					T*>,
				int> = 0>
		constexpr BSPointerHandle(BSPointerHandle<Y, Handle>&& a_rhs) noexcept :
			Handle(std::move(a_rhs))
		{}

		constexpr BSPointerHandle& operator=(const BSPointerHandle&) noexcept = default;
		constexpr BSPointerHandle& operator=(BSPointerHandle&&) noexcept = default;

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					T*>,
				int> = 0>
		BSPointerHandle& operator=(Y* a_rhs)
		{
			get_handle(a_rhs);
			return *this;
		}

		template <
			class Y,
			std::enable_if_t<
				std::is_convertible_v<
					Y*,
					T*>,
				int> = 0>
		constexpr BSPointerHandle& operator=(const BSPointerHandle<Y, Handle>& a_rhs) noexcept
		{
			Handle::operator=(a_rhs);
			return *this;
		}

		~BSPointerHandle() noexcept = default;

		using Handle::reset;

		[[nodiscard]] NiPointer<T> get() const
		{
			NiPointer<T> ptr;
			get_smartptr(ptr);
			return ptr;
		}

		[[nodiscard]] constexpr native_handle_type native_handle() noexcept
		{
			return Handle::value();
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept { return Handle::has_value(); }

		[[nodiscard]] friend constexpr bool operator==(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs) noexcept
		{
			return static_cast<const Handle&>(a_lhs) == static_cast<const Handle&>(a_rhs);
		}

		[[nodiscard]] friend constexpr bool operator!=(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs) noexcept
		{
			return !(a_lhs == a_rhs);
		}

	private:
		void get_handle(T* a_ptr);
		bool get_smartptr(NiPointer<T>& a_refPtr) const;
	};

	extern template class BSPointerHandle<Actor>;
	extern template class BSPointerHandle<Projectile>;
	extern template class BSPointerHandle<TESObjectREFR>;

	using ActorHandle = BSPointerHandle<Actor>;
	using ProjectileHandle = BSPointerHandle<Projectile>;
	using ObjectRefHandle = BSPointerHandle<TESObjectREFR>;

	template <class T, class Manager>
	class BSPointerHandleManagerInterface
	{
	public:
		using value_type = T;

		static BSPointerHandle<T> GetHandle(T* a_ptr)
		{
			using func_t = decltype(&BSPointerHandleManagerInterface<T, Manager>::GetHandle);
			REL::Relocation<func_t> func{ REL::ID(15967) };
			return func(a_ptr);
		}

		static bool GetSmartPointer(const BSPointerHandle<T>& a_handle, NiPointer<T>& a_smartPointerOut)
		{
			using func_t = decltype(&BSPointerHandleManagerInterface<T, Manager>::GetSmartPointer);
			REL::Relocation<func_t> func{ REL::ID(12204) };
			return func(a_handle, a_smartPointerOut);
		}
	};

	extern template class BSPointerHandleManagerInterface<Actor>;
	extern template class BSPointerHandleManagerInterface<Projectile>;
	extern template class BSPointerHandleManagerInterface<TESObjectREFR>;

	template <class T, class Handle>
	void BSPointerHandle<T, Handle>::get_handle(T* a_ptr)
	{
		*this = BSPointerHandleManagerInterface<T>::GetHandle(a_ptr);
	}

	template <class T, class Handle>
	bool BSPointerHandle<T, Handle>::get_smartptr(NiPointer<T>& a_smartPointerOut) const
	{
		return BSPointerHandleManagerInterface<T>::GetSmartPointer(*this, a_smartPointerOut);
	}
}
