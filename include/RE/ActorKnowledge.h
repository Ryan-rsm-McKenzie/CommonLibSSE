#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActorKnowledge

#include "RE/NiRefObject.h"  // NiRefObject
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class DetectionListener;
	class DetectionState;


	class ActorKnowledge : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_ActorKnowledge;


		virtual ~ActorKnowledge();	// 00


		// members
		RefHandle								fromHandle;		// 10
		RefHandle								toHandle;		// 14
		UInt32									unk18;			// 18
		float									unk1C;			// 1C
		NiPointer<DetectionState>				detectionState;	// 20
		BSTArray<NiPointer<DetectionListener>>	listeners;		// 28
		UInt32									unk40;			// 40
		float									unk44;			// 44
	};
	STATIC_ASSERT(sizeof(ActorKnowledge) == 0x48);
}
