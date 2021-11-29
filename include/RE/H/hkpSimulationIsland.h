#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkBaseTypes.h"
#include "RE/H/hkMultiThreadCheck.h"
#include "RE/H/hkpAgentNnTrack.h"
#include "RE/H/hkpConstraintOwner.h"

namespace RE
{
	class hkpAction;
	class hkpEntity;
	class hkpWorld;

	class hkpSimulationIsland : public hkpConstraintOwner
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpSimulationIsland;

		~hkpSimulationIsland() override;  // 00

		// override (hkpConstraintOwner)
		const hkClass* GetClassType() const override;                                                                     // 01 - { return &hkpSimulationIslandClass; }
		void           CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;  // 02
		void           AddConstraintToCriticalLockedIsland(hkpConstraintInstance* a_constraint) override;                 // 03
		void           RemoveConstraintFromCriticalLockedIsland(hkpConstraintInstance* a_constraint) override;            // 04
		void           AddCallbackRequest(hkpConstraintInstance* a_constraint, std::int32_t a_request) override;          // 05

		// members
		hkpWorld*     world;                   // 20
		std::int32_t  numConstraints;          // 28
		hkObjectIndex storageIndex;            // 2C
		hkObjectIndex dirtyListIndex;          // 2E
		std::uint8_t  splitCheckFrameCounter;  // 30

		bool splitCheckRequested: 2;          // 31 - 0
		bool isSparse: 2;                     // 31 - 2
		bool actionListCleanupNeeded: 2;      // 31 - 4
		bool allowIslandLocking: 2;           // 31 - 6
		bool isInActiveIslandsArray: 2;       // 32 - 0
		bool activeMark: 2;                   // 32 - 2
		bool tryToIncreaseIslandSizeMark: 2;  // 32 - 4
		bool inIntegrateJob: 2;               // 32 - 6

		std::uint8_t                  pad33;                            // 33
		mutable hkMultiThreadCheck    multiThreadCheck;                 // 34
		float                         timeSinceLastHighFrequencyCheck;  // 40
		float                         timeSinceLastLowFrequencyCheck;   // 44
		hkArray<hkpAction*>           actions;                          // 48
		hkTime                        timeOfDeactivation;               // 58
		std::uint32_t                 pad5C;                            // 5C
		hkInplaceArray<hkpEntity*, 1> entities;                         // 60
		hkpAgentNnTrack               midphaseAgentTrack;               // 78
		hkpAgentNnTrack               narrowphaseAgentTrack;            // 98
	};
	static_assert(sizeof(hkpSimulationIsland) == 0xB8);
}
