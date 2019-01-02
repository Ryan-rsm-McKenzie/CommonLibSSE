#pragma once

#include "RE/bhkCharacterController.h"  // bhkCharacterController
#include "RE/bhkCharacterProxy.h"  // bhkCharacterProxy
#include "RE/hkpCharacterProxyListener.h"  // hkpCharacterProxyListener


namespace RE
{
	class bhkCachingShapePhantom;
	class hkpCharacterProxy;


	struct UnkbhkCharProxyControllerParent
	{
		UInt64	unk0;	// 0
	};
	STATIC_ASSERT(sizeof(UnkbhkCharProxyControllerParent) == 0x8);


	class bhkCharProxyController :
		public hkpCharacterProxyListener,		// 000
		public UnkbhkCharProxyControllerParent,	// 008
		public bhkCharacterController			// 010
	{
	public:
		virtual ~bhkCharProxyController();	// 00


		// members
		bhkCharacterProxy		characterProxy;			// 340
		bhkCachingShapePhantom*	cachingShapePhantom;	// 590
		UInt64					unk598;					// 598
		UInt64					unk5A0;					// 5A0
		UInt64					unk5A8;					// 5A8
	};
	STATIC_ASSERT(sizeof(bhkCharProxyController) == 0x5B0);
}
