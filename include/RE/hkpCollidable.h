#pragma once

#include "RE/hkpCdBody.h"  // hkpCdBody
#include "RE/hkpShape.h"  // hkpShapeKey
#include "RE/hkpTypedBroadPhaseHandle.h"  // hkpTypedBroadPhaseHandle


namespace RE
{
	struct hkAabbUint32;


	class hkpCollidable : public hkpCdBody
	{
	public:
		enum class ForceCollideOntoPpuReasons : UInt32
		{
			kUserRequest = 1 << 0,
			kShapeRequest = 1 << 1,
			kModifierRequest = 1 << 2,
			kShapeUnchecked = 1 << 3
		};


		struct BoundingVolumeData
		{
			UInt32			min[3];						// 00
			UInt8			expansionMin[3];			// 0C
			UInt8			expansionShift;				// 0F
			UInt32			max[3];						// 10
			UInt8			expansionMax[3];			// 1C
			UInt8			pad1F;						// 1F
			UInt16			numChildShapeAabbs;			// 20
			UInt16			capacityChildShapeAabbs;	// 22
			UInt32			pad24;						// 24
			hkAabbUint32*	childShapeAabbs;			// 28
			hkpShapeKey*	childShapeKeys;				// 30
		};
		STATIC_ASSERT(sizeof(BoundingVolumeData) == 0x38);


		SInt8						ownerOffset;				// 20
		UInt8						forceCollideOntoPpu;		// 21
		UInt16						shapeSizeOnSpu;				// 22
		hkpTypedBroadPhaseHandle	broadPhaseHandle;			// 24
		BoundingVolumeData			boundingVolumeData;			// 30
		float						allowedPenetrationDepth;	// 68
		UInt32						pad6C;						// 6C
	};
	STATIC_ASSERT(sizeof(hkpCollidable) == 0x70);
}
