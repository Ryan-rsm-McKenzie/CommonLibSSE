#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefVariant.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbBehaviorGraphData;

	class hkbBehaviorGraph : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBehaviorGraph;

		enum class VariableMode
		{
			kDiscardWhenActive = 0,
			kMaintainValuesWhenInactive = 1,
		};

		virtual ~hkbBehaviorGraph();  // 00

		// override (hkbGenerator)
		virtual hkClass* GetClassType() const override;															   // 01
		virtual void	 CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const;  // 02
		virtual void	 Unk_04(void) override;																	   // 04
		virtual void	 Unk_05(void) override;																	   // 05
		virtual void	 Unk_06(void) override;																	   // 06
		virtual void	 Unk_07(void) override;																	   // 07
		virtual void	 Unk_09(void) override;																	   // 09
		virtual void	 Unk_0C(void) override;																	   // 0C
		virtual void	 Unk_16(void) override;																	   // 16 - { return 1; }
		virtual void	 Unk_17(void) override;																	   // 17
		virtual void	 Unk_18(void) override;																	   // 18 - { return 1; }
		virtual void	 Unk_19(void) override;																	   // 19

		// members
		stl::enumeration<VariableMode, std::uint8_t> variableMode;					   // 048
		std::uint8_t								 pad49;							   // 049
		std::uint16_t								 pad4A;							   // 04A
		std::uint32_t								 pad4C;							   // 04C
		hkArray<hkRefVariant>						 uniqueIDPool;					   // 050
		hkRefVariant								 idToStateMachineTemplateMap;	   // 060
		hkArray<hkRefVariant>						 mirroredExternalIDMap;			   // 068
		hkRefVariant								 pseudoRandomGenerator;			   // 078
		hkRefPtr<hkbGenerator>						 rootGenerator;					   // 080
		hkRefPtr<hkbBehaviorGraphData>				 data;							   // 088
		hkRefVariant								 rootGeneratorClone;			   // 090
		hkRefVariant								 activeNodes;					   // 098
		hkRefVariant								 activeNodeTemplateToIndexMap;	   // 0A0
		hkRefVariant								 activeNodesChildrenIndices;	   // 0A8
		hkRefVariant								 globalTransitionData;			   // 0B0
		hkRefVariant								 eventIDMap;					   // 0B8
		hkRefVariant								 attributeIDMap;				   // 0C0
		hkRefVariant								 variableIDMap;					   // 0C8
		hkRefVariant								 characterPropertyIDMap;		   // 0D0
		hkRefVariant								 variableValueSet;				   // 0D8
		hkRefVariant								 nodeTemplateToCloneMap;		   // 0E0
		hkRefVariant								 nodeCloneToTemplateMap;		   // 0E8
		hkRefVariant								 stateListenerTemplateToCloneMap;  // 0F0
		hkRefVariant								 nodePartitionInfo;				   // 0F8
		std::int32_t								 numIntermediateOutputs;		   // 100
		std::uint32_t								 pad104;						   // 104
		hkArray<hkRefVariant>						 jobs;							   // 108
		hkArray<hkRefVariant>						 allPartitionMemory;			   // 118
		std::int16_t								 numStaticNodes;				   // 128
		std::int16_t								 nextUniqueID;					   // 12A
		bool										 isActive;						   // 12C
		bool										 isLinked;						   // 12D
		bool										 updateActiveNodes;				   // 12E
		bool										 stateOrTransitionChanged;		   // 12F
	};
	static_assert(sizeof(hkbBehaviorGraph) == 0x130);
}
