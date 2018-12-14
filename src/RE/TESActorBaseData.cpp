#include "RE/TESActorBaseData.h"


namespace RE
{
	bool TESActorBaseData::IsFemale()
	{
		return (flags & Flag::kFemale) != Flag::kNone;
	}


	bool TESActorBaseData::IsPreset()
	{
		return (flags & Flag::kIsChargenFacePreset) != Flag::kNone;
	}


	bool TESActorBaseData::IsEssential()
	{
		return (flags & Flag::kEssential) != Flag::kNone;
	}


	bool TESActorBaseData::Respawns()
	{
		return (flags & Flag::kRespawn) != Flag::kNone;
	}


	bool TESActorBaseData::HasAutoCalcStats()
	{
		return (flags & Flag::kAutoCalcStats) != Flag::kNone;
	}


	bool TESActorBaseData::IsUnique()
	{
		return (flags & Flag::kUnique) != Flag::kNone;
	}


	bool TESActorBaseData::AffectsStealthMeter()
	{
		return (flags & Flag::kDoesntAffectStealthMeter) == Flag::kNone;
	}


	bool TESActorBaseData::HasPCLevelMult()
	{
		return (flags & Flag::kPCLevelMult) != Flag::kNone;
	}


	bool TESActorBaseData::UsesTemplate()
	{
		return (flags & Flag::kUsesTemplate) != Flag::kNone;
	}


	bool TESActorBaseData::Protected()
	{
		return (flags & Flag::kProtected) != Flag::kNone;
	}


	bool TESActorBaseData::IsSummonable()
	{
		return (flags & Flag::kSummonable) != Flag::kNone;
	}


	bool TESActorBaseData::Bleeds()
	{
		return (flags & Flag::kDoesntBleed) == Flag::kNone;
	}


	bool TESActorBaseData::HasBleedoutOverride()
	{
		return (flags & Flag::kBleedoutOverride) != Flag::kNone;
	}


	bool TESActorBaseData::UsesOppositeGenderAnims()
	{
		return (flags & Flag::kOppositeGenderanims) != Flag::kNone;
	}


	bool TESActorBaseData::IsSimpleActor()
	{
		return (flags & Flag::kSimpleActor) != Flag::kNone;
	}
}
