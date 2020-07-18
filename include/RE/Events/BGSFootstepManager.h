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
		std::uint8_t			pad59;	// 59
		std::uint16_t			pad5A;	// 5A
		std::uint32_t			pad5C;	// 5C
		BSTArray<BSFixedString> unk60;	// 60
		std::uint64_t			unk78;	// 78
	};
	static_assert(sizeof(BGSFootstepManager) == 0x80);
}
