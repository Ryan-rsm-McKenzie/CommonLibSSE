#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSAnimationGraphChannel

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BSAnimationGraphChannel : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_BSAnimationGraphChannel;


		virtual ~BSAnimationGraphChannel();	// 00

		// add
		virtual	void	Unk_01(void) = 0;	// 01
		virtual	void	Unk_02(void) = 0;	// 02


		// members
		UInt32			unk0C;	// 0C
		BSFixedString	unk10;	// 10
		UInt64			unk18;	// 18
	};
	STATIC_ASSERT(sizeof(BSAnimationGraphChannel) == 0x20);
}
