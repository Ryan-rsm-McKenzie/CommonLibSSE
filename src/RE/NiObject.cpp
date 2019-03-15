#include "RE/NiObject.h"

#include "skse64/NiObjects.h"  // NiObject


namespace RE
{
	NiStream* NiObject::DeepCopy(NiObject*& a_result)
	{
		using func_t = function_type_t<decltype(&NiObject::DeepCopy)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NiObject, DeepCopy, func_t*);
		return func(this, a_result);
	}
}
