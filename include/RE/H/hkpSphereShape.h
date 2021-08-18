#pragma once

#include "RE/H/hkpConvexShape.h"

namespace RE
{
	class hkpSphereShape : public hkpConvexShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpSphereShape;

		~hkpSphereShape() override;  // 00

		// override (hkpConvexShape)
		void             CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;     // 02
		std::int32_t     CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const override;  // 06 - { return 56; }
		void             GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;      // 07
		bool             CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;     // 08
		std::int32_t     GetNumCollisionSpheresImpl() override;                                                                // 0B - { return 8; }
		const hkpSphere* GetCollisionSpheresImpl(hkSphere* a_sphereBuffer) override;                                           // 0C
		void             GetCentreImpl(hkVector4& a_centreOut) override;                                                       // 0D
		void             Unk_0E(void) override;                                                                                // 0E
		void             Unk_0F(void) override;                                                                                // 0F
		void             Unk_11(void) override;                                                                                // 11
	};
	static_assert(sizeof(hkpSphereShape) == 0x28);
}
