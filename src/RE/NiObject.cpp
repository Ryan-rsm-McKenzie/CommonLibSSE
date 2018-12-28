#include "RE/NiObject.h"

#include "skse64/NiObjects.h"  // NiObject


namespace RE
{
	NiStream* NiObject::DeepCopy(NiObject** a_result)
	{
		typedef NiStream* _DeepCopy_t(NiObject* a_this, NiObject** a_result);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::NiObject*>(this)->_DeepCopy_GetPtr());
		_DeepCopy_t* _DeepCopy = reinterpret_cast<_DeepCopy_t*>(*ptr);
		return _DeepCopy(this, a_result);
	}
}
