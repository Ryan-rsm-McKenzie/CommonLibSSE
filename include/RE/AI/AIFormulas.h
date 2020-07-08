#pragma once


namespace RE
{
	class Actor;
	class TESForm;


	namespace AIFormulas
	{
		SInt32 ComputePickpocketSuccess(float a_thiefSkill, float a_targetSkill, UInt32 a_valueStolen, float a_weightStolen, Actor* a_thief, Actor* a_target, bool a_isDetected, TESForm* a_itemPickpocketing);
	}
}
