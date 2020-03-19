#include "RE/TESFaction.h"

#include "RE/BGSListForm.h"
#include "RE/PlayerCharacter.h"


namespace RE
{
	bool TESFaction::CanBeOwner() const
	{
		return (data.flags & FACTION_DATA::Flag::kCanBeOwner) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::CanPayCrimeGold() const
	{
		auto player = PlayerCharacter::GetSingleton();
		if (!player) {
			return false;
		}

		auto bounty = player->GetCrimeGoldValue(this);
		return player->GetGoldAmount() >= static_cast<SInt32>(bounty);
	}


	SInt32 TESFaction::GetCrimeGold() const
	{
		auto player = PlayerCharacter::GetSingleton();
		return player ? player->GetCrimeGoldValue(this) : 0;
	}


	SInt32 TESFaction::GetCrimeGoldNonViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		return player ? player->GetNonViolentCrimeGoldValue(this) : 0;
	}


	SInt32 TESFaction::GetCrimeGoldViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		return player ? player->GetViolentCrimeGoldValue(this) : 0;
	}


	SInt32 TESFaction::GetInfamy() const
	{
		auto player = PlayerCharacter::GetSingleton();
		if (!player) {
			return 0;
		}

		auto it = player->crimeGoldMap.find(const_cast<TESFaction*>(this));
		if (it != player->crimeGoldMap.end()) {
			return static_cast<SInt32>(it->second.nonViolentInfamy + it->second.violentInfamy);
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetInfamyNonViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		if (!player) {
			return 0;
		}

		auto it = player->crimeGoldMap.find(const_cast<TESFaction*>(this));
		if (it != player->crimeGoldMap.end()) {
			return static_cast<SInt32>(it->second.nonViolentInfamy);
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetInfamyViolent() const
	{
		auto player = PlayerCharacter::GetSingleton();
		if (!player) {
			return 0;
		}

		auto it = player->crimeGoldMap.find(const_cast<TESFaction*>(this));
		if (it != player->crimeGoldMap.end()) {
			return static_cast<SInt32>(it->second.violentInfamy);
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetStolenItemValueCrime() const
	{
		auto player = PlayerCharacter::GetSingleton();
		if (!player) {
			return 0;
		}

		auto it = player->stolenItemValueMap.find(const_cast<TESFaction*>(this));
		if (it != player->stolenItemValueMap.end()) {
			return static_cast<SInt32>(it->second.witnessed);
		} else {
			return 0;
		}
	}


	SInt32 TESFaction::GetStolenItemValueNoCrime() const
	{
		auto player = PlayerCharacter::GetSingleton();
		if (!player) {
			return 0;
		}

		auto it = player->stolenItemValueMap.find(const_cast<TESFaction*>(this));
		if (it != player->stolenItemValueMap.end()) {
			return static_cast<SInt32>(it->second.unwitnessed);
		} else {
			return 0;
		}
	}


	bool TESFaction::HasSpecialCombatState() const
	{
		return (data.flags & FACTION_DATA::Flag::kSpecialCombat) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::HasStealMultiplier() const
	{
		return crimeData.crimevalues.stealCrimeGoldMult > 0.0;
	}


	bool TESFaction::HiddenFromNPC() const
	{
		return (data.flags & FACTION_DATA::Flag::kHiddenFromNPC) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IgnoresAssault() const
	{
		return (data.flags & FACTION_DATA::Flag::kIgnoresCrimes_Assult) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IgnoresMurder() const
	{
		return (data.flags & FACTION_DATA::Flag::kIgnoresCrimes_Murder) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IgnoresPickpocket() const
	{
		return (data.flags & FACTION_DATA::Flag::kIgnoresCrimes_Pickpocket) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IgnoresStealing() const
	{
		return (data.flags & FACTION_DATA::Flag::kIgnoresCrimes_Stealing) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IgnoresTrespass() const
	{
		return (data.flags & FACTION_DATA::Flag::kIngoresCrimes_Trespass) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IgnoresWerewolf() const
	{
		return (data.flags & FACTION_DATA::Flag::kIgnoresCrimes_Werewolf) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IsFactionInCrimeGroup(const TESFaction* a_other) const
	{
		const auto* list = crimeData.crimeGroup;
		return list && list->HasForm(a_other);
	}


	bool TESFaction::IsPlayerEnemy() const
	{
		return (data.flags & FACTION_DATA::Flag::kPlayerIsEnemy) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IsPlayerExpelled() const
	{
		return (data.flags & FACTION_DATA::Flag::kPlayerIsExpelled) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::IsVendor() const
	{
		return (data.flags & FACTION_DATA::Flag::kVendor) != FACTION_DATA::Flag::kNone;
	}


	void TESFaction::ModCrimeGold(SInt32 a_amount, bool a_violent)
	{
		auto player = PlayerCharacter::GetSingleton();
		if (player) {
			return player->ModCrimeGoldValue(this, a_violent, a_amount);
		}
	}


	void TESFaction::PlayerPayCrimeGold(bool a_removeStolenItems, bool a_goToJail)
	{
		auto player = PlayerCharacter::GetSingleton();
		if (player) {
			player->PayFine(this, a_goToJail, a_removeStolenItems);
		}
	}


	bool TESFaction::ReportsCrimesAgainstMembers() const
	{
		return (data.flags & FACTION_DATA::Flag::kDoNotReportCrimesAgainstMembers) == FACTION_DATA::Flag::kNone;
	}


	void TESFaction::SendPlayerToJail(bool a_removeInventory, bool a_realJail)
	{
		auto player = PlayerCharacter::GetSingleton();
		if (player) {
			player->GoToPrison(this, a_removeInventory, a_realJail);
		}
	}


	void TESFaction::SetCrimeGold(SInt32 a_gold)
	{
		auto player = PlayerCharacter::GetSingleton();
		if (player) {
			player->SetCrimeGoldValue(this, false, a_gold);
		}
	}


	void TESFaction::SetCrimeGoldViolent(SInt32 a_gold)
	{
		auto player = PlayerCharacter::GetSingleton();
		if (player) {
			player->SetCrimeGoldValue(this, true, a_gold);
		}
	}


	bool TESFaction::TracksCrimes() const
	{
		return (data.flags & FACTION_DATA::Flag::kTrackCrime) != FACTION_DATA::Flag::kNone;
	}


	bool TESFaction::UsesCrimeGoldDefaults() const
	{
		return (data.flags & FACTION_DATA::Flag::kCrimeGold_UseDefaults) != FACTION_DATA::Flag::kNone;
	}
}
