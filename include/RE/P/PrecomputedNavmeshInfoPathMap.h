#pragma once

#include "RE/B/BSPrecomputedNavmeshInfoPathMap.h"

namespace RE
{
	class PrecomputedNavmeshInfoPathMap : public BSPrecomputedNavmeshInfoPathMap
	{
	public:
	};
	static_assert(sizeof(PrecomputedNavmeshInfoPathMap) == 0x48);
}
