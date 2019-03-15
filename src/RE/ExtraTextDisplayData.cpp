#include "RE/ExtraTextDisplayData.h"

#include "skse64/GameExtraData.h"  // ExtraTextDisplayData


namespace RE
{
	ExtraTextDisplayData* ExtraTextDisplayData::Create()
	{
		using func_t = function_type_t<decltype(&ExtraTextDisplayData::Create)>;
		func_t* func = function_cast<func_t*>(&::ExtraTextDisplayData::Create);
		return func();
	}


	const char* ExtraTextDisplayData::GenerateName(TESForm* a_form, float a_extraHealthValue)
	{
		using func_t = function_type_t<decltype(&ExtraTextDisplayData::GenerateName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ExtraTextDisplayData, GenerateName_Internal, func_t*);
		return func(this, a_form, a_extraHealthValue);
	}


	void ExtraTextDisplayData::SetName(const char* a_name)
	{
		using func_t = function_type_t<decltype(&ExtraTextDisplayData::SetName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ExtraTextDisplayData, SetName_Internal, func_t*);
		return func(this, a_name);
	}
}
