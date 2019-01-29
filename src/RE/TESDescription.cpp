#include "RE/TESDescription.h"

#include "skse64/GameFormComponents.h"  // TESDescription

#include "RE/BSString.h"  // BSString


namespace RE
{
	void TESDescription::GetDescription(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType)
	{
		typedef void _GetDescription_t(TESDescription* a_this, BSString& a_out, TESForm* a_parent, UInt32 a_fieldType);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESDescription*>(this)->_Get_GetPtr());
		_GetDescription_t* _GetDescription = reinterpret_cast<_GetDescription_t*>(*ptr);
		_GetDescription(this, a_out, a_parent, a_fieldType);
	}
}
