#include "RE/ActorKnowledge.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	DetectionState* ActorKnowledge::GetDetectionState(UInt32 a_level)
	{
		using func_t = function_type_t<decltype(&ActorKnowledge::GetDetectionState)>;
		REL::Offset<func_t*> func(Offset::ActorKnowledge::GetDetectionState);
		return func(this, a_level);
	}
}
