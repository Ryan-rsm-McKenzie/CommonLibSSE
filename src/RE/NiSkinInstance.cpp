#include "RE/NiSkinInstance.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiSkinInstance* NiSkinInstance::Create()
	{
		using func_t = decltype(&NiSkinInstance::Create);
		REL::Offset<func_t> func(Offset::NiSkinInstance::Ctor);
		return func();
	}
}
