#include "RE/B/bhkShape.h"

namespace RE
{
	std::uint32_t bhkShape::GetMaterialID(hkpShapeKey a_key) const
	{
		using func_t = decltype(&bhkShape::GetMaterialID);
		REL::Relocation<func_t> func{ Offset::bhkShape::GetMaterialID };
		return func(this, a_key);
	}
}
