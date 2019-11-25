#pragma once

#include "RE/BSTSingleton.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"


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
