#pragma once

#include "RE/hkpWorld.h"


namespace RE
{
	class ahkpWorld : public hkpWorld
	{
	public:
		inline static constexpr auto RTTI = RTTI_ahkpWorld;


		virtual ~ahkpWorld();  // 00


		// members
		UInt64 unk430;	// 430
		UInt64 unk438;	// 438
	};
	STATIC_ASSERT(sizeof(ahkpWorld) == 0x440);
}
