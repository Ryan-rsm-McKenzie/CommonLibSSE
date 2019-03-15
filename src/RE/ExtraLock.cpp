#include "RE/ExtraLock.h"

#include "RE/Offsets.h"


namespace RE
{
	SInt32 LockState::GetLockLevel(const TESObjectREFR* a_containerRef)
	{
		using func_t = function_type_t<decltype(&LockState::GetLockLevel)>;
		RelocUnrestricted<func_t*> func(Offset::LockState::GetLockLevel);
		return func(this, a_containerRef);
	}
}
