#include "RE/NiSkinInstance.h"

#include "skse64/NiGeometry.h"  // NiSkinInstance

#include "REL/Relocation.h"


namespace RE
{
	NiSkinInstance* NiSkinInstance::CreateObject()
	{
		using func_t = function_type_t<decltype(&NiSkinInstance::CreateObject)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NiSkinInstance, ctor, func_t*);
		return func();
	}
}
