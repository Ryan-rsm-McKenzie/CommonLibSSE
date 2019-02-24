#pragma once

#include "RE/BSPrecomputedNavmeshInfoPathMap.h"  // BSPrecomputedNavmeshInfoPathMap


namespace RE
{
	class PrecomputedNavmeshInfoPathMap : public BSPrecomputedNavmeshInfoPathMap
	{
	public:
	};
	STATIC_ASSERT(sizeof(PrecomputedNavmeshInfoPathMap) == 0x48);
}
