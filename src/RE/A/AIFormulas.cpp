#include "RE/A/AIFormulas.h"

namespace RE
{
	namespace AIFormulas
	{
		std::int32_t ComputePickpocketSuccess(float a_thiefSkill, float a_targetSkill, std::uint32_t a_valueStolen, float a_weightStolen, Actor* a_thief, Actor* a_target, bool a_isDetected, TESForm* a_itemPickpocketing)
		{
			using func_t = decltype(ComputePickpocketSuccess);
			REL::Relocation<func_t> func{ REL::Offset(0x3D4820) };
			return func(a_thiefSkill, a_targetSkill, a_valueStolen, a_weightStolen, a_thief, a_target, a_isDetected, a_itemPickpocketing);
		}
	}
}
