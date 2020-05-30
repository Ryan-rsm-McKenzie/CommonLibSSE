#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSingleton.h"


namespace RE
{
	struct BGSFootstepEvent;


	class BGSFootstepManager :
		public BSTEventSource<BGSFootstepEvent>,	// 00
		public BSTSingletonSDM<BGSFootstepManager>	// 58
	{
	public:
		static BGSFootstepManager* GetSingleton();


		// members
		UInt8					pad59;	// 59
		UInt16					pad5A;	// 5A
		UInt32					pad5C;	// 5C
		BSTArray<BSFixedString> unk60;	// 60
		UInt64					unk78;	// 78
	};
	STATIC_ASSERT(sizeof(BGSFootstepManager) == 0x80);
}
