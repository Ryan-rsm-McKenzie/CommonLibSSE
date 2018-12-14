#include "RE/ExtraTextDisplayData.h"

#include "skse64/GameExtraData.h"  // ExtraTextDisplayData


namespace RE
{
	ExtraTextDisplayData* ExtraTextDisplayData::Create()
	{
		typedef ExtraTextDisplayData* _Create_t();
		_Create_t* _Create = reinterpret_cast<_Create_t*>(GetFnAddr(&::ExtraTextDisplayData::Create));
		return _Create();
	}


	const char* ExtraTextDisplayData::GenerateName(TESForm* a_form, float a_extraHealthValue)
	{
		typedef const char* _GenerateName_t(ExtraTextDisplayData* a_this, TESForm* a_form, float a_extraHealthValue);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ExtraTextDisplayData*>(this)->_GenerateName_Internal_GetPtr());
		_GenerateName_t* _HasPerk = reinterpret_cast<_GenerateName_t*>(*ptr);
		return _HasPerk(this, a_form, a_extraHealthValue);
	}


	void ExtraTextDisplayData::SetName(const char* a_name)
	{
		typedef void _SetName_t(ExtraTextDisplayData* a_this, const char* a_name);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::ExtraTextDisplayData*>(this)->_SetName_Internal_GetPtr());
		_SetName_t* _SetName = reinterpret_cast<_SetName_t*>(*ptr);
		return _SetName(this, a_name);
	}
}
