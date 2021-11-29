#pragma once

#include "RE/B/BGSAttackData.h"
#include "RE/B/BSTHashMap.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	NiSmartPointer(BGSAttackDataMap);

	class BGSAttackDataMap : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAttackDataMap;

		~BGSAttackDataMap() override;  // 00

		// members
		BSTHashMap<BSFixedString, NiPointer<BGSAttackData>> attackDataMap;    // 10
		TESRace*                                            defaultDataRace;  // 40 - ATKR
	};
	static_assert(sizeof(BGSAttackDataMap) == 0x48);
}
