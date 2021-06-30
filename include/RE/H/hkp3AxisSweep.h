#pragma once

#include "RE/H/hkAabb.h"
#include "RE/H/hkArray.h"
#include "RE/H/hkVector4.h"
#include "RE/H/hkpBroadPhase.h"

namespace RE
{
	class hkpBroadPhaseHandle;

	class hkp3AxisSweep : public hkpBroadPhase
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkp3AxisSweep;

		using BpInt = std::uint16_t;

		enum class MarkerHandling
		{
			kAddNewOverlaps,
			kIgnore,
			kRemoveNewOverlaps
		};

		class hkpBpMarker
		{
		public:
			// members
			BpInt          nodeIndex;           // 00
			BpInt          value;               // 02
			std::uint32_t  pad04;               // 04
			hkArray<BpInt> overlappingObjects;  // 08
		};
		static_assert(sizeof(hkpBpMarker) == 0x18);

		class hkpBpNode
		{
		public:
			// members
			BpInt                minY;    // 00
			BpInt                minZ;    // 02
			BpInt                maxY;    // 04
			BpInt                maxZ;    // 06
			BpInt                minX;    // 08
			BpInt                maxX;    // 0A
			std::uint32_t        pad0C;   // 0C
			hkpBroadPhaseHandle* handle;  // 10
		};
		static_assert(sizeof(hkpBpNode) == 0x18);

		class hkpBpEndPoint
		{
		public:
			// members
			BpInt value;      // 0
			BpInt nodeIndex;  // 2
		};
		static_assert(sizeof(hkpBpEndPoint) == 0x4);

		class hkpBpAxis
		{
		public:
			// members
			hkArray<hkpBpEndPoint> endPoints;  // 00
		};
		static_assert(sizeof(hkpBpAxis) == 0x10);

		~hkp3AxisSweep() override;  // 00

		// override (hkpBroadPhase)
		void           CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;                                                                                                                        // 02
		BroadPhaseType GetType() const override;                                                                                                                                                                                                // 03
		void           AddObject1(hkpBroadPhaseHandle* a_object, const hkAabbUint32& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) override;                                                                                            // 05
		void           AddObject2(hkpBroadPhaseHandle* a_object, const hkAabb& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) override;                                                                                                  // 06
		void           AddObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& a_addObjectList, const hkArrayBase<hkAabb>& a_addAabbList, hkArray<hkpBroadPhaseHandlePair>& a_newPairs) override;                                               // 07
		void           RemoveObject(hkpBroadPhaseHandle* a_object, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) override;                                                                                                                      // 08
		void           RemoveObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& a_removeObjectList, hkArray<hkpBroadPhaseHandlePair>& a_delPairsOut) override;                                                                                // 09
		std::int32_t   GetNumObjects() const override;                                                                                                                                                                                          // 0A
		void           UpdateAabbs(hkpBroadPhaseHandle* a_objects[], const hkAabb* a_aabbs, std::int32_t a_numObjects, hkArray<hkpBroadPhaseHandlePair>& a_addedPairs, hkArray<hkpBroadPhaseHandlePair>& a_removedPairs) override;              // 0B
		void           UpdateAabbsUInt32(hkpBroadPhaseHandle* a_objects[], const hkAabbUint32* a_aabbs, std::int32_t a_numObjects, hkArray<hkpBroadPhaseHandlePair>& a_addedPairs, hkArray<hkpBroadPhaseHandlePair>& a_removedPairs) override;  // 0C
		void           Defragment() override;                                                                                                                                                                                                   // 0D
		void           CheckDeterminism() override;                                                                                                                                                                                             // 0E - { return; }
		void           GetAllAabbs(hkArray<hkAabb>& a_allAabbs) const override;                                                                                                                                                                 // 0F
		void           GetAabb(const hkpBroadPhaseHandle* a_object, hkAabb& a_aabb) const override;                                                                                                                                             // 10
		void           GetExtents(hkVector4& a_worldMinOut, hkVector4& a_worldMaxOut) const override;                                                                                                                                           // 11
		void           QuerySingleAabb(const hkAabb& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) const override;                                                                                                                      // 12
		void           ReQuerySingleObject(const hkpBroadPhaseHandle* a_object, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) const override;                                                                                                   // 13
		void           QuerySingleAabbWithCollector(const hkAabb& a_aabb, hkpBroadPhaseCastCollector* a_collector) const override;                                                                                                              // 14
		bool           AreAabbsOverlapping(const hkpBroadPhaseHandle* a_bhA, const hkpBroadPhaseHandle* a_bhB) const override;                                                                                                                  // 15
		void           ShiftAllObjects(const hkVector4& a_shiftDistance, hkVector4& a_effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair>& a_newCollisionPairs) override;                                                               // 16
		void           ShiftBroadPhase(const hkVector4& a_shiftDistance, hkVector4& a_effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair>& a_newCollisionPairs) override;                                                               // 17
		void           GetOffsetLowHigh32bit(hkVector4& a_offsetLow32bit, hkVector4& a_offsetHigh32bit) const override;                                                                                                                         // 18
		void           CastRay(const hkpCastRayInput& a_input, hkpBroadPhaseCastCollector* a_collectorBase, std::int32_t a_collectorStriding) const override;                                                                                   // 19
		std::int32_t   GetAabbCacheSize() const override;                                                                                                                                                                                       // 1A
		void           CalcAabbCache1(const hkAabb& a_aabb, hkpBroadPhaseAabbCache* a_aabbCacheOut) const override;                                                                                                                             // 1B
		void           CalcAabbCache2(const hkArrayBase<hkpCollidable*>& a_overlappingCollidables, hkpBroadPhaseAabbCache* a_aabbCacheOut) const override;                                                                                      // 1C
		void           CastAabb(const hkpCastAabbInput& a_input, hkpBroadPhaseCastCollector& a_collector) const override;                                                                                                                       // 1D
		void           Set32BitOffsetAndScale(const hkVector4& a_offsetLow, const hkVector4& a_offsetHigh, const hkVector4& a_scale) override;                                                                                                  // 1E

		// members
		hkAabb             aabb;                       // 030
		hkVector4          offsetLow;                  // 050
		hkVector4          offsetHigh;                 // 060
		hkVector4          scale;                      // 070
		hkVector4          offsetLow32bit;             // 080
		hkVector4          offsetHigh32bit;            // 090
		hkVector4          scale32bit;                 // 0A0
		hkArray<hkpBpNode> nodes;                      // 0B0
		hkpBpAxis          axis[3];                    // 0C0
		std::int32_t       numMarkers;                 // 0F0
		std::int32_t       ld2NumMarkers;              // 0F4
		hkpBpMarker*       markers;                    // 0F8
		float              intToFloatFloorCorrection;  // 100
		std::uint32_t      pad104;                     // 104
		std::uint64_t      pad108;                     // 108
	};
	static_assert(sizeof(hkp3AxisSweep) == 0x110);
}
