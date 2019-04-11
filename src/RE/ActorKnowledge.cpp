#include "RE/ActorKnowledge.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	SInt32 ActorKnowledge::GetDetectionState()
	{
		using func_t = function_type_t<decltype(&ActorKnowledge::GetDetectionState)>;
		REL::Offset<func_t*> func(Offset::ActorKnowledge::GetDetectionState);
		return func(this);
	}
}
