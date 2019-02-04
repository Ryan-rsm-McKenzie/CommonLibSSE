#include "RE/NiAVObject.h"

#include "skse64/NiObjects.h"  // NiAVObject


namespace RE
{
	void NiAVObject::UpdateNode(ControllerUpdateContext* a_ctx)
	{
		typedef void _UpdateNode_t(NiAVObject* a_this, ControllerUpdateContext* a_ctx);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::NiAVObject*>(this)->_UpdateNode_GetPtr());
		_UpdateNode_t* _UpdateNode = reinterpret_cast<_UpdateNode_t*>(*ptr);
		_UpdateNode(this, a_ctx);
	}
}
