#include "RE/BSFixedString.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/Offsets.h"


namespace RE
{
	BSFixedString::BSFixedString() :
		data(0)
	{}


	BSFixedString::BSFixedString(const BSFixedString& a_str)
	{
		_CopyCtor(this, a_str);
	}


	BSFixedString::BSFixedString(BSFixedString&& a_str)
	{
		data = a_str.data;
		a_str.data = 0;
	}


	BSFixedString::BSFixedString(const char* a_str)
	{
		typedef BSFixedString* _ctor_t(BSFixedString* a_this, const char* a_str);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(this)->_ctor_GetPtr());
		static _ctor_t* _ctor = reinterpret_cast<_ctor_t*>(*ptr);

		_ctor(this, a_str);
	}


	BSFixedString::~BSFixedString()
	{
		typedef void _dtor_t(BSFixedString* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(this)->_Release_GetPtr());
		static _dtor_t* _dtor = reinterpret_cast<_dtor_t*>(*ptr);

		_dtor(this);
	}


	BSFixedString::operator const char*() const
	{
		return data;
	}


	BSFixedString& BSFixedString::operator=(const BSFixedString& a_rhs)
	{
		typedef void _dtor_t(BSFixedString* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(this)->_Release_GetPtr());
		static _dtor_t* _dtor = reinterpret_cast<_dtor_t*>(*ptr);

		if (data && data[0]) {
			_dtor(this);
		}

		return *_SetCopy(this, a_rhs);
	}


	BSFixedString& BSFixedString::operator=(BSFixedString&& a_rhs)
	{
		data = a_rhs.data;
		a_rhs.data = 0;

		return *this;
	}


	BSFixedString& BSFixedString::operator=(const char* a_rhs)
	{
		typedef void _dtor_t(BSFixedString* a_this);
		static uintptr_t* ptr1 = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(this)->_Release_GetPtr());
		static _dtor_t* _dtor = reinterpret_cast<_dtor_t*>(*ptr1);

		typedef BSFixedString* _Set_t(BSFixedString* a_this, const char* a_rhs);
		static uintptr_t* ptr2 = reinterpret_cast<uintptr_t*>(reinterpret_cast<::BSFixedString*>(this)->_Set_GetPtr());
		static _Set_t* _Set = reinterpret_cast<_Set_t*>(*ptr2);


		if (data && data[0]) {
			_dtor(this);
		}

		return *_Set(this, a_rhs);
	}


	bool BSFixedString::operator==(const char* a_str) const
	{
		return (data == a_str || _stricmp(data, a_str) == 0);
	}


	bool BSFixedString::operator!=(const char* a_str) const
	{
		return !(*this == a_str);
	}


	bool BSFixedString::operator==(const BSFixedString& a_rhs) const
	{
		return data == a_rhs.data;
	}


	bool BSFixedString::operator!=(const BSFixedString& a_rhs) const
	{
		return data != a_rhs.data;
	}


	const char* BSFixedString::c_str(void) const
	{
		return data;
	}


	RelocAddr<BSFixedString::_CopyCtor_t*> BSFixedString::_CopyCtor(BS_FIXED_STRING_COPY_CTOR);
	RelocAddr<BSFixedString::_SetCopy_t*> BSFixedString::_SetCopy(BS_FIXED_STRING_SET_COPY);
}
