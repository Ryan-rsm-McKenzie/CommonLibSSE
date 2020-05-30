#include "RE/TESActorBaseData.h"


namespace RE
{
	bool TESActorBaseData::AffectsStealthMeter() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kDoesntAffectStealthMeter) == ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::Bleeds() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kDoesntBleed) == ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsEssential() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kEssential) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsFemale() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kFemale) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsGhost() const
	{
		return GetIsGhost();
	}


	bool TESActorBaseData::IsPreset() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kIsChargenFacePreset) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsProtected() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kProtected) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsSimpleActor() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kSimpleActor) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsSummonable() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kSummonable) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsUnique() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kUnique) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::IsInvulnerable() const
	{
		return GetInvulnerable();
	}


	bool TESActorBaseData::HasAutoCalcStats() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kAutoCalcStats) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::HasBleedoutOverride() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kBleedoutOverride) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::HasPCLevelMult() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kPCLevelMult) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::Respawns() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kRespawn) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::UsesOppositeGenderAnims() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kOppositeGenderanims) != ACTOR_BASE_DATA::Flag::kNone;
	}


	bool TESActorBaseData::UsesTemplate() const
	{
		return (actorData.actorBaseFlags & ACTOR_BASE_DATA::Flag::kUsesTemplate) != ACTOR_BASE_DATA::Flag::kNone;
	}
}
