#include "RE/BSCore/BSFixedString.h"


namespace RE
{
	BSFixedString::BSFixedString() :
		_data(nullptr)
	{
		ctor_cstr("");
	}


	BSFixedString::BSFixedString(const BSFixedString& a_rhs) :
		_data(nullptr)
	{
		ctor_copy(a_rhs);
	}


	BSFixedString::BSFixedString(BSFixedString&& a_rhs) noexcept :
		_data(std::move(a_rhs._data))
	{
		a_rhs._data = nullptr;
	}


	BSFixedString::BSFixedString(const char* a_rhs) :
		_data(nullptr)
	{
		ctor_cstr(a_rhs);
	}


	BSFixedString::BSFixedString(const std::string_view& a_rhs) :
		_data(nullptr)
	{
		ctor_cstr(a_rhs.data());
	}


	BSFixedString::~BSFixedString()
	{
		dtor();
	}


	BSFixedString& BSFixedString::operator=(const BSFixedString& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			return *set_copy(a_rhs);
		}
		return *this;
	}


	BSFixedString& BSFixedString::operator=(BSFixedString&& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			dtor();
			_data = std::move(a_rhs._data);
			a_rhs._data = nullptr;
		}
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
		return data()[a_pos];
	}


	const char& BSFixedString::front() const
	{
		return operator[](0);
	}


	const char& BSFixedString::back() const
	{
		return operator[](size() - 1);
	}


	const char* BSFixedString::data() const
	{
		return _data ? _data : "";
	}


	const char* BSFixedString::c_str() const
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
		return _data ? get_proxy()->GetLength() : 0;
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
		using func_t = decltype(&BSFixedString::ctor_cstr);
		REL::Offset<func_t> func = REL::ID(67819);
		return func(this, a_rhs);
	}


	BSFixedString* BSFixedString::ctor_copy(const BSFixedString& a_rhs)
	{
		using func_t = decltype(&BSFixedString::ctor_copy);
		REL::Offset<func_t> func = REL::ID(67820);
		return func(this, a_rhs);
	}


	void BSFixedString::dtor()
	{
		using func_t = decltype(&BSFixedString::dtor);
		REL::Offset<func_t> func = REL::ID(67822);
		return func(this);
	}


	BSFixedString* BSFixedString::set_cstr(const char* a_rhs)
	{
		using func_t = decltype(&BSFixedString::set_cstr);
		REL::Offset<func_t> func = REL::ID(67823);
		return func(this, a_rhs);
	}


	BSFixedString* BSFixedString::set_copy(const BSFixedString& a_rhs)
	{
		using func_t = decltype(&BSFixedString::set_copy);
		REL::Offset<func_t> func = REL::ID(67824);
		return func(this, a_rhs);
	}


	auto BSFixedString::get_proxy() const
		-> proxy_t*
	{
		return adjust_pointer<proxy_t>(_data, -ssizeof_v<proxy_t>);
	}


	BSFixedStringW::BSFixedStringW() :
		_data(nullptr)
	{
		ctor(L"");
	}


	BSFixedStringW::BSFixedStringW(const BSFixedStringW& a_rhs) :
		_data(nullptr)
	{
		ctor(a_rhs.c_str());
	}


	BSFixedStringW::BSFixedStringW(BSFixedStringW&& a_rhs) noexcept :
		_data(std::move(a_rhs._data))
	{
		a_rhs._data = nullptr;
	}


	BSFixedStringW::BSFixedStringW(const wchar_t* a_rhs) :
		_data(nullptr)
	{
		ctor(a_rhs);
	}


	BSFixedStringW::BSFixedStringW(const std::wstring_view& a_rhs)
	{
		ctor(a_rhs.data());
	}


	BSFixedStringW::~BSFixedStringW()
	{
		dtor();
	}


	BSFixedStringW& BSFixedStringW::operator=(const BSFixedStringW& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			dtor();
			_data = nullptr;
			ctor(a_rhs.c_str());
		}
		return *this;
	}


	BSFixedStringW& BSFixedStringW::operator=(BSFixedStringW&& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			dtor();
			_data = std::move(a_rhs._data);
			a_rhs._data = nullptr;
		}
		return *this;
	}


	BSFixedStringW& BSFixedStringW::operator=(const wchar_t* a_rhs)
	{
		dtor();
		_data = nullptr;
		ctor(a_rhs);
		return *this;
	}


	BSFixedStringW& BSFixedStringW::operator=(const std::wstring_view& a_rhs)
	{
		dtor();
		_data = nullptr;
		ctor(a_rhs.data());
		return *this;
	}


	auto BSFixedStringW::at(size_type a_pos) const
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


	auto BSFixedStringW::operator[](size_type a_pos) const
		-> const_reference
	{
		return data()[a_pos];
	}


	const wchar_t& BSFixedStringW::front() const
	{
		return operator[](0);
	}


	const wchar_t& BSFixedStringW::back() const
	{
		return operator[](size() - 1);
	}


	const wchar_t* BSFixedStringW::data() const
	{
		return _data ? get_proxy()->GetDataU16() : L"";
	}


	const wchar_t* BSFixedStringW::c_str() const
	{
		return data();
	}


	BSFixedStringW::operator std::wstring_view() const
	{
		return { data(), size() };
	}


	bool BSFixedStringW::empty() const
	{
		return size() == 0;
	}


	auto BSFixedStringW::size() const
		-> size_type
	{
		return _data ? get_proxy()->GetLength() : 0;
	}


	auto BSFixedStringW::length() const
		-> size_type
	{
		return size();
	}


	void BSFixedStringW::clear()
	{
		dtor();
		_data = nullptr;
		ctor(L"");
	}


	void BSFixedStringW::ctor(const wchar_t* a_string)
	{
		using func_t = decltype(&BSFixedStringW::ctor);
		REL::Offset<func_t> func = REL::ID(67834);
		return func(this, a_string);
	}


	void BSFixedStringW::dtor()
	{
		using func_t = decltype(&BSFixedStringW::dtor);
		REL::Offset<func_t> func = REL::ID(67836);
		return func(this);
	}


	auto BSFixedStringW::get_proxy() const
		-> proxy_t*
	{
		return adjust_pointer<proxy_t>(_data, -ssizeof_v<proxy_t>);
	}
}
