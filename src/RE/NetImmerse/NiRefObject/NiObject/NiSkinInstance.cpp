#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance/NiSkinInstance.h"


namespace RE
{
	NiSkinInstance* NiSkinInstance::Create()
	{
		using func_t = decltype(&NiSkinInstance::Create);
		REL::Offset<func_t> func(Offset::NiSkinInstance::Ctor);
		return func();
	}
}
