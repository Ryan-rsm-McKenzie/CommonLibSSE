#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ahkpWorld

#include "RE/hkpWorld.h"  // hkpWorld


namespace RE
{
	class ahkpWorld : public hkpWorld
	{
	public:
		inline static const void* RTTI = RTTI_ahkpWorld;


		virtual ~ahkpWorld();	// 00


		// members
		UInt64	unk430;	// 430
		UInt64	unk438;	// 438
	};
	STATIC_ASSERT(sizeof(ahkpWorld) == 0x440);
}
