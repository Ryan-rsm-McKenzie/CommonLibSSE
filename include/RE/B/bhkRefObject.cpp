#include "RE/B/bhkRefObject.h"

namespace RE
{
	std::uint64_t bhkRefObject::GetProperty(std::uint32_t a_key) const
	{
		using func_t = decltype(&bhkRefObject::GetProperty);
		REL::Relocation<func_t> func{ Offset::bhkRefObject::GetProperty };
		return func(this, a_key);
	}
}
