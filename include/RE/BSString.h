#pragma once

#include <limits>  // numeric_limits
#include <string_view>  // string_view

#include <string.h>  // _stricmp

#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BSString
	{
	public:
		using value_type = char;
		using size_type = UInt16;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;


		// (constructor)
		BSString();
		BSString(const BSString& a_rhs);
		BSString(BSString&& a_rhs);
		BSString(const char* a_rhs);
		BSString(const std::string_view& a_rhs);

		// (destructor)
		~BSString();

		// operator=
		BSString& operator=(const BSString& a_rhs);
		BSString& operator=(BSString&& a_rhs);
		BSString& operator=(const char* a_rhs);
		BSString& operator=(const std::string_view& a_rhs);

		// Element access
		reference operator[](size_type a_pos);
		const_reference operator[](size_type a_pos) const;

		char& front();
		const char& front() const;

		char& back();
		const char& back() const;

		const char* data() const noexcept;
		char* data() noexcept;

		const char* c_str() const noexcept;

		operator std::string_view() const noexcept;

		// Capacity
		[[nodiscard]] bool empty() const noexcept;

		size_type size() const noexcept;

		size_type length() const noexcept;

		// Operations
		void clear() noexcept;

		inline friend bool operator==(const BSString& a_lhs, const char* a_rhs) { return (a_lhs._data == a_rhs || _stricmp(a_lhs._data, a_rhs) == 0); }
		inline friend bool operator!=(const BSString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const char* a_lhs, const BSString& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const char* a_lhs, const BSString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSString& a_lhs, const BSString& a_rhs) { return a_lhs == a_rhs.c_str(); }
		inline friend bool operator!=(const BSString& a_lhs, const BSString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSString& a_lhs, const std::string_view& a_rhs) { return a_lhs == a_rhs.data(); }
		inline friend bool operator!=(const BSString& a_lhs, const std::string_view& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const std::string_view& a_lhs, const BSString& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const std::string_view& a_lhs, const BSString& a_rhs) { return !(a_lhs == a_rhs); }

		TES_HEAP_REDEFINE_NEW();


	protected:
		enum { kMaxSize = std::numeric_limits<UInt16>::max() };


		bool set_cstr(const char* a_str, UInt32 a_len = 0);


		// members
		char*	_data;		// 00
		UInt16	_size;		// 08
		UInt16	_capacity;	// 0A
		UInt32	_pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(BSString) == 0x10);
}
