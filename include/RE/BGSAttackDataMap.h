#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSAttackDataMap

#include "RE/BGSAttackData.h"  // BGSAttackData
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/FormTypes.h"  // TESRace
#include "RE/NiRefObject.h"  // NiRefObject
#include "RE/NiSmartPointer.h"  // NiSmartPointer


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
