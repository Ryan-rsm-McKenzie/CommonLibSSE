#pragma once

#include <cassert>
#include <string>
#include <string_view>

#include "RE/MemoryManager.h"


namespace RE
{
	template <class T, UInt32 N>
	class DynamicMemoryManagementPol
	{
	public:
		using value_type = T;


		DynamicMemoryManagementPol() = default;
		DynamicMemoryManagementPol(const DynamicMemoryManagementPol&) = default;
		DynamicMemoryManagementPol(DynamicMemoryManagementPol&&) = default;
		~DynamicMemoryManagementPol() = default;

		DynamicMemoryManagementPol& operator=(const DynamicMemoryManagementPol&) = default;
		DynamicMemoryManagementPol& operator=(DynamicMemoryManagementPol&&) = default;


		[[nodiscard]] value_type* allocate(UInt32 a_num)
		{
			if (a_num > N) {
				return 0;
			}

			auto size = a_num * sizeof(value_type);
			auto mem = malloc<value_type>(size);
			std::memset(mem, 0, size);
			return mem;
		}


		void deallocate(value_type* a_ptr)
		{
			free(a_ptr);
		}
	};


	template <class T, UInt32 N>
	class FixedLengthMemoryManagementPol
	{
	public:
		using value_type = T;


		FixedLengthMemoryManagementPol() :
			_buffer{ 0 }
		{}


		FixedLengthMemoryManagementPol(const FixedLengthMemoryManagementPol& a_rhs) :
			FixedLengthMemoryManagementPol()
		{
			copy_from(a_rhs);
		}


		FixedLengthMemoryManagementPol(FixedLengthMemoryManagementPol&& a_rhs) :
			FixedLengthMemoryManagementPol()
		{
			copy_from(a_rhs);
		}


		~FixedLengthMemoryManagementPol() = default;


		FixedLengthMemoryManagementPol& operator=(const FixedLengthMemoryManagementPol& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			copy_from(a_rhs);
			return *this;
		}


		FixedLengthMemoryManagementPol& operator=(FixedLengthMemoryManagementPol&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			copy_from(a_rhs);
			return *this;
		}


		[[nodiscard]] value_type* allocate(UInt32 a_num)
		{
			return a_num > N ? 0 : _buffer;
		}


		void deallocate([[maybe_unused]] value_type* a_ptr)
		{
			return;
		}

	private:
		void copy_from(const FixedLengthMemoryManagementPol& a_rhs)
		{
			std::memcpy(_buffer, a_rhs._buffer, sizeof(value_type) * N);
		}


		value_type _buffer[N];	// 00
	};


	template <class CharT, UInt32 N, template <class, UInt32> class Allocator>
	class BSStringT : public Allocator<CharT, N>
	{
	private:
		static constexpr auto MAX = static_cast<UInt16>(N);

	public:
		using traits_type = std::char_traits<CharT>;
		using value_type = CharT;
		using allocator_type = Allocator<CharT, N>;
		using size_type = UInt16;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;


		// (constructor)
		BSStringT() :
			allocator_type(),
			_data(0),
			_size(0),
			_capacity(0),
			_pad0C(0)
		{
			set_cstr("");
		}


		BSStringT(const BSStringT& a_rhs) :
			allocator_type(a_rhs),
			_data(0),
			_size(0),
			_capacity(0),
			_pad0C(0)
		{
			set_cstr(a_rhs.c_str());
		}


		BSStringT(BSStringT&& a_rhs) :
			allocator_type(std::move(a_rhs)),
			_data(std::move(a_rhs._data)),
			_size(std::move(a_rhs._size)),
			_capacity(std::move(a_rhs._capacity)),
			_pad0C(0)
		{
			a_rhs._data = 0;
			a_rhs._size = 0;
			a_rhs._capacity = 0;
		}


		BSStringT(const value_type* a_rhs) :
			_data(0),
			_size(0),
			_capacity(0),
			_pad0C(0)
		{
			set_cstr(a_rhs);
		}


		BSStringT(const std::string_view& a_rhs)
		{
			set_cstr(a_rhs.data(), a_rhs.size());
		}


		// (destructor)
		~BSStringT()
		{
			deallocate(_data);
			_data = 0;
		}


		// operator=
		BSStringT& operator=(const BSStringT& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			static_cast<allocator_type&>(*this) = a_rhs;
			set_cstr(a_rhs.c_str());
			return *this;
		}


