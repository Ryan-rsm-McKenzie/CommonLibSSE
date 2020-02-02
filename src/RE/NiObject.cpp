#include "RE/NiObject.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void NiObject::CreateDeepCopy(NiPointer<NiObject>& a_result)
	{
		using func_t = decltype(&NiObject::CreateDeepCopy);
		REL::Offset<func_t> func(Offset::NiObject::CreateDeepCopy);
		return func(this, a_result);
	}
}
