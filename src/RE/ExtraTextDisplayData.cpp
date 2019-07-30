#include "RE/ExtraTextDisplayData.h"

#include "skse64/GameExtraData.h"  // ExtraTextDisplayData, s_ExtraTextDisplayVtbl


namespace RE
{
	ExtraTextDisplayData::ExtraTextDisplayData() :
		BSExtraData(),
		name(""),
		message(0),
		owner(0),
		type(Type::kDefault),
		temperFactor(1.0),
		rawNameLen(0),
		pad32(0),
		pad34(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraTextDisplayVtbl.GetUIntPtr();
	}


	ExtraTextDisplayData::ExtraTextDisplayData(const char* a_name) :
		BSExtraData(),
		name(""),
		message(0),
		owner(0),
		type(Type::kDefault),
		temperFactor(1.0),
		rawNameLen(0),
		pad32(0),
		pad34(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraTextDisplayVtbl.GetUIntPtr();
		SetName(a_name);
	}


	ExtraTextDisplayData::ExtraTextDisplayData(TESForm* a_form, float a_temperFactor) :
		BSExtraData(),
		name(""),
		message(0),
		owner(0),
		type(Type::kDefault),
		temperFactor(1.0),
		rawNameLen(0),
		pad32(0),
		pad34(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraTextDisplayVtbl.GetUIntPtr();
		GenerateName(a_form, a_temperFactor);
	}


	ExtraDataType ExtraTextDisplayData::GetType() const
	{
		return ExtraDataType::kTextDisplayData;
	}


	const char* ExtraTextDisplayData::GenerateName(TESForm* a_form, float a_temperFactor)
	{
		using func_t = function_type_t<decltype(&ExtraTextDisplayData::GenerateName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ExtraTextDisplayData, GenerateName_Internal, func_t*);
		return func(this, a_form, a_temperFactor);
	}


	void ExtraTextDisplayData::SetName(const char* a_name)
	{
		using func_t = function_type_t<decltype(&ExtraTextDisplayData::SetName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ExtraTextDisplayData, SetName_Internal, func_t*);
		return func(this, a_name);
	}
}
