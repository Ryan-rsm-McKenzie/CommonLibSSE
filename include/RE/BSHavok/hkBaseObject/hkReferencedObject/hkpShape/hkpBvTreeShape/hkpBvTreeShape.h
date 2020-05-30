#pragma once

#include "RE/hkArray.h"
#include "RE/hkpShape.h"


namespace RE
{
	class hkAabb;
	class hkpShapeContainer;


	class hkpBvTreeShape : public hkpShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpBvTreeShape;


		enum class BvTreeType : UInt8
		{
			kMOPP,
			kTriSampledHeightField,
			kUser
		};


		virtual ~hkpBvTreeShape();	// 00

		// override (hkpShape)
		virtual const hkpShapeContainer* GetContainer() const override = 0;	 // 04

		// add
		virtual void   QueryAabb(const hkAabb& a_aabb, hkArray<hkpShapeKey>& a_hits) const = 0;					 // 0B
		virtual UInt32 QueryAabbImpl(const hkAabb& a_aabb, hkpShapeKey* a_hits, SInt32 a_maxNumKeys) const = 0;	 // 0C


		// members
		BvTreeType bvTreeType;	// 20
		UInt8	   pad21;		// 21
		UInt16	   pad22;		// 22
		UInt32	   pad24;		// 24
	};
	STATIC_ASSERT(sizeof(hkpBvTreeShape) == 0x28);
}
