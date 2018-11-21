#include "RE/TESActorBaseData.h"


namespace RE
{
	bool TESActorBaseData::IsFemale()
	{
		return (flags & kFlag_Female) != 0;
	}


	bool TESActorBaseData::IsPreset()
	{
		return (flags & kFlag_IsPreset) != 0;
	}


	bool TESActorBaseData::IsEssential()
	{
		return (flags & kFlag_Essential) != 0;
	}


	bool TESActorBaseData::Respawns()
	{
		return (flags & kFlag_Respawn) != 0;
	}


	bool TESActorBaseData::UsesAutoCalc()
	{
		return (flags & kFlag_AutoCalc) != 0;
	}


	bool TESActorBaseData::IsUnique()
	{
		return (flags & kFlag_Unique) != 0;
	}


	bool TESActorBaseData::AffectsStealthMeter()
	{
		return (flags & kFlag_DontAffectStealthMeter) == 0;
	}


	bool TESActorBaseData::HasPCLevelMult()
	{
		return (flags & kFlag_PCLevelMult) != 0;
	}


	bool TESActorBaseData::UsesTemplate()
	{
		return (flags & kFlag_UsesTemplate) != 0;
	}


	bool TESActorBaseData::Protected()
	{
		return (flags & kFlag_Protected) != 0;
	}


	bool TESActorBaseData::IsSummonable()
	{
		return (flags & kFlag_Summonable) != 0;
	}


	bool TESActorBaseData::Bleeds()
	{
		return (flags & kFlag_DoesntBleed) == 0;
	}


	bool TESActorBaseData::HasBleedoutOverride()
	{
		return (flags & kFlag_BleedoutOverride) != 0;
	}


	bool TESActorBaseData::UsesOppositeGenderAnims()
	{
		return (flags & kFlag_OppositeGenderanims) != 0;
	}


	bool TESActorBaseData::IsSimpleActor()
	{
		return (flags & kFlag_SimpleActor) != 0;
	}


	bool TESActorBaseData::IsGhost()
	{
		return (flags & kFlag_Ghost) != 0;
	}


	bool TESActorBaseData::IsInvulnerable()
	{
		return (flags & kFlag_Invulnerable) != 0;
	}
}
