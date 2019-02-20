#include "RE/BSString.h"

#include "skse64/GameTypes.h"  // BSString

#include <string>  // char_traits

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/Memory.h"  // Heap_Free


namespace RE
{
	BSString::BSString() :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{}


	BSString::BSString(const BSString& a_str) :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{
		Set(a_str.c_str());
	}


	BSString::BSString(BSString&& a_str) :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{
		_data = a_str._data;
		a_str._data = 0;

		_dataLen = a_str._dataLen;
		a_str._dataLen = 0;

		_bufLen = a_str._bufLen;
		a_str._bufLen = 0;
	}


	BSString::BSString(const char* a_str) :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{
		Set(a_str);
	}


	BSString::~BSString()
	{
		if (_data) {
			Heap_Free(_data);
			_data = 0;
		}
	}


	BSString::operator const char*() const
	{
		return c_str();
	}


	BSString& BSString::operator=(const BSString& a_rhs)
	{
		Set(a_rhs.c_str());
		return *this;
	}


	BSString& BSString::operator=(BSString&& a_rhs)
	{
		_data = a_rhs._data;
		a_rhs._data = 0;

		_dataLen = a_rhs._dataLen;
		a_rhs._dataLen = 0;

		_bufLen = a_rhs._bufLen;
		a_rhs._bufLen = 0;

		return *this;
	}


	BSString& BSString::operator=(const BSFixedString& str)
	{
		return operator=(str.c_str());
	}


	BSString& BSString::operator=(const char* a_rhs)
	{
		Set(a_rhs);
		return *this;
	}


	const char* BSString::c_str() const noexcept
	{
		return _data ? _data : "";
	}


	[[nodiscard]] bool BSString::empty() const noexcept
	{
		return length() != 0;
	}


	BSString::size_type BSString::length() const noexcept
	{
		return (_dataLen != NPOS) ? _dataLen : std::char_traits<char>::length(_data);
	}


	bool BSString::operator==(const BSFixedString& a_rhs) const
	{
		return (*this == a_rhs.c_str());
	}


	bool BSString::operator!=(const BSFixedString& a_rhs) const
	{
		return !operator==(a_rhs);
	}


	bool BSString::Set(const char* a_str, UInt32 a_len)
	{
		typedef bool _Set_t(BSString* a_this, const char* a_str, UInt32 a_len);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSString*>(this)->_Set_GetPtr());
		_Set_t* _Set = reinterpret_cast<_Set_t*>(*ptr);
		return _Set(this, a_str, a_len);
	}
}
