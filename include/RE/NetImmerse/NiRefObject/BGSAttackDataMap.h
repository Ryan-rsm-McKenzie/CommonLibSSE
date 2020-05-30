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
		inline static constexpr auto RTTI = RTTI_BGSAttackDataMap;


		virtual ~BGSAttackDataMap();  // 00


		// members
		BSTHashMap<BSFixedString, NiPointer<BGSAttackData>> attackDataMap;	  // 10
		TESRace*											defaultDataRace;  // 40 - ATKR
	};
	STATIC_ASSERT(sizeof(BGSAttackDataMap) == 0x48);
}
