#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTHashMap.h"


namespace RE
{
	class BGSActionData;


	class BGSAnimationSequencer
	{
	public:
		// members
		std::uint32_t							  numSequences;	 // 00
		std::uint32_t							  pad04;		 // 04
		BSTHashMap<BSFixedString, BGSActionData*> actions;		 // 08
	};
	static_assert(sizeof(BGSAnimationSequencer) == 0x38);
}
