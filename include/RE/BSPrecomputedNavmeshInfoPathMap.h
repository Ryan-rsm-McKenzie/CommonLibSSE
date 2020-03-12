#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	struct BSNavmeshInfo;


	class BSPrecomputedNavmeshInfoPathMap : public BSTSingletonExplicit<BSPrecomputedNavmeshInfoPathMap>
	{
	public:
		// members
		BSTArray<BSTArray<const BSNavmeshInfo*>*> allPaths;		   // 00
		BSTHashMap<const BSNavmeshInfo*, UInt32>  infoToIndexMap;  // 18
	};
	STATIC_ASSERT(sizeof(BSPrecomputedNavmeshInfoPathMap) == 0x48);
}
