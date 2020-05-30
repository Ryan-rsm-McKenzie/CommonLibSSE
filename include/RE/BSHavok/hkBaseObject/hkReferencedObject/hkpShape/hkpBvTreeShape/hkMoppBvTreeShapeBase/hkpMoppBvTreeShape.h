#pragma once

#include "RE/hkMoppBvTreeShapeBase.h"
#include "RE/hkpSingleShapeContainer.h"


namespace RE
{
	class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpMoppBvTreeShape;


		virtual ~hkpMoppBvTreeShape();	// 00

		// override (hkMoppBvTreeShapeBase)
		virtual void					 CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;														 // 02
		virtual const hkpShapeContainer* GetContainer() const override;																															 // 04
		virtual SInt32					 CalcSizeForSpu(const CalcSizeForSpuInput& a_input, SInt32 a_spuBufferSizeLeft) const override;															 // 06
		virtual void					 GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;														 // 07
		virtual bool					 CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;														 // 08
		virtual void					 CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;				 // 09
		virtual hkVector4Comparison		 CastRayBundleImpl(const hkpShapeRayBundleCastInput& a_input, hkpShapeRayBundleCastOutput& a_output, const hkVector4Comparison& a_mask) const override;	 // 0A


		// members
		hkpSingleShapeContainer child;		// 50
		mutable SInt32			childSize;	// 60
		UInt32					pad64;		// 64
		UInt64					pad68;		// 68
	};
	STATIC_ASSERT(sizeof(hkpMoppBvTreeShape) == 0x70);
}
