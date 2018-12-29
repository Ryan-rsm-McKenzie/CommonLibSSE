#include "RE/TESFaction.h"


namespace RE
{
	bool TESFaction::HiddenFromNPC()
	{
		return (flags & Flag::kHiddenFromNPC) != Flag::kNone;
	}


	bool TESFaction::HasSpecialCombatState()
	{
		return (flags & Flag::kSpecialCombat) != Flag::kNone;
	}


	bool TESFaction::TracksCrimes()
	{
		return (flags & Flag::kTrackCrime) != Flag::kNone;
	}


	bool TESFaction::IgnoresMurder()
	{
		return (flags & Flag::kIgnoresCrimes_Murder) != Flag::kNone;
	}


	bool TESFaction::IgnoresAssault()
	{
		return (flags & Flag::kIgnoresCrimes_Assult) != Flag::kNone;
	}


	bool TESFaction::IgnoresStealing()
	{
		return (flags & Flag::kIgnoresCrimes_Stealing) != Flag::kNone;
	}


	bool TESFaction::IgnoresTrespass()
	{
		return (flags & Flag::kIngoresCrimes_Trespass) != Flag::kNone;
	}


	bool TESFaction::ReportsCrimesAgainstMembers()
	{
		return (flags & Flag::kDoNotReportCrimesAgainstMembers) == Flag::kNone;
	}


	bool TESFaction::UsesCrimeGoldDefaults()
	{
		return (flags & Flag::kCrimeGold_UseDefaults) != Flag::kNone;
	}


	bool TESFaction::IgnoresPickpocket()
	{
		return (flags & Flag::kIgnoresCrimes_Pickpocket) != Flag::kNone;
	}


	bool TESFaction::IsVendor()
	{
		return (flags & Flag::kVendor) != Flag::kNone;
	}


	bool TESFaction::CanBeOwner()
	{
		return (flags & Flag::kCanBeOwner) != Flag::kNone;
	}


	bool TESFaction::IgnoresWerewolf()
	{
		return (flags & Flag::kIgnoresCrimes_Werewolf) != Flag::kNone;
	}
}
