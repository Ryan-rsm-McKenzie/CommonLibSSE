#include "RE/TESFaction.h"

#include "RE/BGSListForm.h"
#include "RE/PlayerCharacter.h"


namespace RE
{
	bool TESFaction::CanBeOwner() const
	{
		return (flags & Flag::kCanBeOwner) != Flag::kNone;
	}


	bool TESFaction::CanPayCrimeGold() const
	{
		auto player = PlayerCharacter::GetSingleton();
		auto bounty = player->GetCrimeGold(this);
		return player->GetGoldAmount() >= bounty;
	}


	SInt32 TESFaction::GetCrimeGold() const
	{
		auto player = PlayerCharacter::GetSingleton();
		return player->GetCrimeGold(this);
	}


	SInt32 TESFaction::GetCrimeGoldNonViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		return player->GetCrimeGoldNonViolent(this);
	}


	SInt32 TESFaction::GetCrimeGoldViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		return player->GetCrimeGoldViolent(this);
	}


	SInt32 TESFaction::GetInfamy() const
	{
		auto player = PlayerCharacter::GetSingleton();
		auto it = player->crimeMap.find(const_cast<TESFaction*>(this));
		if (it != player->crimeMap.end()) {
			return it->second.nonViolentInfamy + it->second.violentInfamy;
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetInfamyNonViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		auto it = player->crimeMap.find(const_cast<TESFaction*>(this));
		if (it != player->crimeMap.end()) {
			return it->second.nonViolentInfamy;
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetInfamyViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		auto it = player->crimeMap.find(const_cast<TESFaction*>(this));
		if (it != player->crimeMap.end()) {
			return it->second.violentInfamy;
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetStolenItemValueCrime() const
	{
		auto player = PlayerCharacter::GetSingleton();
		auto it = player->stealCrimeMap.find(const_cast<TESFaction*>(this));
		if (it != player->stealCrimeMap.end()) {
			return it->second.witnessed;
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetStolenItemValueNoCrime() const
	{
		auto player = PlayerCharacter::GetSingleton();
		auto it = player->stealCrimeMap.find(const_cast<TESFaction*>(this));
		if (it != player->stealCrimeMap.end()) {
			return it->second.unwitnessed;
		} else {
			return 0;
		}
	}


	bool TESFaction::HasSpecialCombatState() const
	{
		return (flags & Flag::kSpecialCombat) != Flag::kNone;
	}


	bool TESFaction::HiddenFromNPC() const
	{
		return (flags & Flag::kHiddenFromNPC) != Flag::kNone;
	}


	bool TESFaction::IgnoresAssault() const
	{
		return (flags & Flag::kIgnoresCrimes_Assult) != Flag::kNone;
	}


	bool TESFaction::IgnoresMurder() const
	{
		return (flags & Flag::kIgnoresCrimes_Murder) != Flag::kNone;
	}


	bool TESFaction::IgnoresPickpocket() const
	{
		return (flags & Flag::kIgnoresCrimes_Pickpocket) != Flag::kNone;
	}


	bool TESFaction::IgnoresStealing() const
	{
		return (flags & Flag::kIgnoresCrimes_Stealing) != Flag::kNone;
	}


	bool TESFaction::IgnoresTrespass() const
	{
		return (flags & Flag::kIngoresCrimes_Trespass) != Flag::kNone;
	}


	bool TESFaction::IgnoresWerewolf() const
	{
		return (flags & Flag::kIgnoresCrimes_Werewolf) != Flag::kNone;
	}


	bool TESFaction::IsFactionInCrimeGroup(const TESFaction* a_other) const
	{
		auto list = sharedCrimeFactionList;
		return list && list->HasForm(a_other);
	}


	bool TESFaction::IsPlayerEnemy() const
	{
		return (flags & Flag::kPlayerIsEnemy) != Flag::kNone;
	}


	bool TESFaction::IsPlayerExpelled() const
	{
		return (flags & Flag::kPlayerIsExpelled) != Flag::kNone;
	}


	bool TESFaction::IsVendor() const
	{
		return (flags & Flag::kVendor) != Flag::kNone;
	}


	void TESFaction::ModCrimeGold(SInt32 a_amount, bool a_violent)
	{
		auto player = PlayerCharacter::GetSingleton();
		return player->ModCrimeGold(this, a_violent, a_amount);
	}


	void TESFaction::PlayerPayCrimeGold(bool a_removeStolenItems, bool a_goToJail)
	{
		auto player = PlayerCharacter::GetSingleton();
		player->PayCrimeGold(this, a_goToJail, a_removeStolenItems);
	}


	bool TESFaction::ReportsCrimesAgainstMembers() const
	{
		return (flags & Flag::kDoNotReportCrimesAgainstMembers) == Flag::kNone;
	}


	void TESFaction::SendPlayerToJail(bool a_removeInventory, bool a_realJail)
	{
		auto player = PlayerCharacter::GetSingleton();
		player->SendToJail(this, a_removeInventory, a_realJail);
	}


	void TESFaction::SetCrimeGold(SInt32 a_gold)
	{
		auto player = PlayerCharacter::GetSingleton();
		player->SetCrimeGold(this, false, a_gold);
	}


	void TESFaction::SetCrimeGoldViolent(SInt32 a_gold)
	{
		auto player = PlayerCharacter::GetSingleton();
		player->SetCrimeGold(this, true, a_gold);
	}


	bool TESFaction::TracksCrimes() const
	{
		return (flags & Flag::kTrackCrime) != Flag::kNone;
	}


	bool TESFaction::UsesCrimeGoldDefaults() const
	{
		return (flags & Flag::kCrimeGold_UseDefaults) != Flag::kNone;
	}
}
