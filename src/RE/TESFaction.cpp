#include "RE/TESFaction.h"


namespace RE
{
	bool TESFaction::HiddenFromNPC()
	{
		return (factionFlags & kFactionFlag_HiddenFromNPC) != 0;
	}


	bool TESFaction::HasSpecialCombatState()
	{
		return (factionFlags & kFactionFlag_SpecialCombat) != 0;
	}


	bool TESFaction::TracksCrimes()
	{
		return (factionFlags & kFactionFlag_TrackCrime) != 0;
	}


	bool TESFaction::IgnoresMurder()
	{
		return (factionFlags & kFactionFlag_IgnoreMurder) != 0;
	}


	bool TESFaction::IgnoresAssault()
	{
		return (factionFlags & kFactionFlag_IgnoreAssult) != 0;
	}


	bool TESFaction::IgnoresPickpocket()
	{
		return (factionFlags & kFactionFlag_IgnorePickPocket) != 0;
	}


	bool TESFaction::IngoresStealing()
	{
		return (factionFlags & kFactionFlag_IngoreStealing) != 0;
	}


	bool TESFaction::ReportsCrimes()
	{
		return (factionFlags & kFactionFlag_DoReportCrimes) != 0;
	}


	bool TESFaction::UsesCrimeGoldDefaults()
	{
		return (factionFlags & kFactionFlag_CrimeGoldDefaults) != 0;
	}


	bool TESFaction::IgnoresTrespassing()
	{
		return (factionFlags & kFactionFlag_IgnoreTrespass) != 0;
	}


	bool TESFaction::IsVendor()
	{
		return (factionFlags & kFactionFlag_Vendor) != 0;
	}


	bool TESFaction::CanBeOwner()
	{
		return (factionFlags & kFactionFlag_CanBeOwner) != 0;
	}


	bool TESFaction::IgnoresWerewolf()
	{
		return (factionFlags & kFactionFlag_IgnoreWerewolf) != 0;
	}
}
