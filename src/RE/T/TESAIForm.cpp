#include "RE/T/TESAIForm.h"

namespace RE
{
	bool TESAIForm::AggroRadiusBehaviourIsEnabled() const
	{
		return aiData.aggroRadiusBehaviour;
	}

	ACTOR_AGGRESSION TESAIForm::GetAggressionLevel() const
	{
		return static_cast<ACTOR_AGGRESSION>(stl::pun_bits(aiData.aggression1, aiData.aggression2));
	}

	ACTOR_ASSISTANCE TESAIForm::GetAssistanceLevel() const
	{
		return static_cast<ACTOR_ASSISTANCE>(stl::pun_bits(aiData.assistance1, aiData.assistance2));
	}

	ACTOR_CONFIDENCE TESAIForm::GetConfidenceLevel() const
	{
		return static_cast<ACTOR_CONFIDENCE>(stl::pun_bits(aiData.confidence1, aiData.confidence2, aiData.confidence3));
	}

	std::uint8_t TESAIForm::GetEnergyLevel() const
	{
		return static_cast<std::uint8_t>(stl::pun_bits(aiData.energyLevel1, aiData.energyLevel2, aiData.energyLevel3, aiData.energyLevel4, aiData.energyLevel5, aiData.energyLevel6, aiData.energyLevel7, aiData.energyLevel8));
	}

	ACTOR_MOOD TESAIForm::GetMoodLevel() const
	{
		return static_cast<ACTOR_MOOD>(stl::pun_bits(aiData.mood1, aiData.mood2, aiData.mood3));
	}

	ACTOR_MORALITY TESAIForm::GetMoralityLevel() const
	{
		return static_cast<ACTOR_MORALITY>(stl::pun_bits(aiData.morality1, aiData.morality1));
	}

	bool TESAIForm::NoSlowApproach() const
	{
		return aiData.noSlowApproach;
	}
}
