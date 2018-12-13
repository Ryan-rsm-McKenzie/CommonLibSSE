#include "RE/TESObjectCELL.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameForms.h"  // TESObjectCELL


namespace RE
{
	double TESObjectCELL::GetNorthRotation()
	{
		typedef double _GetNorthRotation_t(TESObjectCELL* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::TESObjectCELL*>(this)->_GetNorthRotation_GetPtr());
		_GetNorthRotation_t* _GetNorthRotation = reinterpret_cast<_GetNorthRotation_t*>(*ptr);
		return _GetNorthRotation(this);
	}
}
