#include "RE/BSFixedString.h"

#include "skse64/GameTypes.h"  // BSFixedString

#include <cctype>  // tolower
#include <cstdint>  // uintptr_t
#include <cstring>  // strlen
#include <memory>  // pointer_traits
#include <stdexcept>  // out_of_range, length_error
#include <string>  // string

#include "RE/BSString.h"  // BSString
#include "RE/BSGlobalStringTable.h"  // BSGlobalStringTable::Entry


namespace RE
{
	BSFixedString::const_iterator::const_iterator() :
		_ptr(0)
	{}


	BSFixedString::const_iterator::const_iterator(pointer a_ptr) :
		_ptr(a_ptr)
	{}


	BSFixedString::const_iterator::reference BSFixedString::const_iterator::operator*() const
	{
		return *_ptr;
	}


	BSFixedString::const_iterator::pointer BSFixedString::const_iterator::operator->() const
	{
		return std::pointer_traits<pointer>::pointer_to(operator*());
	}


	// prefix
	BSFixedString::const_iterator& BSFixedString::const_iterator::operator++()
	{
		++_ptr;
		return *this;
	}


	// postfix
	BSFixedString::const_iterator BSFixedString::const_iterator::operator++(int)
	{
		const_iterator tmp(*this);
		operator++();
		return tmp;
	}


	// prefix
	BSFixedString::const_iterator& BSFixedString::const_iterator::operator--()
	{
		--_ptr;
		return *this;
	}


	// postfix
	BSFixedString::const_iterator BSFixedString::const_iterator::operator--(int)
	{
		const_iterator tmp(*this);
		operator--();
		return tmp;
	}


	BSFixedString::const_iterator& BSFixedString::const_iterator::operator+=(const difference_type a_off)
	{
		_ptr += a_off;
		return *this;
	}


	BSFixedString::const_iterator BSFixedString::const_iterator::operator+(const difference_type a_off) const
	{
		const_iterator tmp(*this);
		return tmp += a_off;
	}


	BSFixedString::const_iterator& BSFixedString::const_iterator::operator-=(const difference_type a_off)
	{
		return operator+=(-a_off);
	}


	BSFixedString::const_iterator BSFixedString::const_iterator::operator-(const difference_type a_off) const
	{
		const_iterator tmp(*this);
		return tmp -= a_off;
	}


	BSFixedString::const_iterator::difference_type BSFixedString::const_iterator::operator-(const const_iterator& a_rhs) const
	{
		return _ptr - a_rhs._ptr;
	}


	BSFixedString::const_iterator::reference BSFixedString::const_iterator::operator[](const difference_type a_off) const
	{
		return *(operator+(a_off));
	}


	bool BSFixedString::const_iterator::operator==(const const_iterator& a_rhs) const
	{
		return _ptr == a_rhs._ptr;
	}


