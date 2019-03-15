#include "RE/ActorKnowledge.h"

#include "RE/Offsets.h"


namespace RE
{
	SInt32 ActorKnowledge::GetDetectionState()
	{
		using func_t = function_type_t<decltype(&ActorKnowledge::GetDetectionState)>;
		RelocUnrestricted<func_t*> func(Offset::ActorKnowledge::GetDetectionState);
		return func(this);
	}
}
