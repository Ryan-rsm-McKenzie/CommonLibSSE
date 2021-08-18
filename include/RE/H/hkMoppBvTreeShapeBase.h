#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkVector4.h"
#include "RE/H/hkpBvTreeShape.h"

namespace RE
{
	class hkpMoppCode;
	class hkTransform;

	class hkMoppBvTreeShapeBase : public hkpBvTreeShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkMoppBvTreeShapeBase;

		~hkMoppBvTreeShapeBase() override;  // 00

		// override (hkpBvTreeShape)
		void          CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override = 0;  // 02
		void          QueryAabb(const hkAabb& a_aabb, hkArray<hkpShapeKey>& a_hits) const override;                          // 0B
		std::uint32_t QueryAabbImpl(const hkAabb& a_aabb, hkpShapeKey* a_hits, std::int32_t a_maxNumKeys) const override;    // 0C

		// add
		virtual void QueryObb(const hkTransform& a_obbToMopp, const hkVector4& a_extent, float tolerance, hkArray<hkpShapeKey>& a_hits) const;  // 0E

		// members
		const hkpMoppCode*  code;          // 28
		const std::uint8_t* moppData;      // 30
		std::uint32_t       moppDataSize;  // 38
		std::uint32_t       pad3C;         // 3C
		hkVector4           codeInfoCopy;  // 40
	};
	static_assert(sizeof(hkMoppBvTreeShapeBase) == 0x50);
}