	bool BSFixedString::const_iterator::operator!=(const const_iterator& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	bool BSFixedString::const_iterator::operator<(const const_iterator& a_rhs) const
	{
		return _ptr < a_rhs._ptr;
	}


	bool BSFixedString::const_iterator::operator>(const const_iterator& a_rhs) const
	{
		return a_rhs.operator<(*this);
	}


	bool BSFixedString::const_iterator::operator<=(const const_iterator& a_rhs) const
	{
		return !operator>(a_rhs);
	}


	bool BSFixedString::const_iterator::operator>=(const const_iterator& a_rhs) const
	{
		return !operator<(a_rhs);
	}


	BSFixedString::BSFixedString() :
		_data(0)
	{
		ctor_cstr("");
	}


	BSFixedString::BSFixedString(const char* a_rhs) :
		_data(0)
	{
		ctor_cstr(a_rhs);
	}


	BSFixedString::BSFixedString(const BSFixedString& a_rhs) :
		_data(0)
	{
		ctor_copy(a_rhs);
	}


	BSFixedString::BSFixedString(BSFixedString&& a_rhs) noexcept :
		_data(std::move(a_rhs._data))
	{
		a_rhs._data = 0;
	}


	BSFixedString::~BSFixedString()
	{
		dtor();
	}


	BSFixedString& BSFixedString::operator=(const BSFixedString& a_rhs)
	{
		return *set_copy(a_rhs);
	}


	BSFixedString& BSFixedString::operator=(BSFixedString&& a_rhs)
	{
		if (_data) {
			dtor();
		}

		_data = std::move(a_rhs._data);
		a_rhs._data = 0;

		return *this;
	}


	BSFixedString& BSFixedString::operator=(const char* a_rhs)
	{
		return *set_cstr(a_rhs);
	}


	BSFixedString::const_reference BSFixedString::at(size_type a_pos) const
	{
		if (a_pos >= size()) {
			std::string err = __FUNCTION__;
			err += ": ";
			err += MAKE_STR(a_pos);
			err += " (which is" + std::to_string(a_pos) + ") >= this->size() (which is" + std::to_string(this->size()) + ")";
			throw std::out_of_range(err);
		} else {
			return operator[](a_pos);
		}
	}


	BSFixedString::const_reference BSFixedString::operator[](size_type a_pos) const
	{
		return _data[a_pos];
	}


	const char& BSFixedString::front() const
	{
		return operator[](0);
	}


	const char& BSFixedString::back() const
	{
		return operator[](size() - 1);
	}


	const char* BSFixedString::data() const noexcept
	{
		return _data;
	}


	const char* BSFixedString::c_str() const noexcept
	{
		return data();
	}


	BSFixedString::const_iterator BSFixedString::begin() const noexcept
	{
		return const_iterator(std::addressof(_data[0]));
	}


	BSFixedString::const_iterator BSFixedString::cbegin() const noexcept
	{
		return begin();
	}


	BSFixedString::const_iterator BSFixedString::end() const noexcept
	{
		return const_iterator(std::addressof(_data[size()]));
	}


	BSFixedString::const_iterator BSFixedString::cend() const noexcept
	{
		return end();
	}


	BSFixedString::const_reverse_iterator BSFixedString::rbegin() const noexcept
	{
		return const_reverse_iterator(std::addressof(_data[size() - 1]));
	}


	BSFixedString::const_reverse_iterator BSFixedString::crbegin() const noexcept
	{
		return rbegin();
	}


	BSFixedString::const_reverse_iterator BSFixedString::rend() const noexcept
	{
		return const_reverse_iterator(std::addressof(_data[-1]));
	}


	BSFixedString::const_reverse_iterator BSFixedString::crend() const noexcept
	{
		return rend();
	}


	bool BSFixedString::empty() const noexcept
	{
		return size() == 0;
	}


	BSFixedString::size_type BSFixedString::size() const noexcept
	{
		size_type len = 0;
		if (_data) {
			BSGlobalStringTable::Entry* entry = (BSGlobalStringTable::Entry*)((std::uintptr_t)_data - offsetof(BSGlobalStringTable::Entry, data));
			len = entry->length & BSGlobalStringTable::Entry::kLengthMask;
		}
		return len;
	}


	BSFixedString::size_type BSFixedString::length() const noexcept
	{
		return size();
	}


	BSFixedString::size_type BSFixedString::max_size() noexcept
	{
		return 0x7FFF;
	}


	void BSFixedString::clear() noexcept
	{
		set_cstr("");
	}


	int BSFixedString::compare(const BSFixedString& a_str) const noexcept
	{
		return _stricmp(data(), a_str.data());
	}


	int BSFixedString::compare(const char* a_s) const
	{
		return _stricmp(data(), a_s);
	}


	bool BSFixedString::operator==(const BSString& a_rhs) const
	{
		return *this == a_rhs.c_str();
	}


	bool BSFixedString::operator!=(const BSString& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	BSFixedString* BSFixedString::ctor_cstr(const char* a_rhs)
	{
		using func_t = function_type_t<decltype(&BSFixedString::ctor_cstr)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSFixedString, ctor, func_t*);
		return func(this, a_rhs);
	}


	BSFixedString* BSFixedString::ctor_copy(const BSFixedString& a_rhs)
	{
		using func_t = function_type_t<decltype(&BSFixedString::ctor_copy)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSFixedString, ctor_ref, func_t*);
		return func(this, a_rhs);
	}


	void BSFixedString::dtor()
	{
		using func_t = function_type_t<decltype(&BSFixedString::dtor)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSFixedString, Release, func_t*);
		return func(this);
	}


	BSFixedString* BSFixedString::set_cstr(const char* a_rhs)
	{
		using func_t = function_type_t<decltype(&BSFixedString::set_cstr)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSFixedString, Set, func_t*);
		return func(this, a_rhs);
	}


	BSFixedString* BSFixedString::set_copy(const BSFixedString& a_rhs)
	{
		using func_t = function_type_t<decltype(&BSFixedString::set_copy)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSFixedString, Set_ref, func_t*);
		return func(this, a_rhs);
	}


	void BSFixedString::assert_out_of_range(size_type a_index, const char* a_func) const
	{
		if (a_index > size()) {
			std::string err = a_func;
			err += ": ";
			err += MAKE_STR(a_index);
			err += "(which is " + std::to_string(a_index) + ") > ";
			err += MAKE_STR(this->size());
			err += " (which is" + std::to_string(this->size()) + ")";
			throw std::out_of_range(err);
		}
	}


	void BSFixedString::assert_length_error(size_type a_count, const char* a_func) const
	{
		if (size() + a_count > max_size()) {
			std::string err = a_func;
			err += ": operation would result in ";
			err += MAKE_STR(size() > max_size());
			throw std::length_error(err);
		}
	}
}
