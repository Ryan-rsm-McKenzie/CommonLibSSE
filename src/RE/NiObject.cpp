#include "RE/NiObject.h"


namespace RE
{
	void NiObject::CreateDeepCopy(NiPointer<NiObject>& a_result)
	{
		using func_t = decltype(&NiObject::CreateDeepCopy);
		REL::Offset<func_t> func(Offset::NiObject::CreateDeepCopy);
		return func(this, a_result);
	}
}
