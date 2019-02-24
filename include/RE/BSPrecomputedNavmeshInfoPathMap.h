#pragma once

#include "RE/BSTSingleton.h"  // BSTSingletonExplicit
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	class BSPrecomputedNavmeshInfoPathMap : public BSTSingletonExplicit<BSPrecomputedNavmeshInfoPathMap>
	{
	public:
		// members
		BSTArray<void*>					unk00;	// 00
		BSTHashMap<UnkKey, UnkValue>	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(BSPrecomputedNavmeshInfoPathMap) == 0x48);
}
