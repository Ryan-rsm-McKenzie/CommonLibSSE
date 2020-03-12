#pragma once

#include "RE/hkBaseTypes.h"
#include "RE/hkVector4.h"


namespace RE
{
	class hkpCollisionDispatcher;
	class hkpCollisionFilter;
	class hkpConvexListFilter;


	struct hkpCollisionInput
	{
	public:
		struct Aabb32Info
		{
		public:
			// members
			hkVector4 bitOffsetLow;	  // 00
			hkVector4 bitOffsetHigh;  // 10
			hkVector4 bitScale;		  // 20
		};
		STATIC_ASSERT(sizeof(Aabb32Info) == 0x30);


		// members
		hkpCollisionDispatcher*	   dispatcher;				  // 00
		SInt32					   weldClosestPoints;		  // 08
		SInt32					   forceAcceptContactPoints;  // 0C
		float					   tolerance;				  // 10
		UInt32					   pad14;					  // 14
		const hkpCollisionFilter*  filter;					  // 18
		const hkpConvexListFilter* convexListFilter;		  // 20
		mutable SInt32			   createPredictiveAgents;	  // 28
		UInt32					   pad2C;					  // 2C
		Aabb32Info				   aabb32Info;				  // 30
	};
	STATIC_ASSERT(sizeof(hkpCollisionInput) == 0x60);
}
