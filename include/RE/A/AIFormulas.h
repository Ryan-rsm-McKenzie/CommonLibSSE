#pragma once

namespace RE
{
	class Actor;
	class TESForm;

	namespace AIFormulas
	{
		std::int32_t ComputePickpocketSuccess(float a_thiefSkill, float a_targetSkill, std::uint32_t a_valueStolen, float a_weightStolen, Actor* a_thief, Actor* a_target, bool a_isDetected, TESForm* a_itemPickpocketing);
	}
}
