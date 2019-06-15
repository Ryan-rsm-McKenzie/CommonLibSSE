#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpShapeCollection

#include "RE/hkpShape.h"  // hkpShape
#include "RE/hkpShapeContainer.h"  // hkpShapeContainer
#include "RE/hkpWeldingUtility.h"  // hkpWeldingUtility::WeldingType


namespace RE
{
	class hkpShapeCollection :
		public hkpShape,			// 00
		public hkpShapeContainer	// 20
	{
	public:
		inline static const void* RTTI = RTTI_hkpShapeCollection;


		enum class CollectionType : UInt8
		{
			kList,
			kExtendedMesh,
			kTrisampledHeightfield,
			kUser,
			kSimpleMesh,
			kMeshShape,
			kCompressedMesh,

			kTotal
		};


		virtual ~hkpShapeCollection();																																					// 00

		// override (hkpShape)
		virtual void						CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;											// 02
		virtual float						GetMaximumProjection(const hkVector4& a_direction) const override;																			// 03
		virtual const hkpShapeContainer*	GetContainer() const override;																												// 04
		virtual void						GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;											// 07
		virtual bool						CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;											// 08
		virtual void						CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;	// 09

		// override (hkpShapeContainer)
		virtual bool						IsWeldingEnabled() const override;																											// 06 - { return !disableWelding; }

		// add
		virtual void						InitWeldingInfo(hkpWeldingUtility::WeldingType a_weldingType);																				// 0B - { return; }
		virtual void						SetWeldingInfo(hkpShapeKey a_key, SInt16 a_weldingInfo);																					// 0C - { return; }


		// members
		bool			disableWelding; // 28
		CollectionType	collectionType;	// 29
		UInt16			pad2A;			// 2A
		UInt32			pad2C;			// 2C
	};
	STATIC_ASSERT(sizeof(hkpShapeCollection) == 0x30);
}
