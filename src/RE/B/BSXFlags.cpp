#include "RE/B/BSXFlags.h"

namespace RE
{
	auto BSXFlags::GetFlags() const
		-> Flag
	{
		return static_cast<Flag>(value);
	}

	void BSXFlags::SetFlags(Flag a_flags)
	{
		value = stl::to_underlying(a_flags);
	}
}
