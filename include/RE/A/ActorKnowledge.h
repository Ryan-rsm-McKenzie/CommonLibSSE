#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/F/FightReactions.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class DetectionListener;
	class DetectionState;

	class ActorKnowledge : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorKnowledge;

		enum class FLAGS
		{
			kNone = 0
		};

		~ActorKnowledge() override;  // 00

		// members
		ActorHandle                                     owner;                        // 10
		ActorHandle                                     target;                       // 14
		stl::enumeration<FIGHT_REACTION, std::uint32_t> factionFightReaction;         // 18
		AITimeStamp                                     shouldAttackTargetTimeStamp;  // 1C
		NiPointer<DetectionState>                       detectionState;               // 20
		BSTArray<NiPointer<DetectionListener>>          listeners;                    // 28
		stl::enumeration<FLAGS, std::uint32_t>          flags;                        // 40
		AITimeStamp                                     detectionQueuedTimeStamp;     // 44
	};
	static_assert(sizeof(ActorKnowledge) == 0x48);
}
