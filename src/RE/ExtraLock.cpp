#include "RE/ExtraLock.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	SInt32 LockState::GetLockLevel(const TESObjectREFR* a_containerRef)
	{
		using func_t = function_type_t<decltype(&LockState::GetLockLevel)>;
		REL::Offset<func_t*> func(Offset::LockState::GetLockLevel);
		return func(this, a_containerRef);
	}


	void LockState::SetLocked(bool a_locked)
	{
		if (a_locked) {
			flags |= Flag::kLocked;
		} else {
			flags &= ~Flag::kLocked;
			unk14 = 0;
		}
	}
}
