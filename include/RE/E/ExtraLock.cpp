#include "RE/E/ExtraLock.h"

namespace RE
{
	LOCK_LEVEL REFR_LOCK::GetLockLevel(const TESObjectREFR* a_containerRef) const
	{
		if (IsLocked()) {
			using func_t = decltype(&REFR_LOCK::GetLockLevel);
			REL::Relocation<func_t> func{ REL::ID(12272) };
			return func(this, a_containerRef);
		} else {
			return LOCK_LEVEL::kUnlocked;
		}
	}

	void REFR_LOCK::SetLocked(bool a_locked)
	{
		if (a_locked) {
			flags.set(Flag::kLocked);
		} else {
			flags.reset(Flag::kLocked);
			numTries = 0;
		}
	}
}
