#include "RE/TESDescription.h"

#include "skse64/GameFormComponents.h"  // TESDescription

#include "RE/BSString.h"  // BSString


namespace RE
{
	void TESDescription::Get(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType)
	{
		typedef void _Get_t(TESDescription* a_this, BSString& a_out, TESForm* a_parent, UInt32 a_fieldType);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESDescription*>(this)->_Get_GetPtr());
		_Get_t* _Get = reinterpret_cast<_Get_t*>(*ptr);
		_Get(this, a_out, a_parent, a_fieldType);
	}
}
