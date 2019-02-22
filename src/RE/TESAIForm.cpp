#include "RE/TESAIForm.h"


namespace RE
{
	TESAIForm::Aggression TESAIForm::GetAggression() const
	{
		return static_cast<Aggression>(DataPun(data.aggression1, data.aggression2).v);
	}


	TESAIForm::Confidence TESAIForm::GetConfidence() const
	{
		return static_cast<Confidence>(DataPun(data.confidence1, data.confidence2, data.confidence3).v);
	}


	UInt8 TESAIForm::GetEnergyLevel() const
	{
		return DataPun(data.energyLevel1, data.energyLevel2, data.energyLevel3, data.energyLevel4, data.energyLevel5, data.energyLevel6, data.energyLevel7, data.energyLevel8).v;
	}


	TESAIForm::Responsibility TESAIForm::GetResponsibility() const
	{
		return static_cast<Responsibility>(DataPun(data.responsibility1, data.responsibility2).v);
	}


	TESAIForm::Mood TESAIForm::GetMood() const
	{
		return static_cast<Mood>(DataPun(data.mood1, data.mood2, data.mood3).v);
	}


	TESAIForm::Assistance TESAIForm::GetAssistance() const
	{
		return static_cast<Assistance>(DataPun(data.assistance1, data.assistance2).v);
	}


	bool TESAIForm::AggroRadiusBehaviourIsEnabled() const
	{
		return data.aggroRadiusBehaviour;
	}
}
