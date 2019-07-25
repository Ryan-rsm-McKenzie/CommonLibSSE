#pragma once

#include <cwchar>
#include <string_view>  // string_view

#include "RE/BSGlobalStringTable.h"  // GlobalStringHandle
#include "RE/CRC.h"
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class BSFixedString
	{
	public:
		using value_type = char;
		using size_type = UInt32;
		using const_reference = const value_type&;


		// (constructor)
		BSFixedString();
		BSFixedString(const BSFixedString& a_rhs);
		BSFixedString(BSFixedString&& a_rhs) noexcept;
		BSFixedString(const char* a_rhs);
		BSFixedString(const std::string_view& a_rhs);	// must be null terminated

		// (destructor)
		~BSFixedString();

		// operator=
		BSFixedString& operator=(const BSFixedString& a_rhs);
		BSFixedString& operator=(BSFixedString&& a_rhs);
		BSFixedString& operator=(const char* a_rhs);
		BSFixedString& operator=(const std::string_view& a_rhs);	// must be null terminated

		// Element access
		const_reference at(size_type a_pos) const;

		const_reference operator[](size_type a_pos) const;

		const char& front() const;

		const char& back() const;

		const char* data() const;

		const char* c_str() const;

		operator std::string_view() const;

		// Capacity
		bool empty() const;

		size_type size() const;

		size_type length() const;

		static size_type max_size() noexcept;

		// Operations
		void clear();

		inline friend bool operator==(const BSFixedString& a_lhs, const char* a_rhs) { return a_lhs.c_str() == a_rhs || _stricmp(a_lhs.c_str(), a_rhs) == 0; }
		inline friend bool operator!=(const BSFixedString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const char* a_lhs, const BSFixedString& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const char* a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return (a_lhs == a_rhs.c_str()); }
		inline friend bool operator!=(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSFixedString& a_lhs, const std::string_view& a_rhs) { return a_lhs == a_rhs.data(); }
		inline friend bool operator!=(const BSFixedString& a_lhs, const std::string_view& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const std::string_view& a_lhs, const BSFixedString& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const std::string_view& a_lhs, const BSFixedString& a_rhs) { return !(a_rhs == a_lhs); }

		TES_HEAP_REDEFINE_NEW();


	protected:
		using proxy_t = BSGlobalStringTable::Entry;


		BSFixedString* ctor_cstr(const char* a_rhs);
		BSFixedString* ctor_copy(const BSFixedString& a_rhs);
		void dtor();
		BSFixedString* set_cstr(const char* a_rhs);
		BSFixedString* set_copy(const BSFixedString& a_rhs);
		proxy_t* get_proxy() const;


		// members
		GlobalStringHandle _data;	// 0
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);


	template <>
	struct CRC32Hash<BSFixedString>
	{
	public:
		UInt32 operator()(const BSFixedString& a_key) const
		{
			UInt32 crc32;
			Impl::CalcCRC32_64(crc32, (UInt64)a_key.c_str());
			return crc32;
		}
	};


	class BSFixedStringW
	{
	public:
		using value_type = wchar_t;
		using size_type = UInt32;
		using const_reference = const value_type &;

		// (constructor)
		BSFixedStringW();
		BSFixedStringW(const BSFixedStringW& a_rhs);
		BSFixedStringW(BSFixedStringW&& a_rhs) noexcept;
		BSFixedStringW(const wchar_t* a_rhs);
		BSFixedStringW(const std::wstring_view& a_rhs);	// must be null terminated

		// (destructor)
		~BSFixedStringW();

		// operator=
		BSFixedStringW& operator=(const BSFixedStringW& a_rhs);
		BSFixedStringW& operator=(BSFixedStringW&& a_rhs);
		BSFixedStringW& operator=(const wchar_t* a_rhs);
		BSFixedStringW& operator=(const std::wstring_view& a_rhs);	// must be null terminated

		// Element access
		const_reference at(size_type a_pos) const;

		const_reference operator[](size_type a_pos) const;

		const wchar_t& front() const;

		const wchar_t& back() const;

		const wchar_t* data() const;

		const wchar_t* c_str() const;

		operator std::wstring_view() const;

		// Capacity
		bool empty() const;

		size_type size() const;

		size_type length() const;

		// Operations
		void clear();

		inline friend bool operator==(const BSFixedStringW& a_lhs, const wchar_t* a_rhs) { return std::wcscmp(a_lhs.c_str(), a_rhs) == 0; }
		inline friend bool operator!=(const BSFixedStringW& a_lhs, const wchar_t* a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const wchar_t* a_lhs, const BSFixedStringW& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const wchar_t* a_lhs, const BSFixedStringW& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSFixedStringW& a_lhs, const BSFixedStringW& a_rhs) { return (a_lhs == a_rhs.c_str()); }
		inline friend bool operator!=(const BSFixedStringW& a_lhs, const BSFixedStringW& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSFixedStringW& a_lhs, const std::wstring_view& a_rhs) { return a_lhs == a_rhs.data(); }
		inline friend bool operator!=(const BSFixedStringW& a_lhs, const std::wstring_view& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const std::wstring_view& a_lhs, const BSFixedStringW& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const std::wstring_view& a_lhs, const BSFixedStringW& a_rhs) { return !(a_rhs == a_lhs); }

		TES_HEAP_REDEFINE_NEW();

	private:
		using proxy_t = BSGlobalStringTable::Entry;


		void ctor(const wchar_t* a_string);
		void dtor();	// post: _data == 0
		proxy_t* get_proxy() const;


		// members
		GlobalStringHandleW _data;	// 00
	};
	STATIC_ASSERT(sizeof(BSFixedStringW) == 0x8);


	template <>
	struct CRC32Hash<BSFixedStringW>
	{
	public:
		UInt32 operator()(const BSFixedStringW& a_key) const
		{
			UInt32 crc32;
			Impl::CalcCRC32_64(crc32, (UInt64)a_key.c_str());
			return crc32;
		}
	};
}
