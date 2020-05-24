#include "RE/BipedAnim.h"

#include "RE/NiAVObject.h"


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
		REL::Offset<func_t> func(Offset::BipedAnim::RemoveAllParts);
		return func(this);
	}


	void BipedAnim::Dtor()
	{
		using func_t = decltype(&BipedAnim::Dtor);
		REL::Offset<func_t> func(Offset::BipedAnim::Dtor);
		return func(this);
	}
}
