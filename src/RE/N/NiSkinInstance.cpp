#include "RE/N/NiSkinInstance.h"

namespace RE
{
	NiSkinInstance* NiSkinInstance::Create()
	{
		using func_t = decltype(&NiSkinInstance::Create);
		REL::Relocation<func_t> func{ Offset::NiSkinInstance::Ctor };
		return func();
	}
}
