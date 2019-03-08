#include "RE/ActorKnowledge.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	SInt32 ActorKnowledge::GetDetectionState()
	{
		typedef SInt32 _GetDetectionState_t(ActorKnowledge* a_this);
		RelocAddr<_GetDetectionState_t*> _GetDetectionState(ACTOR_KNOWLEDGE_GET_DETECTION_STATE);
		return _GetDetectionState(this);
	}
}