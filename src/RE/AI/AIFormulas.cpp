#include "RE/AI/AIFormulas.h"


namespace RE
{
	namespace AIFormulas
	{
		SInt32 ComputePickpocketSuccess(float a_thiefSkill, float a_targetSkill, UInt32 a_valueStolen, float a_weightStolen, Actor* a_thief, Actor* a_target, bool a_isDetected, TESForm* a_itemPickpocketing)
		{
			using func_t = decltype(ComputePickpocketSuccess);
			REL::Offset<func_t> func = REL::ID(25822);
			return func(a_thiefSkill, a_targetSkill, a_valueStolen, a_weightStolen, a_thief, a_target, a_isDetected, a_itemPickpocketing);
		}
	}
}
