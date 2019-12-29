#include "RE/ExtraFlags.h"


namespace RE
{
	bool ExtraFlags::IsActivationBlocked() const
	{
		return (flags & Flag::kBlockActivate) != Flag::kNone;
	}
}
