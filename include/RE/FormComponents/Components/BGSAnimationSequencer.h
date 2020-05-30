#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTHashMap.h"


namespace RE
{
	class BGSActionData;


	class BGSAnimationSequencer
	{
	public:
		// members
		UInt32									  numSequences;	 // 00
		UInt32									  pad04;		 // 04
		BSTHashMap<BSFixedString, BGSActionData*> actions;		 // 08
	};
	STATIC_ASSERT(sizeof(BGSAnimationSequencer) == 0x38);
}
