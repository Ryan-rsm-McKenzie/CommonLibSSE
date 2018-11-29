#include "RE/ExtraLock.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	class TESObjectREFR;


	SInt32 LockState::GetLockLevel(const TESObjectREFR* a_containerRef)
	{
		typedef SInt32 _GetLockLevel_t(LockState* a_this, const TESObjectREFR* a_containerRef);
		static RelocAddr<_GetLockLevel_t*> _GetLockLevel(LOCK_STATE_GET_LOCK_LEVEL);
		return _GetLockLevel(this, a_containerRef);
	}
}
