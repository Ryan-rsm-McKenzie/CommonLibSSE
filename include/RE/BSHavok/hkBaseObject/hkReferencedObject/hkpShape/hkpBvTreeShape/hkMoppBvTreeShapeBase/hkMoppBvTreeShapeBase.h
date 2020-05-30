#pragma once

#include "RE/hkArray.h"
#include "RE/hkVector4.h"
#include "RE/hkpBvTreeShape.h"


namespace RE
{
	class hkpMoppCode;
	class hkTransform;


	class hkMoppBvTreeShapeBase : public hkpBvTreeShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkMoppBvTreeShapeBase;


		virtual ~hkMoppBvTreeShapeBase();  // 00

		// override (hkpBvTreeShape)
		virtual void   CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override = 0;  // 02
		virtual void   QueryAabb(const hkAabb& a_aabb, hkArray<hkpShapeKey>& a_hits) const override;						  // 0B
		virtual UInt32 QueryAabbImpl(const hkAabb& a_aabb, hkpShapeKey* a_hits, SInt32 a_maxNumKeys) const override;		  // 0C

		// add
		virtual void QueryObb(const hkTransform& a_obbToMopp, const hkVector4& a_extent, float tolerance, hkArray<hkpShapeKey>& a_hits) const;	// 0E


		// members
		const hkpMoppCode* code;		  // 28
		const UInt8*	   moppData;	  // 30
		UInt32			   moppDataSize;  // 38
		UInt32			   pad3C;		  // 3C
		hkVector4		   codeInfoCopy;  // 40
	};
	STATIC_ASSERT(sizeof(hkMoppBvTreeShapeBase) == 0x50);
}
