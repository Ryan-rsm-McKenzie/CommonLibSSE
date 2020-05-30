#pragma once

#include "RE/hkArray.h"
#include "RE/hkMultiThreadCheck.h"
#include "RE/hkReferencedObject.h"
#include "RE/hkVector4.h"


namespace RE
{
	class hkAabb;
	class hkCriticalSection;
	class hkpBroadPhaseCastCollector;
	class hkpBroadPhaseHandle;
	class hkpBroadPhaseHandlePair;
	class hkpCollidable;
	struct hkAabbUint32;


	using hkpBroadPhaseAabbCache = char;


	class hkpBroadPhase : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpBroadPhase;


		enum class BroadPhaseType : UInt16
		{
			k16Bit,
			k32Bit,
			kHybrid
		};


		enum class Capabilities : UInt32
		{
			kNone = 0,
			kRayCast = 1 << 0,
			kLinearCast = 1 << 1,
			kAABBQuery = 1 << 2,
			kClosestPoints = 1 << 3,
			kCharProxyInt = 1 << 4,
			kISASweepAndPrune = 1 << 12
		};


		struct hkpCastRayInput
		{
		public:
			// members
			hkVector4					  from;			  // 00
			SInt32						  numCasts;		  // 10
			UInt32						  pad14;		  // 14
			const hkVector4*			  toBase;		  // 18
			SInt32						  toStriding;	  // 20
			UInt32						  pad24;		  // 24
			const hkpBroadPhaseAabbCache* aabbCacheInfo;  // 28
		};
		STATIC_ASSERT(sizeof(hkpCastRayInput) == 0x30);


		struct hkpCastAabbInput
		{
		public:
			// members
			hkVector4					  from;			  // 00
			hkVector4					  to;			  // 10
			hkVector4					  halfExtents;	  // 20
			const hkpBroadPhaseAabbCache* aabbCacheInfo;  // 30
			UInt64						  pad38;		  // 38
		};
		STATIC_ASSERT(sizeof(hkpCastAabbInput) == 0x40);


		virtual ~hkpBroadPhase();  // 00

		// add
		virtual BroadPhaseType		 GetType() const = 0;																																														   // 03
		virtual const hkpBroadPhase* GetCapabilityDelegate(Capabilities a_cap) const;																																							   // 04 - { return caps & a_cap ? this : 0; }
		virtual void				 AddObject1(hkpBroadPhaseHandle* a_object, const hkAabbUint32& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) = 0;																					   // 05
		virtual void				 AddObject2(hkpBroadPhaseHandle* a_object, const hkAabb& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) = 0;																							   // 06
		virtual void				 AddObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& a_addObjectList, const hkArrayBase<hkAabb>& a_addAabbList, hkArray<hkpBroadPhaseHandlePair>& a_newPairs) = 0;										   // 07
		virtual void				 RemoveObject(hkpBroadPhaseHandle* a_object, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) = 0;																												   // 08
		virtual void				 RemoveObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& a_removeObjectList, hkArray<hkpBroadPhaseHandlePair>& a_delPairsOut) = 0;																		   // 09
		virtual SInt32				 GetNumObjects() const = 0;																																													   // 0A
		virtual void				 UpdateAabbs(hkpBroadPhaseHandle* a_objects[], const hkAabb* a_aabbs, SInt32 a_numObjects, hkArray<hkpBroadPhaseHandlePair>& a_addedPairs, hkArray<hkpBroadPhaseHandlePair>& a_removedPairs) = 0;			   // 0B
		virtual void				 UpdateAabbsUInt32(hkpBroadPhaseHandle* a_objects[], const hkAabbUint32* a_aabbs, SInt32 a_numObjects, hkArray<hkpBroadPhaseHandlePair>& a_addedPairs, hkArray<hkpBroadPhaseHandlePair>& a_removedPairs) = 0;  // 0C
		virtual void				 Defragment() = 0;																																															   // 0D
		virtual void				 CheckDeterminism();																																														   // 0E - { return; }
		virtual void				 GetAllAabbs(hkArray<hkAabb>& a_allAabbs) const = 0;																																						   // 0F
		virtual void				 GetAabb(const hkpBroadPhaseHandle* a_object, hkAabb& a_aabb) const = 0;																																	   // 10
		virtual void				 GetExtents(hkVector4& a_worldMinOut, hkVector4& a_worldMaxOut) const = 0;																																	   // 11
		virtual void				 QuerySingleAabb(const hkAabb& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) const = 0;																												   // 12
		virtual void				 ReQuerySingleObject(const hkpBroadPhaseHandle* a_object, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut) const = 0;																							   // 13
		virtual void				 QuerySingleAabbWithCollector(const hkAabb& a_aabb, hkpBroadPhaseCastCollector* a_collector) const = 0;																										   // 14
		virtual bool				 AreAabbsOverlapping(const hkpBroadPhaseHandle* a_bhA, const hkpBroadPhaseHandle* a_bhB) const = 0;																											   // 15
		virtual void				 ShiftAllObjects(const hkVector4& a_shiftDistance, hkVector4& a_effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair>& a_newCollisionPairs) = 0;														   // 16
		virtual void				 ShiftBroadPhase(const hkVector4& a_shiftDistance, hkVector4& a_effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair>& a_newCollisionPairs) = 0;														   // 17
		virtual void				 GetOffsetLowHigh32bit(hkVector4& a_offsetLow32bit, hkVector4& a_offsetHigh32bit) const = 0;																												   // 18
		virtual void				 CastRay(const hkpCastRayInput& a_input, hkpBroadPhaseCastCollector* a_collectorBase, SInt32 a_collectorStriding) const = 0;																				   // 19
		virtual SInt32				 GetAabbCacheSize() const = 0;																																												   // 1A
		virtual void				 CalcAabbCache1(const hkAabb& a_aabb, hkpBroadPhaseAabbCache* a_aabbCacheOut) const = 0;																													   // 1B
		virtual void				 CalcAabbCache2(const hkArrayBase<hkpCollidable*>& a_overlappingCollidables, hkpBroadPhaseAabbCache* a_aabbCacheOut) const = 0;																				   // 1C
		virtual void				 CastAabb(const hkpCastAabbInput& a_input, hkpBroadPhaseCastCollector& a_collector) const = 0;																												   // 1D
		virtual void				 Set32BitOffsetAndScale(const hkVector4& a_offsetLow, const hkVector4& a_offsetHigh, const hkVector4& a_scale) = 0;																							   // 1E

		void AddObject(hkpBroadPhaseHandle* a_object, const hkAabbUint32& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut);
		void AddObject(hkpBroadPhaseHandle* a_object, const hkAabb& a_aabb, hkArray<hkpBroadPhaseHandlePair>& a_pairsOut);
		void CalcAabbCache(const hkAabb& a_aabb, hkpBroadPhaseAabbCache* a_aabbCacheOut) const;
		void CalcAabbCache(const hkArrayBase<hkpCollidable*>& a_overlappingCollidables, hkpBroadPhaseAabbCache* a_aabbCacheOut) const;


		// members
		const BroadPhaseType	   type;			  // 10
		const UInt16			   size;			  // 12
		const Capabilities		   caps;			  // 14
		mutable hkMultiThreadCheck multiThreadCheck;  // 18
		UInt32					   pad24;			  // 24
		hkCriticalSection*		   criticalSection;	  // 28
	};
	STATIC_ASSERT(sizeof(hkpBroadPhase) == 0x30);
}
