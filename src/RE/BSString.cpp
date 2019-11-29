#include "RE/BSString.h"

#include <cassert>
#include <string>

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSString::BSString() :
		_data(0),
		_size(0),
		_capacity(0),
		_pad0C(0)
	{
		set_cstr("");
	}


	BSString::BSString(const BSString& a_rhs) :
		_data(0),
		_size(0),
		_capacity(0),
		_pad0C(0)
	{
		set_cstr(a_rhs.c_str());
	}


	BSString::BSString(BSString&& a_rhs) :
		_data(std::move(a_rhs._data)),
		_size(std::move(a_rhs._size)),
		_capacity(std::move(a_rhs._capacity)),
		_pad0C(0)
	{
		a_rhs._data = 0;
		a_rhs._size = 0;
		a_rhs._capacity = 0;
	}


	BSString::BSString(const char* a_rhs) :
		_data(0),
		_size(0),
		_capacity(0),
		_pad0C(0)
	{
		set_cstr(a_rhs);
	}


	BSString::BSString(const std::string_view& a_rhs)
	{
		set_cstr(a_rhs.data(), a_rhs.size());
	}


	BSString::~BSString()
	{
		free(_data);
		_data = 0;
	}


	BSString& BSString::operator=(const BSString& a_rhs)
	{
		set_cstr(a_rhs.c_str());
		return *this;
	}


	BSString& BSString::operator=(BSString&& a_rhs)
	{
		_data = std::move(a_rhs._data);
		a_rhs._data = 0;

		_size = std::move(a_rhs._size);
		a_rhs._size = 0;

		_capacity = std::move(a_rhs._capacity);
		a_rhs._capacity = 0;

		return *this;
	}


	BSString& BSString::operator=(const char* a_rhs)
	{
		set_cstr(a_rhs);
		return *this;
	}


	BSString& BSString::operator=(const std::string_view& a_rhs)
	{
		set_cstr(a_rhs.data(), a_rhs.size());
		return *this;
	}


	auto BSString::operator[](size_type a_pos)
		-> reference
	{
		return _data[a_pos];
	}


	auto BSString::operator[](size_type a_pos) const
		-> const_reference
	{
		return _data[a_pos];
	}


	char& BSString::front()
	{
		return operator[](0);
	}


	const char& BSString::front() const
	{
		return operator[](0);
	}


	char& BSString::back()
	{
		return operator[](size() - 1);
	}


	const char& BSString::back() const
	{
		return operator[](size() - 1);
	}


	const char* BSString::data() const noexcept
	{
		return _data ? _data : "";
	}


	char* BSString::data() noexcept
	{
		return _data ? _data : "";
	}


	const char* BSString::c_str() const noexcept
	{
		return data();
	}


	BSString::operator std::string_view() const noexcept
	{
		return { data(), size() };
	}


	[[nodiscard]] bool BSString::empty() const noexcept
	{
		return length() == 0;
	}


	auto BSString::size() const noexcept
		-> size_type
	{
		return (_size != kMaxSize) ? _size : std::char_traits<char>::length(_data);
	}


	auto BSString::length() const noexcept
		-> size_type
	{
		return size();
	}


	void BSString::clear() noexcept
	{
		set_cstr("");
	}


	bool BSString::set_cstr(const char* a_str, UInt32 a_len)
	{
		using func_t = function_type_t<decltype(&BSString::set_cstr)>;
		REL::Offset<func_t*> func(Offset::BSString::Set_CStr);
		return func(this, a_str, a_len);
	}
}
