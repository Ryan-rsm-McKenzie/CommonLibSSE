#include "RE/ExtraLock.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	LOCK_LEVEL REFR_LOCK::GetLockLevel(const TESObjectREFR* a_containerRef) const
	{
		using func_t = decltype(&REFR_LOCK::GetLockLevel);
		REL::Offset<func_t> func(Offset::REFR_LOCK::GetLockLevel);
		return func(this, a_containerRef);
	}


	void REFR_LOCK::SetLocked(bool a_locked)
	{
		if (a_locked) {
			flags |= Flag::kLocked;
		} else {
			flags &= ~Flag::kLocked;
			numTries = 0;
		}
	}
}
