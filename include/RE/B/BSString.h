#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class T, std::uint32_t N>
	class DynamicMemoryManagementPol
	{
	public:
		using value_type = T;

		constexpr DynamicMemoryManagementPol() noexcept = default;
		DynamicMemoryManagementPol(const DynamicMemoryManagementPol&) = default;
		DynamicMemoryManagementPol(DynamicMemoryManagementPol&&) = default;
		~DynamicMemoryManagementPol() = default;

		DynamicMemoryManagementPol& operator=(const DynamicMemoryManagementPol&) = default;
		DynamicMemoryManagementPol& operator=(DynamicMemoryManagementPol&&) = default;

		[[nodiscard]] value_type* allocate(std::uint32_t a_num)
		{
			if (a_num > N) {
				return 0;
			}

			auto size = a_num * sizeof(value_type);
			auto mem = malloc<value_type>(size);
			std::memset(mem, 0, size);
			return mem;
		}

		void deallocate(value_type* a_ptr) { free(a_ptr); }
	};

	template <class T, std::uint32_t N>
	class FixedLengthMemoryManagementPol
	{
	public:
		using value_type = T;

		constexpr FixedLengthMemoryManagementPol() noexcept = default;

		FixedLengthMemoryManagementPol(const FixedLengthMemoryManagementPol& a_rhs) { copy_from(a_rhs); }
		FixedLengthMemoryManagementPol(FixedLengthMemoryManagementPol&& a_rhs) { copy_from(a_rhs); }

		~FixedLengthMemoryManagementPol() = default;

		FixedLengthMemoryManagementPol& operator=(const FixedLengthMemoryManagementPol& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				copy_from(a_rhs);
			}
			return *this;
		}

		FixedLengthMemoryManagementPol& operator=(FixedLengthMemoryManagementPol&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				copy_from(a_rhs);
			}
			return *this;
		}

		[[nodiscard]] value_type* allocate(std::uint32_t a_num)
		{
			return a_num > N ? 0 : _buffer;
		}

		void deallocate(value_type*) { return; }

	private:
		void copy_from(const FixedLengthMemoryManagementPol& a_rhs)
		{
			std::memcpy(_buffer, a_rhs._buffer, sizeof(value_type) * N);
		}

		value_type _buffer[N]{ 0 };	 // 00
	};

	template <class CharT, std::uint32_t N, template <class, std::uint32_t> class Allocator>
	class BSStringT : public Allocator<CharT, N>
	{
	private:
		static constexpr auto MAX = static_cast<std::uint16_t>(N);

	public:
		using value_type = CharT;
		using traits_type = std::char_traits<value_type>;
		using allocator_type = Allocator<value_type, N>;
		using size_type = std::uint16_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

		BSStringT()
		{
			clear();
		}

		BSStringT(const BSStringT& a_rhs) :
			allocator_type(a_rhs)
		{
			set_cstr(a_rhs.c_str());
		}

		BSStringT(BSStringT&& a_rhs) :
			allocator_type(std::move(a_rhs)),
			_data(a_rhs._data),
			_size(a_rhs._size),
			_capacity(a_rhs._capacity)
		{
			a_rhs._data = nullptr;
			a_rhs._size = 0;
			a_rhs._capacity = 0;
		}

		BSStringT(const value_type* a_rhs)
		{
			set_cstr(a_rhs);
		}

		BSStringT(const std::string_view& a_rhs)
		{
			set_cstr(a_rhs.data(), a_rhs.size());
		}

		~BSStringT()
		{
			deallocate(_data);
			_data = nullptr;
		}

		BSStringT& operator=(const BSStringT& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				static_cast<allocator_type&>(*this) = a_rhs;
				set_cstr(a_rhs.c_str());
			}
			return *this;
		}

		BSStringT& operator=(BSStringT&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				static_cast<allocator_type&>(*this) = std::move(a_rhs);

				_data = a_rhs._data;
				a_rhs._data = nullptr;

				_size = a_rhs._size;
				a_rhs._size = 0;

				_capacity = a_rhs._capacity;
				a_rhs._capacity = 0;
			}
			return *this;
		}

		BSStringT& operator=(const_pointer a_rhs)
		{
			set_cstr(a_rhs);
			return *this;
		}

		BSStringT& operator=(const std::basic_string_view<value_type>& a_rhs)
		{
			set_cstr(a_rhs.data(), a_rhs.size());
			return *this;
		}

		[[nodiscard]] constexpr reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos <= size());
			return data()[a_pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos <= size());
			return data()[a_pos];
		}

		[[nodiscard]] constexpr reference		front() noexcept { return operator[](0); }
		[[nodiscard]] constexpr const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] constexpr reference		back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] constexpr const_reference back() const noexcept { return operator[](size() - 1); }

		[[nodiscard]] constexpr pointer		  data() noexcept { return _data ? _data : EMPTY; }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return _data ? _data : EMPTY; }

		[[nodiscard]] constexpr const_pointer c_str() const noexcept { return data(); }

		[[nodiscard]] operator std::basic_string_view<value_type>() const noexcept { return { data(), size() }; }

		[[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] constexpr size_type size() const noexcept { return _size != MAX ? _size : static_cast<size_type>(traits_type::length(data())); }

		[[nodiscard]] constexpr size_type length() const noexcept { return size(); }

		void clear() { set_cstr(EMPTY); }

		[[nodiscard]] inline friend bool operator==(const BSStringT& a_lhs, const value_type* a_rhs) { return (a_lhs._data == a_rhs || stricmp(a_lhs._data, a_rhs) == 0); }
		[[nodiscard]] inline friend bool operator!=(const BSStringT& a_lhs, const value_type* a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const value_type* a_lhs, const BSStringT& a_rhs) { return a_rhs == a_lhs; }
		[[nodiscard]] inline friend bool operator!=(const value_type* a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const BSStringT& a_lhs, const BSStringT& a_rhs) { return a_lhs == a_rhs.c_str(); }
		[[nodiscard]] inline friend bool operator!=(const BSStringT& a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const BSStringT& a_lhs, const std::string_view& a_rhs) { return a_lhs == a_rhs.data(); }
		[[nodiscard]] inline friend bool operator!=(const BSStringT& a_lhs, const std::string_view& a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const std::string_view& a_lhs, const BSStringT& a_rhs) { return a_rhs == a_lhs; }
		[[nodiscard]] inline friend bool operator!=(const std::string_view& a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }

		TES_HEAP_REDEFINE_NEW();

	private:
		[[nodiscard]] static int stricmp(const char* a_lhs, const char* a_rhs) { return _stricmp(a_lhs, a_rhs); }

		[[nodiscard]] static int stricmp(const wchar_t* a_lhs, const wchar_t* a_rhs) { return _wcsicmp(a_lhs, a_rhs); }

		[[nodiscard]] pointer allocate(std::uint32_t a_num) { return allocator_type::allocate(a_num); }

		void deallocate(pointer a_ptr) { allocator_type::deallocate(a_ptr); }

		bool set_cstr(const_pointer a_str, std::uint32_t a_len = 0)
		{
			auto len = static_cast<std::uint16_t>(a_len);
			if (_data == a_str) {
				return true;
			}

			if (len == 0) {
				len = static_cast<std::uint16_t>(traits_type::length(a_str));
			}

			const size_type newSize = len > MAX ? MAX : len;
			++len;
			const size_type newCap = len > MAX ? MAX : len;

			if (len <= _capacity) {
				traits_type::copy(_data, a_str, len);
				_size = newSize;
				return true;
			}

			const auto newData = allocate(len);
			if (!newData) {
				return false;
			}

			traits_type::copy(newData, a_str, len);
			if (_data) {
				deallocate(_data);
			}

			_data = newData;
			_size = newSize;
			_capacity = newCap;
			return true;
		}

		static constexpr value_type EMPTY[]{ 0 };

		// members
		pointer		  _data{ nullptr };	 // ?? (00)
		size_type	  _size{ 0 };		 // ?? (08)
		size_type	  _capacity{ 0 };	 // ?? (0A)
		std::uint32_t _pad0C{ 0 };		 // ?? (0C)
	};

	using BSString = BSStringT<char, static_cast<std::uint32_t>(-1), DynamicMemoryManagementPol>;
	static_assert(sizeof(BSString) == 0x10);

	template <std::uint32_t N>
	class BSStaticStringT : public BSStringT<char, N, FixedLengthMemoryManagementPol>
	{
	public:
		using Base = BSStringT<char, N, FixedLengthMemoryManagementPol>;
		using Base::Base;
	};
}
