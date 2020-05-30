#pragma once

#include "RE/ProcessLists.h"


namespace RE
{
	class ActorTargetCheck : public ProcessLists::GetActorsFilter
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorTargetCheck;


		virtual ~ActorTargetCheck();  // 00

		// override (GetActorsFilter)
		virtual bool IsValid(Actor* a_actor) override;	// 01


		// members
		UInt64 unk08;  // 08
		UInt64 unk10;  // 10
		UInt64 unk18;  // 18
	};
	STATIC_ASSERT(sizeof(ActorTargetCheck) == 0x20);
}
