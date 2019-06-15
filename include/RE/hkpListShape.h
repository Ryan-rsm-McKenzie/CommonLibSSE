#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpListShape

#include "RE/hkArray.h"  // hkArray
#include "RE/hkVector4.h"  // hkVector4
#include "RE/hkpShapeCollection.h"  // hkpShapeCollection


namespace RE
{
	class hkpListShape : public hkpShapeCollection
	{
	public:
		inline static const void* RTTI = RTTI_hkpListShape;


		enum
		{
			kMaxChildrenForSPUMidPhase = 252,
			kMaxDisabledChildren = 256
		};


		enum class ListShapeFlags : UInt32
		{
			kNone = 0,
			kDisableSPUCacheForListChildInfo = 1 << 0
		};


		struct ChildInfo
		{
			alignas(0x10) const hkpShape*	shape;					// 00
			UInt32							collisionFilterInfo;	// 08
			mutable SInt32					shapeSize;				// 0C
			mutable SInt32					numChildShapes;			// 10
			UInt32							pad14;					// 14
			UInt64							pad18;					// 18
		};
		STATIC_ASSERT(sizeof(ChildInfo) == 0x20);


		virtual ~hkpListShape();																																			// 00

		// override (hkpShapeCollection)
		virtual void			CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;											// 02
		virtual SInt32			CalcSizeForSpu(const CalcSizeForSpuInput& a_input, SInt32 a_spuBufferSizeLeft) const override;												// 06
		virtual void			GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;											// 07
		virtual bool			CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const override;											// 08
		virtual void			CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const override;	// 09

		// override (hkpShapeContainer)
		virtual SInt32			GetNumChildShapes() const override;																											// 01 - { return m_childInfo.getSize() - m_numDisabledChildren; }
		virtual hkpShapeKey		GetFirstKey() const override;																												// 02 - { return hkpListShape::getNextKey(hkpShapeKey(-1)); }
		virtual hkpShapeKey		GetNextKey(hkpShapeKey a_oldKey) const override;																							// 03
		virtual UInt32			GetCollisionFilterInfo(hkpShapeKey a_key) const override;																					// 04
		virtual const hkpShape*	GetChildShape(hkpShapeKey a_key, hkpShapeBuffer& a_buffer) const override;																	// 05


		// members
		hkArray<ChildInfo>	childInfo;				// 30
		UInt16				flags;					// 40
		UInt16				numDisabledChildren;	// 42
		UInt32				pad44;					// 44
		hkVector4			aabbHalfExtents;		// 50
		hkVector4			aabbCenter;				// 60
		UInt32				enabledChildren[8];		// 70
	};
	STATIC_ASSERT(sizeof(hkpListShape) == 0x90);
}
