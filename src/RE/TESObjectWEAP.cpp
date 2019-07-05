#include "RE/TESObjectWEAP.h"


namespace RE
{
	float TESObjectWEAP::GetSpeed()
	{
		return data.speed;
	}


	float TESObjectWEAP::GetReach()
	{
		return data.reach;
	}


	float TESObjectWEAP::GetStagger()
	{
		return data.stagger;
	}


	float TESObjectWEAP::GetMinRange()
	{
		return data.rangeMin;
	}


	float TESObjectWEAP::GetMaxRange()
	{
		return data.rangeMax;
	}


	TESObjectWEAP::Data::AnimationType TESObjectWEAP::GetAnimationType()
	{
		return data.animationType;
	}


	UInt16 TESObjectWEAP::GetCritDamage()
	{
		return criticalData.damage;
	}


	void TESObjectWEAP::GetNodeName(char* a_dstBuff)
	{
		sprintf_s(a_dstBuff, MAX_PATH, "%s  (%08X)", "Weapon", this->formID);
	}


	bool TESObjectWEAP::IsBound() const
	{
		return (data.flags2 & Data::Flag2::kBoundWeapon) != Data::Flag2::kNone;
	}


	bool TESObjectWEAP::IsMelee() const
	{
		switch (data.animationType) {
		case Data::AnimationType::kHandToHandMelee:
		case Data::AnimationType::kOneHandSword:
		case Data::AnimationType::kOneHandDagger:
		case Data::AnimationType::kOneHandAxe:
		case Data::AnimationType::kOneHandMace:
		case Data::AnimationType::kTwoHandSword:
		case Data::AnimationType::kTwoHandAxe:
			return true;
		default:
			return false;
		}
	}


	bool TESObjectWEAP::IsRanged() const
	{
		switch (data.animationType) {
		case Data::AnimationType::kBow:
		case Data::AnimationType::kStaff:
		case Data::AnimationType::kCrossbow:
			return true;
		default:
			return false;
		}
	}


	bool TESObjectWEAP::IsHandToHandMelee() const
	{
		return data.animationType == Data::AnimationType::kHandToHandMelee;
	}


	bool TESObjectWEAP::IsOneHandedSword() const
	{
		return data.animationType == Data::AnimationType::kOneHandSword;
	}


	bool TESObjectWEAP::IsOneHandedDagger() const
	{
		return data.animationType == Data::AnimationType::kOneHandDagger;
	}


	bool TESObjectWEAP::IsOneHandedAxe() const
	{
		return data.animationType == Data::AnimationType::kOneHandAxe;
	}


	bool TESObjectWEAP::IsOneHandedMace() const
	{
		return data.animationType == Data::AnimationType::kOneHandMace;
	}


	bool TESObjectWEAP::IsTwoHandedSword() const
	{
		return data.animationType == Data::AnimationType::kTwoHandSword;
	}


	bool TESObjectWEAP::IsTwoHandedAxe() const
	{
		return data.animationType == Data::AnimationType::kTwoHandAxe;
	}


	bool TESObjectWEAP::IsBow() const
	{
		return data.animationType == Data::AnimationType::kBow;
	}


	bool TESObjectWEAP::IsStaff() const
	{
		return data.animationType == Data::AnimationType::kStaff;
	}


	bool TESObjectWEAP::IsCrossbow() const
	{
		return data.animationType == Data::AnimationType::kCrossbow;
	}
}
