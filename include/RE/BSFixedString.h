#pragma once

#include <string_view>  // string_view

#include "RE/BSGlobalStringTable.h"  // GlobalStringHandle
#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


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
		BSFixedString(const std::string_view& a_rhs);

		// (destructor)
		~BSFixedString();

		// operator=
		BSFixedString& operator=(const BSFixedString& a_rhs);
		BSFixedString& operator=(BSFixedString&& a_rhs);
		BSFixedString& operator=(const char* a_rhs);
		BSFixedString& operator=(const std::string_view& a_rhs);

		// Element access
		const_reference at(size_type a_pos) const;

		const_reference operator[](size_type a_pos) const;

		const char& front() const;

		const char& back() const;

		const char* data() const noexcept;

		const char* c_str() const noexcept;

		operator std::string_view() const noexcept;

		// Capacity
		bool empty() const noexcept;

		size_type size() const noexcept;

		size_type length() const noexcept;

		static size_type max_size() noexcept;

		// Operations
		void clear() noexcept;

		int compare(const BSFixedString& a_rhs) const noexcept;
		int compare(const char* a_rhs) const;

		inline friend bool operator==(const BSFixedString& a_lhs, const char* a_rhs) { return a_lhs._data == a_rhs || _stricmp(a_lhs._data, a_rhs) == 0; }
		inline friend bool operator!=(const BSFixedString& a_lhs, const char* a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const char* a_lhs, const BSFixedString& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const char* a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return (a_lhs == a_rhs._data); }
		inline friend bool operator!=(const BSFixedString& a_lhs, const BSFixedString& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const BSFixedString& a_lhs, const std::string_view& a_rhs) { return a_lhs == a_rhs.data(); }
		inline friend bool operator!=(const BSFixedString& a_lhs, const std::string_view& a_rhs) { return !(a_lhs == a_rhs); }
		inline friend bool operator==(const std::string_view& a_lhs, const BSFixedString& a_rhs) { return a_rhs == a_lhs; }
		inline friend bool operator!=(const std::string_view& a_lhs, const BSFixedString& a_rhs) { return !(a_rhs == a_lhs); }

		TES_HEAP_REDEFINE_NEW();


	protected:
		BSFixedString*	ctor_cstr(const char* a_rhs);
		BSFixedString*	ctor_copy(const BSFixedString& a_rhs);
		void			dtor();
		BSFixedString*	set_cstr(const char* a_rhs);
		BSFixedString*	set_copy(const BSFixedString& a_rhs);
		void			assert_out_of_range(size_type a_index, const char* a_func) const;
		void			assert_length_error(size_type a_count, const char* a_func) const;


		// members
		GlobalStringHandle _data;	// 0
	};
	STATIC_ASSERT(sizeof(BSFixedString) == 0x8);
}
