#include "RE/NiAVObject.h"

#include "skse64/NiObjects.h"  // NiAVObject

#include "REL/Relocation.h"


namespace RE
{
	void NiAVObject::UpdateNode(ControllerUpdateContext* a_ctx)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateNode)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NiAVObject, UpdateNode, func_t*);
		return func(this, a_ctx);
	}
}
