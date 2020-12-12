#pragma once

#include "RE/BSCore/BSTHashMap.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/NetImmerse/NiRefObject/BGSAttackData.h"
#include "RE/NetImmerse/NiRefObject/NiRefObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"


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
	static_assert(sizeof(BGSAttackDataMap) == 0x48);
}
