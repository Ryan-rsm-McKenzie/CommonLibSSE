#include "RE/TESActorBaseData.h"


namespace RE
{
	bool TESActorBaseData::IsFemale() const
	{
		return (flags & Flag::kFemale) != Flag::kNone;
	}


	bool TESActorBaseData::IsPreset() const
	{
		return (flags & Flag::kIsChargenFacePreset) != Flag::kNone;
	}


	bool TESActorBaseData::IsEssential() const
	{
		return (flags & Flag::kEssential) != Flag::kNone;
	}


	bool TESActorBaseData::Respawns() const
	{
		return (flags & Flag::kRespawn) != Flag::kNone;
	}


	bool TESActorBaseData::HasAutoCalcStats() const
	{
		return (flags & Flag::kAutoCalcStats) != Flag::kNone;
	}


	bool TESActorBaseData::IsUnique() const
	{
		return (flags & Flag::kUnique) != Flag::kNone;
	}


	bool TESActorBaseData::AffectsStealthMeter() const
	{
		return (flags & Flag::kDoesntAffectStealthMeter) == Flag::kNone;
	}


	bool TESActorBaseData::HasPCLevelMult() const
	{
		return (flags & Flag::kPCLevelMult) != Flag::kNone;
	}


	bool TESActorBaseData::UsesTemplate() const
	{
		return (flags & Flag::kUsesTemplate) != Flag::kNone;
	}


	bool TESActorBaseData::Protected() const
	{
		return (flags & Flag::kProtected) != Flag::kNone;
	}


	bool TESActorBaseData::IsSummonable() const
	{
		return (flags & Flag::kSummonable) != Flag::kNone;
	}


	bool TESActorBaseData::Bleeds() const
	{
		return (flags & Flag::kDoesntBleed) == Flag::kNone;
	}


	bool TESActorBaseData::HasBleedoutOverride() const
	{
		return (flags & Flag::kBleedoutOverride) != Flag::kNone;
	}


	bool TESActorBaseData::UsesOppositeGenderAnims() const
	{
		return (flags & Flag::kOppositeGenderanims) != Flag::kNone;
	}


	bool TESActorBaseData::IsSimpleActor() const
	{
		return (flags & Flag::kSimpleActor) != Flag::kNone;
	}
}
