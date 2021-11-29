#include "RE/T/TESObjectWEAP.h"

namespace RE
{
	float TESObjectWEAP::GetSpeed() const
	{
		return weaponData.speed;
	}

	float TESObjectWEAP::GetReach() const
	{
		return weaponData.reach;
	}

	float TESObjectWEAP::GetStagger() const
	{
		return weaponData.staggerValue;
	}

	float TESObjectWEAP::GetMinRange() const
	{
		return weaponData.minRange;
	}

	float TESObjectWEAP::GetMaxRange() const
	{
		return weaponData.maxRange;
	}

	std::uint16_t TESObjectWEAP::GetCritDamage() const
	{
		return criticalData.damage;
	}

	void TESObjectWEAP::GetNodeName(char* a_dstBuff) const
	{
		sprintf_s(a_dstBuff, WinAPI::MAX_PATH, "%s  (%08X)", "Weapon", formID);
	}

	WEAPON_TYPE TESObjectWEAP::GetWeaponType() const
	{
		return *weaponData.animationType;
	}

	bool TESObjectWEAP::IsBound() const
	{
		return weaponData.flags2.all(Data::Flag2::kBoundWeapon);
	}

	bool TESObjectWEAP::IsMelee() const
	{
		switch (*weaponData.animationType) {
		case WEAPON_TYPE::kHandToHandMelee:
		case WEAPON_TYPE::kOneHandSword:
		case WEAPON_TYPE::kOneHandDagger:
		case WEAPON_TYPE::kOneHandAxe:
		case WEAPON_TYPE::kOneHandMace:
		case WEAPON_TYPE::kTwoHandSword:
		case WEAPON_TYPE::kTwoHandAxe:
			return true;
		default:
			return false;
		}
	}

	bool TESObjectWEAP::IsRanged() const
	{
		switch (*weaponData.animationType) {
		case WEAPON_TYPE::kBow:
		case WEAPON_TYPE::kStaff:
		case WEAPON_TYPE::kCrossbow:
			return true;
		default:
			return false;
		}
	}

	bool TESObjectWEAP::IsHandToHandMelee() const
	{
		return weaponData.animationType == WEAPON_TYPE::kHandToHandMelee;
	}

	bool TESObjectWEAP::IsOneHandedSword() const
	{
		return weaponData.animationType == WEAPON_TYPE::kOneHandSword;
	}

	bool TESObjectWEAP::IsOneHandedDagger() const
	{
		return weaponData.animationType == WEAPON_TYPE::kOneHandDagger;
	}

	bool TESObjectWEAP::IsOneHandedAxe() const
	{
		return weaponData.animationType == WEAPON_TYPE::kOneHandAxe;
	}

	bool TESObjectWEAP::IsOneHandedMace() const
	{
		return weaponData.animationType == WEAPON_TYPE::kOneHandMace;
	}

	bool TESObjectWEAP::IsTwoHandedSword() const
	{
		return weaponData.animationType == WEAPON_TYPE::kTwoHandSword;
	}

	bool TESObjectWEAP::IsTwoHandedAxe() const
	{
		return weaponData.animationType == WEAPON_TYPE::kTwoHandAxe;
	}

	bool TESObjectWEAP::IsBow() const
	{
		return weaponData.animationType == WEAPON_TYPE::kBow;
	}

	bool TESObjectWEAP::IsStaff() const
	{
		return weaponData.animationType == WEAPON_TYPE::kStaff;
	}

	bool TESObjectWEAP::IsCrossbow() const
	{
		return weaponData.animationType == WEAPON_TYPE::kCrossbow;
	}
}
