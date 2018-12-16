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
}
