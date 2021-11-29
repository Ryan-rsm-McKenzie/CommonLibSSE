#pragma once

#include "RE/H/hkpShape.h"
#include "RE/H/hkpShapeContainer.h"
#include "RE/H/hkpWeldingUtility.h"

namespace RE
{
	class hkpShapeCollection :
		public hkpShape,          // 00
		public hkpShapeContainer  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpShapeCollection;

		enum class CollectionType
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

		~hkpShapeCollection() override;  // 00

		// override (hkpShape)
		void                     CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;                                          // 02
		float                    GetMaximumProjection(const hkVector4& a_direction) const override;                                                                         // 03
		const hkpShapeContainer* GetContainer() const override;                                                                                                             // 04
		void                     GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;                                           // 07
		bool                     CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;                                          // 08
		void                     CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;  // 09

		// override (hkpShapeContainer)
		bool IsWeldingEnabled() const override;  // 06 - { return !disableWelding; }

		// add
		virtual void InitWeldingInfo(hkpWeldingUtility::WeldingType a_weldingType);  // 0B - { return; }
		virtual void SetWeldingInfo(hkpShapeKey a_key, std::int16_t a_weldingInfo);  // 0C - { return; }

		// members
		bool                                           disableWelding;  // 28
		stl::enumeration<CollectionType, std::uint8_t> collectionType;  // 29
		std::uint16_t                                  pad2A;           // 2A
		std::uint32_t                                  pad2C;           // 2C
	};
	static_assert(sizeof(hkpShapeCollection) == 0x30);
}
