#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCachingShapePhantom

#include "RE/hkpShapePhantom.h"  // hkpShapePhantom


namespace RE
{
	class hkpCollisionAgent;


	class hkpCachingShapePhantom : public hkpShapePhantom
	{
	public:
		inline static const void* RTTI = RTTI_hkpCachingShapePhantom;


		class OrderByUid
		{
		public:
		};
		STATIC_ASSERT(sizeof(OrderByUid) == 0x1);


		struct CollisionDetail
		{
			hkpCollisionAgent*	agent;		// 00
			hkpCollidable*		collidable;	// 08
		};
		STATIC_ASSERT(sizeof(CollisionDetail) == 0x10);


		using hkpCollisionDetail = CollisionDetail;


		virtual ~hkpCachingShapePhantom();																																											// 00

		// override (hkpShapePhantom)
		virtual void			CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;																					// 02
		virtual hkpPhantomType	GetType() const override;																																							// 06 - { return hkpPhantomType::kCachingShape; }
		virtual void			AddOverlappingCollidable(hkpCollidable* a_collidable) override;																														// 08
		virtual bool			IsOverlappingCollidableAdded(const hkpCollidable* a_collidable) override;																											// 09
		virtual void			RemoveOverlappingCollidable(hkpCollidable* a_collidable) override;																													// 0A
		virtual void			EnsureDeterministicOrder() override;																																				// 0B
		virtual hkpPhantom*		Clone() const override;																																								// 0C
		virtual void			UpdateShapeCollectionFilter() override;																																				// 0D
		virtual void			DeallocateInternalArrays() override;																																				// 0E
		virtual void			SetPositionAndLinearCast(const hkVector4& a_position, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) override;		// 0F
		virtual void			SetTransformAndLinearCast(const hkTransform& a_transform, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) override;	// 10
		virtual void			GetClosestPoints(hkpCdPointCollector& a_collector, const hkpCollisionInput* a_input = 0) override;																					// 11
		virtual void			GetPenetrations(hkpCdBodyPairCollector& a_collector, const hkpCollisionInput* a_input = 0) override;																				// 12


		// members
		hkArray<CollisionDetail>	collisionDetails;	// 1A0
		bool						orderDirty;			// 1B0
		OrderByUid					orderRelation;		// 1B1
		UInt16						pad1B2;				// 1B2
		UInt32						pad1B4;				// 1B4
		UInt64						pad1B8;				// 1B8
	};
	STATIC_ASSERT(sizeof(hkpCachingShapePhantom) == 0x1C0);
}
