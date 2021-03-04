#include "RE/H/hkpCollidable.h"

namespace RE
{
	NiAVObject* hkpCollidable::Get3D() const
	{
		using func_t = decltype(&hkpCollidable::Get3D);
		REL::Relocation<func_t> func{ Offset::hkpCollidable::Get3D };
		return func(this);
	}
	
	void* hkpCollidable::GetOwner() const
	{
		return const_cast<void*>(adjust_pointer<const void>(this, ownerOffset));
	}
}
