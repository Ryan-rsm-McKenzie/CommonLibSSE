#include "RE/B/BipedAnim.h"

#include "RE/N/NiAVObject.h"

namespace RE
{
	BipedAnim::~BipedAnim()
	{
		Dtor();
		stl::memzero(this);
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
