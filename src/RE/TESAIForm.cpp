#include "RE/TESAIForm.h"


namespace RE
{
	TESAIForm::Aggression TESAIForm::GetAggression() const
	{
		return static_cast<Aggression>(pun_bits(data.aggression1, data.aggression2));
	}


	TESAIForm::Confidence TESAIForm::GetConfidence() const
	{
		return static_cast<Confidence>(pun_bits(data.confidence1, data.confidence2, data.confidence3));
	}


	UInt8 TESAIForm::GetEnergyLevel() const
	{
		return pun_bits(data.energyLevel1, data.energyLevel2, data.energyLevel3, data.energyLevel4, data.energyLevel5, data.energyLevel6, data.energyLevel7, data.energyLevel8);
	}


	TESAIForm::Responsibility TESAIForm::GetResponsibility() const
	{
		return static_cast<Responsibility>(pun_bits(data.responsibility1, data.responsibility2));
	}


	TESAIForm::Mood TESAIForm::GetMood() const
	{
		return static_cast<Mood>(pun_bits(data.mood1, data.mood2, data.mood3));
	}


	TESAIForm::Assistance TESAIForm::GetAssistance() const
	{
		return static_cast<Assistance>(pun_bits(data.assistance1, data.assistance2));
	}


	bool TESAIForm::AggroRadiusBehaviourIsEnabled() const
	{
		return data.aggroRadiusBehaviour;
	}
}
