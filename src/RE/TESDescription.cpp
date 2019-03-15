#include "RE/TESDescription.h"

#include "skse64/GameFormComponents.h"  // TESDescription

#include "RE/BSString.h"  // BSString


namespace RE
{
	void TESDescription::GetDescription(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType)
	{
		using func_t = function_type_t<decltype(&TESDescription::GetDescription)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::TESDescription, Get, func_t*);
		return func(this, a_out, a_parent, a_fieldType);
	}
}
