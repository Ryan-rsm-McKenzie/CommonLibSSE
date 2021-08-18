#pragma once

#include "RE/H/hkVector4.h"
#include "RE/H/hkpConvexShape.h"

namespace RE
{
	class hkpBoxShape : public hkpConvexShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpBoxShape;

		~hkpBoxShape() override;  // 00

		// overwrite
		void             CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;     // 02
		std::int32_t     CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const override;  // 06 - { return 64; }
		void             GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;      // 07
		bool             CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;     // 08
		std::int32_t     GetNumCollisionSpheresImpl() override;                                                                // 0B - { return 8; }
		const hkpSphere* GetCollisionSpheresImpl(hkSphere* a_sphereBuffer) override;                                           // 0C
		void             GetCentreImpl(hkVector4& a_centreOut) override;                                                       // 0D
		void             Unk_0E(void) override;                                                                                // 0E
		void             Unk_0F(void) override;                                                                                // 0F
		void             Unk_11(void) override;                                                                                // 11

		// members
		std::uint32_t pad28;        // 28
		std::uint32_t pad2C;        // 2C
		hkVector4     halfExtents;  // 30
	};
	static_assert(sizeof(hkpBoxShape) == 0x40);
}
