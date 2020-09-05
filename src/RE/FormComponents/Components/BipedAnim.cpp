#include "RE/FormComponents/Components/BipedAnim.h"

#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiAVObject.h"


namespace RE
{
	BipedAnim::~BipedAnim()
	{
		Dtor();
		memzero(this);
	}


	void BipedAnim::RemoveAllParts()
	{
		using func_t = decltype(&BipedAnim::RemoveAllParts);
		REL::Relocation<func_t> func{ Offset::BipedAnim::RemoveAllParts };
		return func(this);
	}


	void BipedAnim::Dtor()
	{
		using func_t = decltype(&BipedAnim::Dtor);
		REL::Relocation<func_t> func{ Offset::BipedAnim::Dtor };
		return func(this);
	}
}
