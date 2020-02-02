#include "RE/TESDescription.h"

#include "RE/BSString.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void TESDescription::GetDescription(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType)
	{
		using func_t = decltype(&TESDescription::GetDescription);
		REL::Offset<func_t> func(Offset::TESDescription::GetDescription);
		return func(this, a_out, a_parent, a_fieldType);
	}
}
