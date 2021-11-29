#pragma once

#include "RE/H/hkpShapePhantom.h"

namespace RE
{
	class hkpCollisionAgent;

	class hkpCachingShapePhantom : public hkpShapePhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCachingShapePhantom;

		class OrderByUid
		{
		public:
		};
		static_assert(sizeof(OrderByUid) == 0x1);

		struct CollisionDetail
		{
			hkpCollisionAgent* agent;       // 00
			hkpCollidable*     collidable;  // 08
		};
		static_assert(sizeof(CollisionDetail) == 0x10);

		using hkpCollisionDetail = CollisionDetail;

		~hkpCachingShapePhantom() override;  // 00

		// override (hkpShapePhantom)
		void           CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;                                                                                    // 02
		hkpPhantomType GetType() const override;                                                                                                                                                            // 06 - { return hkpPhantomType::kCachingShape; }
		void           AddOverlappingCollidable(hkpCollidable* a_collidable) override;                                                                                                                      // 08
		bool           IsOverlappingCollidableAdded(const hkpCollidable* a_collidable) override;                                                                                                            // 09
		void           RemoveOverlappingCollidable(hkpCollidable* a_collidable) override;                                                                                                                   // 0A
		void           EnsureDeterministicOrder() override;                                                                                                                                                 // 0B
		hkpPhantom*    Clone() const override;                                                                                                                                                              // 0C
		void           UpdateShapeCollectionFilter() override;                                                                                                                                              // 0D
		void           DeallocateInternalArrays() override;                                                                                                                                                 // 0E
		void           SetPositionAndLinearCast(const hkVector4& a_position, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) override;      // 0F
		void           SetTransformAndLinearCast(const hkTransform& a_transform, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) override;  // 10
		void           GetClosestPoints(hkpCdPointCollector& a_collector, const hkpCollisionInput* a_input = 0) override;                                                                                   // 11
		void           GetPenetrations(hkpCdBodyPairCollector& a_collector, const hkpCollisionInput* a_input = 0) override;                                                                                 // 12

		// members
		hkArray<CollisionDetail> collisionDetails;  // 1A0
		bool                     orderDirty;        // 1B0
		OrderByUid               orderRelation;     // 1B1
		std::uint16_t            pad1B2;            // 1B2
		std::uint32_t            pad1B4;            // 1B4
		std::uint64_t            pad1B8;            // 1B8
	};
	static_assert(sizeof(hkpCachingShapePhantom) == 0x1C0);
}
