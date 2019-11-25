#pragma once

#include "RE/BGSAttackData.h"
#include "RE/BSTHashMap.h"
#include "RE/FormTypes.h"
#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	NiSmartPointer(BGSAttackDataMap);


	class BGSAttackDataMap : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_BGSAttackDataMap;


		virtual ~BGSAttackDataMap();	// 00


		// members
		BSTHashMap<BSFixedString, BGSAttackData>	attacks;	// 10
		TESRace*									attackRace;	// 40 - ATKR
	};
	STATIC_ASSERT(sizeof(BGSAttackDataMap) == 0x48);
}
