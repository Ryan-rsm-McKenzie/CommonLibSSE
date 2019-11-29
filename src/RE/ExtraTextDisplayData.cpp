#include "RE/ExtraTextDisplayData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


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
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraTextDisplayData::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
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
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraTextDisplayData::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
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
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraTextDisplayData::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
		GenerateName(a_form, a_temperFactor);
	}


	ExtraDataType ExtraTextDisplayData::GetType() const
	{
		return ExtraDataType::kTextDisplayData;
	}


	const char* ExtraTextDisplayData::GenerateName(TESForm* a_form, float a_temperFactor)
	{
		using func_t = function_type_t<decltype(&ExtraTextDisplayData::GenerateName)>;
		REL::Offset<func_t*> func(Offset::ExtraTextDisplayData::GenerateName);
		return func(this, a_form, a_temperFactor);
	}


	void ExtraTextDisplayData::SetName(const char* a_name)
	{
		if (message) {
			return;
		}

		name = a_name;
		rawNameLen = name.length();
		type = Type::kPlayerSet;
		temperFactor = 1.0;
	}
}
