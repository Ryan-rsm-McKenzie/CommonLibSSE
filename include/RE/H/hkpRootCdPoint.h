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
		std::uint32_t		 pad2C;			   // 2C
		const hkpCollidable* rootCollidableB;  // 30
		hkpShapeKey			 shapeKeyB;		   // 38
		std::uint32_t		 pad3C;			   // 3C
	};
	static_assert(sizeof(hkpRootCdPoint) == 0x40);
}