		BSStringT& operator=(BSStringT&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			static_cast<allocator_type&>(*this) = std::move(a_rhs);

			_data = std::move(a_rhs._data);
			a_rhs._data = 0;

			_size = std::move(a_rhs._size);
			a_rhs._size = 0;

			_capacity = std::move(a_rhs._capacity);
			a_rhs._capacity = 0;

			return *this;
		}


		BSStringT& operator=(const value_type* a_rhs)
		{
			set_cstr(a_rhs);
			return *this;
		}


		BSStringT& operator=(const std::string_view& a_rhs)
		{
			set_cstr(a_rhs.data(), a_rhs.size());
			return *this;
		}


		// Element access
		reference operator[](size_type a_pos)
		{
			assert(a_pos <= size());
			return data()[a_pos];
		}


		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos <= size());
			return data()[a_pos];
		}


		value_type& front()
		{
			return operator[](0);
		}


		const value_type& front() const
		{
			return operator[](0);
		}


		value_type& back()
		{
			return operator[](size() - 1);
		}


		const value_type& back() const
		{
			return operator[](size() - 1);
		}


		const value_type* data() const noexcept
		{
			return _data ? _data : "";
		}


		value_type* data() noexcept
		{
			return _data ? _data : "";
		}


		const value_type* c_str() const noexcept
		{
			return data();
		}


		operator std::basic_string_view<value_type>() const noexcept
		{
			return std::basic_string_view<value_type>(data(), size());
		}


		// Capacity
		[[nodiscard]] bool empty() const noexcept
		{
			return size() == 0;
		}


		size_type size() const noexcept
		{
			return _size != MAX ? _size : traits_type::length(_data);
		}


		size_type length() const noexcept
		{
			return size();
		}


		// Operations
		void clear() noexcept
		{
			set_cstr("");
		}


		inline friend bool operator==(const BSStringT& a_lhs, const value_type* a_rhs) { return (a_lhs._data == a_rhs || stricmp(a_lhs._data, a_rhs) == 0); }
		inline friend bool operator!=(const BSStringT& a_lhs, const value_type* a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const value_type* a_lhs, const BSStringT& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const value_type* a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSStringT& a_lhs, const BSStringT& a_rhs) { return a_lhs == a_rhs.c_str(); }
		inline friend bool operator!=(const BSStringT& a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSStringT& a_lhs, const std::string_view& a_rhs) { return a_lhs == a_rhs.data(); }
		inline friend bool operator!=(const BSStringT& a_lhs, const std::string_view& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const std::string_view& a_lhs, const BSStringT& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const std::string_view& a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }

		TES_HEAP_REDEFINE_NEW();


	private:
		static int stricmp(const char* a_lhs, const char* a_rhs)
		{
			return _stricmp(a_lhs, a_rhs);
		}


		static int stricmp(const wchar_t* a_lhs, const wchar_t* a_rhs)
		{
			return _wcsicmp(a_lhs, a_rhs);
		}


		[[nodiscard]] value_type* allocate(UInt32 a_num)
		{
			return allocator_type::allocate(a_num);
		}


		void deallocate(value_type* a_ptr)
		{
			allocator_type::deallocate(a_ptr);
		}


		bool set_cstr(const value_type* a_str, UInt32 a_len = 0)
		{
			if (_data == a_str) {
				return true;
			}

			if (a_len == 0) {
				a_len = traits_type::length(a_str);
			}

			size_type newSize = a_len > MAX ? MAX : a_len;
			++a_len;
			size_type newCap = a_len > MAX ? MAX : a_len;

			if (a_len <= _capacity) {
				traits_type::copy(_data, a_str, a_len);
				_size = newSize;
				return true;
			}

			auto newData = allocate(a_len);
			if (!newData) {
				return false;
			}

			traits_type::copy(newData, a_str, a_len);
			if (_data) {
				deallocate(_data);
			}
			_data = newData;
			_size = newSize;
			_capacity = newCap;
			return true;
		}


		// members
		value_type* _data;		// ?? (00)
		UInt16		_size;		// ?? (08)
		UInt16		_capacity;	// ?? (0A)
		UInt32		_pad0C;		// ?? (0C)
	};


	using BSString = BSStringT<char, static_cast<UInt32>(-1), DynamicMemoryManagementPol>;
	STATIC_ASSERT(sizeof(BSString) == 0x10);


	template <UInt32 N>
	class BSStaticStringT : public BSStringT<char, N, FixedLengthMemoryManagementPol>
	{
	public:
		using Base = BSStringT<char, N, FixedLengthMemoryManagementPol>;
		using Base::Base;
	};
}
