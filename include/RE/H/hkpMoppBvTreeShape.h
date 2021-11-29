#pragma once

#include "RE/H/hkMoppBvTreeShapeBase.h"
#include "RE/H/hkpSingleShapeContainer.h"

namespace RE
{
	class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpMoppBvTreeShape;

		~hkpMoppBvTreeShape() override;  // 00

		// override (hkMoppBvTreeShapeBase)
		void                     CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;                                                       // 02
		const hkpShapeContainer* GetContainer() const override;                                                                                                                          // 04
		std::int32_t             CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const override;                                                    // 06
		void                     GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;                                                        // 07
		bool                     CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;                                                       // 08
		void                     CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;               // 09
		hkVector4Comparison      CastRayBundleImpl(const hkpShapeRayBundleCastInput& a_input, hkpShapeRayBundleCastOutput& a_output, const hkVector4Comparison& a_mask) const override;  // 0A

		// members
		hkpSingleShapeContainer child;      // 50
		mutable std::int32_t    childSize;  // 60
		std::uint32_t           pad64;      // 64
		std::uint64_t           pad68;      // 68
	};
	static_assert(sizeof(hkpMoppBvTreeShape) == 0x70);
}
