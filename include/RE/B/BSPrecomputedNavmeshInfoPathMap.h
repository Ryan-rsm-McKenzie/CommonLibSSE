#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	struct BSNavmeshInfo;

	class BSPrecomputedNavmeshInfoPathMap : public BSTSingletonExplicit<BSPrecomputedNavmeshInfoPathMap>
	{
	public:
		// members
		BSTArray<BSTArray<const BSNavmeshInfo*>*>       allPaths;        // 00
		BSTHashMap<const BSNavmeshInfo*, std::uint32_t> infoToIndexMap;  // 18
	};
	static_assert(sizeof(BSPrecomputedNavmeshInfoPathMap) == 0x48);
}
