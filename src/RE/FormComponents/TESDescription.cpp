#include "RE/FormComponents/TESDescription.h"

#include "RE/BSCore/BSString.h"


namespace RE
{
	void TESDescription::GetDescription(BSString& a_out, TESForm* a_parent, std::uint32_t a_fieldType)
	{
		using func_t = decltype(&TESDescription::GetDescription);
		REL::Offset<func_t> func(Offset::TESDescription::GetDescription);
		return func(this, a_out, a_parent, a_fieldType);
	}
}
