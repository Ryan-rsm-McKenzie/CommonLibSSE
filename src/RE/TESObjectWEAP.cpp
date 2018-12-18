#include "RE/TESObjectWEAP.h"


namespace RE
{
	float TESObjectWEAP::speed()
	{
		return data.speed;
	}


	float TESObjectWEAP::reach()
	{
		return data.reach;
	}


	float TESObjectWEAP::stagger()
	{
		return data.stagger;
	}


	float TESObjectWEAP::minRange()
	{
		return data.rangeMin;
	}


	float TESObjectWEAP::maxRange()
	{
		return data.rangeMax;
	}


	TESObjectWEAP::Data::AnimationType TESObjectWEAP::animationType()
	{
		return data.animationType;
	}


	UInt16 TESObjectWEAP::critDamage()
	{
		return criticalData.damage;
	}


	void TESObjectWEAP::GetNodeName(char* a_dstBuff)
	{
		sprintf_s(a_dstBuff, MAX_PATH, "%s  (%08X)", "Weapon", this->formID);
	}


	bool TESObjectWEAP::IsBound()
	{
		return (data.flags2 & Data::Flag2::kBoundWeapon) != Data::Flag2::kNone;
	}


	bool TESObjectWEAP::IsMelee()
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


	bool TESObjectWEAP::IsRanged()
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
}
