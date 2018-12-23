#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BSAnimationGraphChannel : public BSIntrusiveRefCounted
	{
	public:
		virtual ~BSAnimationGraphChannel();

		// add
		virtual	void	Unk_01(void);	// 01 - pure
		virtual	void	Unk_02(void);	// 02 - pure


		// members
		BSFixedString	unk10;	// 10
		UInt64			unk18;	// 18
	};
	STATIC_ASSERT(sizeof(BSAnimationGraphChannel) == 0x20);
}
