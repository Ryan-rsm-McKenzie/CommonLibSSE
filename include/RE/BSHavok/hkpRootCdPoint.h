#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShape.h"
#include "RE/BSHavok/hkContactPoint.h"


namespace RE
{
	class hkpCollidable;


	struct hkpRootCdPoint
	{
		hkContactPoint		 contact;		   // 00
		const hkpCollidable* rootCollidableA;  // 20
		hkpShapeKey			 shapeKeyA;		   // 28
		UInt32				 pad2C;			   // 2C
		const hkpCollidable* rootCollidableB;  // 30
		hkpShapeKey			 shapeKeyB;		   // 38
		UInt32				 pad3C;			   // 3C
	};
	STATIC_ASSERT(sizeof(hkpRootCdPoint) == 0x40);
}
