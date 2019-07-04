#include "RE/BSFixedString.h"

#include "skse64/GameTypes.h"  // BSFixedString

#include <cctype>  // tolower
#include <cstdint>  // uintptr_t
#include <cstring>  // strlen
#include <memory>  // pointer_traits
#include <stdexcept>  // out_of_range, length_error
#include <string>  // string

#include "RE/BSGlobalStringTable.h"  // BSGlobalStringTable::Entry


namespace RE
{
	BSFixedString::BSFixedString() :
		_data(0)
	{
		ctor_cstr("");
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


	BSFixedString::BSFixedString(const char* a_rhs) :
		_data(0)
	{
		ctor_cstr(a_rhs);
	}


	BSFixedString::BSFixedString(const std::string_view& a_rhs)
	{
		ctor_cstr(a_rhs.data());
	}


	BSFixedString::~BSFixedString()
	{
		dtor();
	}


	BSFixedString& BSFixedString::operator=(const BSFixedString& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		return *set_copy(a_rhs);
	}


	BSFixedString& BSFixedString::operator=(BSFixedString&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

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


	BSFixedString& BSFixedString::operator=(const std::string_view& a_rhs)
	{
		return *set_cstr(a_rhs.data());
	}


	auto BSFixedString::at(size_type a_pos) const
		-> const_reference
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


	auto BSFixedString::operator[](size_type a_pos) const
		-> const_reference
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
		return _data ? _data : "";
	}


	const char* BSFixedString::c_str() const noexcept
	{
		return data();
	}


	BSFixedString::operator std::string_view() const
	{
		return { data(), size() };
	}


	bool BSFixedString::empty() const
	{
		return size() == 0;
	}


	auto BSFixedString::size() const
		-> size_type
	{
		size_type len = 0;
		if (_data) {
			auto entry = reinterpret_cast<BSGlobalStringTable::Entry*>((std::uintptr_t)_data - offsetof(BSGlobalStringTable::Entry, data));
			len = entry->length & BSGlobalStringTable::Entry::kLengthMask;
		}
		return len;
	}


	auto BSFixedString::length() const
		-> size_type
	{
		return size();
	}


	auto BSFixedString::max_size() noexcept
		-> size_type
	{
		return 0x7FFF;
	}


	void BSFixedString::clear()
	{
		set_cstr("");
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
}
