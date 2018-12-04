#include "RE/TESObjectWEAP.h"


namespace RE
{
	float TESObjectWEAP::speed()
	{
		return gameData.speed;
	}


	float TESObjectWEAP::reach()
	{
		return gameData.reach;
	}


	float TESObjectWEAP::stagger()
	{
		return gameData.stagger;
	}


	float TESObjectWEAP::minRange()
	{
		return gameData.minRange;
	}


	float TESObjectWEAP::maxRange()
	{
		return gameData.maxRange;
	}


	TESObjectWEAP::GameData::Type TESObjectWEAP::type()
	{
		return gameData.type;
	}


	UInt16 TESObjectWEAP::critDamage()
	{
		return critData.critDamage;
	}


	void TESObjectWEAP::GetNodeName(char* a_dstBuff)
	{
		sprintf_s(a_dstBuff, MAX_PATH, "%s  (%08X)", "Weapon", this->formID);
	}
}
