#pragma once

#include "RE/BSPathFinding/BSPrecomputedNavmeshInfoPathMap/BSPrecomputedNavmeshInfoPathMap.h"


namespace RE
{
	class PrecomputedNavmeshInfoPathMap : public BSPrecomputedNavmeshInfoPathMap
	{
	public:
	};
	STATIC_ASSERT(sizeof(PrecomputedNavmeshInfoPathMap) == 0x48);
}
